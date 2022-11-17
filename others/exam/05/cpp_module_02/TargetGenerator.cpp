#include "./TargetGenerator.hpp"

void		TargetGenerator::learnTargetType(ATarget* at) {
	if (at)
		_gen.insert(std::pair<std::string, ATarget*>(at->getType(), at));
}
void		TargetGenerator::forgetTargetType(std::string const& tg) {
	std::map<std::string, ATarget*>::iterator it = _gen.find(tg);
	if (it != _gen.end())
		delete (it->second);
	_gen.erase(tg);
}
ATarget*	TargetGenerator::createTarget(std::string const& tg) {
	std::map<std::string, ATarget*>::iterator it = _gen.find(tg);
	if (it != _gen.end())
		return (_gen[tg]);
	return (0);
}
