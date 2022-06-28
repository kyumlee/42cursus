#include "./../../includes/Location.hpp"

Location::Location () : _mod(), _route() {}

Location::Location (const Location &lb) {
	_mod = lb._mod;
	_route = lb._route;
}

Location::~Location() {}

Location	&Location::operator= (const Location &lb) {
	_mod = lb._mod;
	_route = lb._route;

	return (*this);
}

std::string					Location::getBlock () { return (_block); }
std::string					Location::getMod () { return (_mod); }
std::string					Location::getRoute () { return (_route); }
std::vector<std::string>	Location::getMethods () { return (_methods); }
int							Location::getRedirect () { return (_redirect); }
bool						Location::getDListing () { return (_dListing); }
std::string					Location::getDefault () { return (_default); }

void						Location::setBlock (std::string block) {}
void						Location::setMod (std::string str) { _mod = str; }
void						Location::setRoute (std::string str) { _route = str; }
void						Location::setMethods (std::vector<std::string> methods) {}
void						Location::setRedirect (int redirection) {}
void						Location::setDListing (bool dListing) {}
void						Location::setDefault (std::string file) {}

int							Location::parseMethods () {}
int							Location::parseDListing () {}
int							Location::parseDefault () {}
void						Location::parse () {}
