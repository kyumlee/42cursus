#include <iostream>
#include <algorithm>
#include "Request.hpp"
#include "common.hpp"
#include "utils/util.hpp"

Request::Request() {
	reset();
	_part_cnt = 0;
}

Request::~Request() {};

int Request::append_msg(char* str) {
#if DEBUG
	if (_part_cnt == 0) {
		std::cout << "< receiving request msg..." << std::endl;
		gettimeofday(&_start_time, NULL);
	}
	_part_cnt++;
#endif
	int ret = 0;
	std::string buf(str);

	while (!buf.empty()) {
		if (m_current_state == READING_STARTLINE)
			ret = process_startline(buf);
		else if (m_current_state == READING_HEADERS)
			ret = process_headers(buf);
		else if (m_current_state == READING_BODY)
			ret = process_body(buf);
		else
			break;
		if (ret != 0) {
			m_current_state = ret;
			m_is_done = true;
			m_is_valid = false;
			return ret;
		}
	}

#if DEBUG
	if (m_is_done) {
		struct timeval current;
		gettimeofday(&current, NULL);
		unsigned int elapsed = millisec(_start_time, current);
		std::cout << "   [ part: " << _part_cnt << ",  elapsed: " << elapsed << "ms ]" << std::endl;
	}
#endif

	return ret;
}

// line을 공백단위로 잘라서 method, uri, version에 저장
int Request::parse_startline(std::string& line) {
	m_raw.append(line).append("\r\n");
	size_t start_pos = 0, next;

	next = line.find(' ');
	if (next == std::string::npos)
		return BAD_REQUEST;
	m_method = line.substr(0, next);
	start_pos = next;
	while (line[start_pos] == ' ')
		start_pos++;
	next = line.find(' ', start_pos);
	if (next == std::string::npos)
		return BAD_REQUEST;
	m_uri = Uri(line.substr(start_pos, next - start_pos));
	if (m_uri.getLength() > MAX_URI)
		return URI_TOO_LONG;
	if (m_uri.getHost() != "" && m_uri.getScheme() != "http")
		return BAD_REQUEST;
	if (m_uri.getPath()[0] != '/')
		return BAD_REQUEST;
	start_pos = next;
	while (line[start_pos] == ' ')
		start_pos++;
	m_version = line.substr(start_pos);
	if (m_version.substr(0,5) != "HTTP/")
		return BAD_REQUEST;
	if ( ! (m_version.substr(5) == "1.0" || m_version.substr(5) == "1.1") )
		return HTTP_VERSION_NOT_SUPPORTED;
	return 0;
}

// line을 colon단위로 잘라서 key:value로 저장
int Request::parse_headers(std::string& line) {
	m_raw.append(line).append("\r\n");
	size_t pos = line.find(':');
	std::string key = line.substr(0, pos);
	key = trimSpace(key);
	std::transform(key.begin(), key.end(), key.begin(), ::tolower);
	std::string value = line.substr(pos+1);
	value = trimSpace(value);
	std::transform(value.begin(), value.end(), value.begin(), ::tolower);
	if (key == "host" && m_headers.count("host"))
		return BAD_REQUEST;
	if (key == "transfer-encoding" && value != "chunked")
		return NOT_IMPLEMENTED;
	m_headers[key] = value;
	return 0;
}

int Request::process_startline(std::string& buf) {
	m_prev.append(buf);

	size_t n = m_prev.find("\r\n");
	if (n == std::string::npos) {
		buf = "";
	}
	else {
		std::string line = m_prev.substr(0, n);
		buf = m_prev.substr(n + 2);
		m_prev = "";
		int ret = parse_startline(line);
		if (ret != 0)
			return ret;
		else
			m_current_state = READING_HEADERS;
	}
	return 0;
}

