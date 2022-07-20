#ifndef _REQUEST_HPP_
# define _REQUEST_HPP_

# include <iostream>
# include <map>
# include <sys/time.h>
# include "utils/Uri.hpp"

# define MAX_URI 8192

enum rq_state {
	READING_STARTLINE = 0,
	READING_HEADERS,
	READING_BODY,
	RECV_END
};

class Request {
	private:
		std::string m_raw;
		std::string m_prev;
		std::string m_method;
		Uri m_uri;
		std::string m_version;
		std::map<std::string, std::string> m_headers;
		std::string m_body;
		bool m_body_chunked;
		long m_body_length;
		bool m_chunk_size_ready;
		unsigned long m_chunk_size;
		long m_current_body_size;
		std::string m_chunk_data;
		int m_current_state;
		bool m_is_done;
		bool m_is_valid;
#if DEBUG
		struct timeval _start_time;
#endif
		int _part_cnt;

		int parse_startline(std::string& buf);
		int parse_headers(std::string& buf);
		int process_startline(std::string& buf);
		int process_headers(std::string& buf);
		int process_body(std::string& buf);
		int process_body_chunked(std::string& buf);
		int process_body_length(std::string& buf);
		
	public:
		Request();
		~Request();
		int append_msg(char* buf);
		bool isDone() const;
		bool isValid() const;
		int getState() const;  // isValid()가 false면 getState()는 보내야할 응답코드를 리턴
		const std::string& getMethod() const;
		const Uri& getUri() const;
		const std::string& getVersion() const;
		std::string& getHeaderValue(const std::string& key);
		const std::string& getBody() const;
		const std::string& getRaw() const;
		
		void reset();
		const std::map<std::string,std::string>& getAllHeaders() const;
};

#endif
