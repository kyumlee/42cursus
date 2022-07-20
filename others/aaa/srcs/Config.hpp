#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <map>

#include "utils/util.hpp"

struct Location
{
    std::string _prefix;
    std::string _root;
    std::string _index;
    std::string _cgipath;
    std::string _cgiext;
    std::vector<std::string> _allowmethod;
    int _bodysize;
    int _autoindex; //off,init = 0, on = 1
};

class Server //ConfigSever.cpp
{
private:
    int         m_fd;// Server.cpp
    std::string m_host;
    int         m_port;
    std::string m_servername;
    std::map<std::string, Location> m_location; //string에 location directory
    std::map<int, std::string> m_error;

public:
    typedef std::map<std::string, Location> locations_map_type;

    Server():m_fd(0), m_port(0){};
    Server(const Server &other){*this = other;};
    ~Server(){};
    Server &operator=(const Server &other)
    {
        this->m_host = other.m_host;
        this->m_port = other.m_port;
        this->m_servername = other.m_servername;
        this->m_location = other.m_location;
        this->m_error = other.m_error;
        return (*this);
    };
    
    std::string getHost()
    {
        return m_host;
    }
    int getPort()
    {
        return m_port;
    }
    std::string getServername()
    {
        return m_servername;
    }
    std::map<int, std::string> getError()
    {
        return m_error;
    }

    void initLocation(Location *loc);
    void parsingServer(std::vector<std::string>::iterator it, std::vector<std::string>::iterator end);
    const std::map<std::string, Location>& getLocations() const;
    void printServer();// 임시 출력용

    int run(int kq);
    int accept_new_connection(int kq);
    int getFd() const;
};

class Webserv // ConfigWebserv.cpp
{
    private:
        Webserv(const Webserv &other);
        Webserv &operator=(const Webserv &other);

        std::vector<Server> m_server_list;
        int m_server_cnt;

        int getServerIdx(int fd);
    public:
        Webserv():m_server_cnt(0){};
        ~Webserv(){};

        void parsingWebserv(std::string path);
        bool checkWrongserv();

        int run();
        int monitor_events(int kq);

        std::vector<Server> getServerList();
};

#endif
