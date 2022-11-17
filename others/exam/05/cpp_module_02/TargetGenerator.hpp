#ifndef __TARGET_GENERATOR_HPP__
# define __TARGET_GENERATOR_HPP__

# include <iostream>
# include <map>

# include "./ATarget.hpp"

class	TargetGenerator {
	private:
		std::map<std::string, ATarget*>	_gen;

	public:
		void		learnTargetType(ATarget* at);
		void		forgetTargetType(std::string const& tg);
		ATarget*	createTarget(std::string const& tg);
};

#endif
