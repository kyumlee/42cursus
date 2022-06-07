#ifndef __KAREN_HPP__
# define __KAREN_HPP__

# include <iostream>

class	Karen {

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:
	Karen(void);
	~Karen(void);
	void	complain(std::string level);

};

void	printUsage(void);

#endif
