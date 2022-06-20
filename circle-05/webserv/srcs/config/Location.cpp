#include "./../../includes/Location.hpp"

Location::Location () : _mod(), _match() {}

Location::Location (std::string mod, std::string match) : _mod(mod), _match(match) {}

Location::Location (const Location &lb) {
	_mod = lb._mod;
	_match = lb._match;
}

Location::~Location() {}

Location	&Location::operator= (const Location &lb) {
	_mod = lb._mod;
	_match = lb._match;

	return (*this);
}

std::string	Location::getMod () { return (_mod); }

std::string	Location::getMatch () { return (_match); }

void		Location::setMod (std::string str) { _mod = str; }

void		Location::setMatch (std::string str) { _match = str; }
