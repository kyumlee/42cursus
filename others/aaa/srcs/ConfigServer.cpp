#include "Config.hpp"

void Server::initLocation(Location *loc)
{
    loc->_allowmethod.clear();
    loc->_autoindex = 0;
    loc->_bodysize = 0;
    loc->_index = "";
    loc->_root = "";
    loc->_cgipath = "";
    loc->_cgiext = "";
}

void Server::parsingServer(std::vector<std::string>::iterator it, std::vector<std::string>::iterator end)//begin(), end()
{
    std::string         tmp;
    Location            t_location;
    std::vector<int>    errorNum;
    
    if (*it == "server")
        it++;
    if (m_location.size() > 0)
        m_location.clear();
    while (it != end && *it != "server")
    {
        if (*it == "host")
        {
            it++;
            m_host = checkSemicolon(*it); //세미콜론 있으면 마지막 떼어주기
        }
        if (*it == "port")
        {
            it++;
            m_port = atoi((*it).c_str());
        }
        if (*it == "server_name")
        {
            it++;
            m_servername = checkSemicolon(*it);
        }
        if (*it == "location")
        {
            it++;
            if (*it == "=")
                it++;
            tmp = *it; // direct 저장
            initLocation(&t_location);
            it++;
            for (; *it != "location" && *it != "server" && *it != "error_page" && it != end ; it++) //location 개수만큼
            {
                if (*it == "root")
                {
                    it++;
                    t_location._root = checkSemicolon(*it);
                }
                else if (*it == "index")
                {
                    it++;
                    t_location._index = checkSemicolon(*it);                
                }
                else if (*it == "allowed_method")
                {
                    it++;
                    if (t_location._allowmethod.size() != 0)
                        t_location._allowmethod.clear();
                    while (*it == checkSemicolon(*it))
                    {
                        t_location._allowmethod.push_back(*it);
                        it++;
                    }
                    t_location._allowmethod.push_back(checkSemicolon(*it));
                }
                else if (*it == "limit_body_size")
                {
                    it++;
                    std::string tmp2 = *it;
                    int size = atoi(tmp2.c_str());
                    t_location._bodysize = size;
                }
                else if (*it == "autoindex")
                {
                    it++;
                    if (*it == "on;")
                        t_location._autoindex = 1;
                    else
                        t_location._autoindex = 0;
                }
                else if (*it == "cgi_path")
                {
                    it++;
                    t_location._cgipath = checkSemicolon(*it);
                }
                else if (*it == "cgi_ext")
                {
                    it++;
                    t_location._cgiext = checkSemicolon(*it);                
                }
            }
            t_location._prefix = tmp;
            m_location.insert(make_pair(tmp, t_location));
            it--;
        }
        if (*it == "error_page")
        {
            it++;
            if (errorNum.size() > 0)
                errorNum.clear();
            while (*it == checkSemicolon(*it))
            {
                errorNum.push_back(atoi((*it).c_str()));
                it++;
            }
            std::string error_page = checkSemicolon(*it);
            for (unsigned long i = 0; i < errorNum.size(); i++)
            {
                m_error.insert(make_pair(errorNum[i], error_page));
            }
        }
        it++;
    }
    if (m_location.find("/") == m_location.end())
    {
        std::cout << "Need / location" << std::endl;
        return ;
    }
}

const std::map<std::string, Location>& Server::getLocations() const {
    return m_location;
}

void Server::printServer()//출력용
{
    std::map<std::string, Location>::iterator it = m_location.begin();

    std::cout << "host : " << m_host << std::endl;
    std::cout << "port : " << m_port << std::endl;
    std::cout << "servername : " << m_servername << std::endl;
    std::cout << std::endl;
    std::cout <<  "location size : " << m_location.size() << std::endl;
    std::cout << std::endl;
    for (; it != m_location.end(); it++)
    {
        std::cout << "--------------------------" << std::endl;
        std::cout << "direct name : " << it->first << std::endl;
        std::cout << "root : " << it->second._root << std::endl;
        std::cout << "index : " << it->second._index << std::endl;
        std::cout << "cgi_path : " << it->second._cgipath << std::endl;
        std::cout << "cgi_ext : " << it->second._cgiext << std::endl;
        std::cout << "bodysize : " << it->second._bodysize << std::endl;
        std::cout << "autoindex : " << it->second._autoindex << std::endl;
        std::cout << "allowmethod : ";
        for (unsigned long j = 0; j < it->second._allowmethod.size(); j++)
        {
            std::cout << it->second._allowmethod[j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::map<int, std::string>::iterator it2 = m_error.begin();
    std::cout << "error_page size : " << m_error.size() << std::endl; 
    for (unsigned long j = 0; j < m_error.size(); j++)
    {
        std::cout << "--------------------------" << std::endl;
        std::cout << "error_num : " << it2->first << std::endl;
        std::cout << "error_page : " << it2->second << std::endl;
        it2++;
    }
    std::cout << "--------end-----------" << std::endl;
}
