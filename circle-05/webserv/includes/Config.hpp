#ifndef __CONFIG_HPP__
# define __CONFIG_HPP__

#include "./Server.hpp"

class	Config {
	private:
		std::vector<Server>	_server;

	public:
		Config ();
		Config (Config &conf);
		~Config ();
		Config	&operator= (Config &conf);

		Server	getServerByAddr (std::string address);
		Server	getServerByName (std::string name);

		void	addServer (Server serv);
};

#endif
