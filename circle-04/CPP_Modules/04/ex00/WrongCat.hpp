#ifndef __WRONG_CAT_HPP__
# define __WRONG_CAT_HPP__

# include "./WrongAnimal.hpp"

# define W_CAT	"[  WRONG CAT   ] "

class	WrongCat : public WrongAnimal {

	public:
		WrongCat(void);
		WrongCat(const WrongCat &cat);
		~WrongCat(void);

		WrongCat		&operator=(const WrongCat &cat);
		void			makeSound(void) const;

};

#endif