int Request::process_headers(std::string& buf) {
	m_prev.append(buf);
	size_t n = m_prev.find("\r\n");
	if (n == std::string::npos) {
		buf = "";
	}
	else if (n == 0) {	// empty line. header수신 완료
		if (m_headers.count("host") == 0)
			return BAD_REQUEST;

		m_is_done = true;
		m_is_valid = true;
		m_current_state = RECV_END;

		if ( m_headers.count("content-length") || m_headers.count("transfer-encoding") ) {
			buf = m_prev.substr(n + 2);
			m_prev = "";
			if (m_headers.count("content-length")) {
				m_body_length = strtol(m_headers["content-length"].c_str(), NULL, 0);
				if (m_body_length < 0)
					return BAD_REQUEST;
			}
			if (m_headers.count("transfer-encoding"))
				m_body_chunked = true;
			m_current_state = READING_BODY;
			m_is_done = false;
		}
	}
	else {
		std::string line = m_prev.substr(0, n);
		buf = m_prev.substr(n + 2);
		m_prev = "";
		int ret = parse_headers(line);
		if (ret != 0)
			return ret;
	}
	return 0;
}

int Request::process_body(std::string& buf) {
	m_prev.append(buf);
	if (m_body_chunked)
		return process_body_chunked(buf);
	else
		return process_body_length(buf);

}

int Request::process_body_chunked(std::string& buf) {
	if (!m_chunk_size_ready) {
		size_t n = m_prev.find("\r\n");
		if (n == std::string::npos) {
			buf = "";
		}
		else {
			buf = m_prev.substr(n + 2);
			// chunk size를 16진수->10진수로 변환
			m_chunk_size = strtol(m_prev.c_str(), NULL, 16);
			m_chunk_size_ready = true;
			m_current_body_size += m_chunk_size;
			m_prev = "";
		}
	}
	else {
		// m_chunk_data가 m_chunk_size + \r\n을 가지고 있을 때까지 append
		if (m_chunk_data.size() + m_prev.size() < m_chunk_size + 2) {
			m_chunk_data.append(m_prev);
			m_prev = "";
			buf = "";
		}
		else {
			size_t n_pos = m_chunk_size + 2 - m_chunk_data.size();
			m_chunk_data.append(m_prev.substr(0, n_pos));
			buf = m_prev.substr(n_pos);
			m_prev = "";
			// m_chunk_data는 \r\n으로 끝나야 한다
			if (m_chunk_data.substr(m_chunk_data.size() - 2) != "\r\n")
				return BAD_REQUEST;
			if (m_chunk_size == 0) {
				m_is_done = true;
				m_is_valid = true;
				m_current_state = RECV_END;
				return 0;
			}
			m_body.append(m_chunk_data.substr(0, m_chunk_data.size() - 2));
			m_chunk_data = "";
			m_chunk_size_ready = false;
		}
	}
	return 0;
}

int Request::process_body_length(std::string& buf) {
	if (m_prev.size() >= static_cast<size_t>(m_body_length)) {
		m_body = m_prev.substr(0, m_body_length);
		m_is_done = true;
		m_is_valid = true;
		m_current_state = RECV_END;
	}
	else
		buf = "";
	return 0;
}


bool Request::isDone() const {
	return m_is_done;
}

bool Request::isValid() const {
	return m_is_valid;
}

int Request::getState() const {
	return m_current_state;
}
const std::string& Request::getMethod() const {
	return m_method;
}
const Uri& Request::getUri() const {
	return m_uri;
}
const std::string& Request::getVersion() const {
	return m_version;
}

std::string& Request::getHeaderValue(const std::string& key) {
	return m_headers[key];
}

const std::string& Request::getBody() const {
	return m_body;
}

const std::string& Request::getRaw() const {
	return m_raw;
}

void Request::reset() {
	m_raw = "";
	m_prev = "";
	m_method = "";
	m_uri.reset();
	m_version = "";
	m_headers.clear();
	m_body = "";
	m_body_chunked = false;
	m_body_length = 0;
	m_chunk_size_ready = false;
	m_chunk_size = 0;
	m_current_body_size = 0;
	m_chunk_data = "";
	m_current_state = READING_STARTLINE;
	m_is_done = false;
	m_is_valid = false;
}

const std::map<std::string,std::string>& Request::getAllHeaders() const {
	return m_headers;
}
