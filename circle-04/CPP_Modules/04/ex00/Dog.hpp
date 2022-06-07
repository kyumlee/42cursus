#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "./Animal.hpp"

# define DOG	"[     DOG      ] "

class	Dog : public Animal {

	public:
		Dog(void);
		Dog(const Dog &dog);
		virtual			~Dog(void);

		Dog				&operator=(const Dog &dog);
		virtual void	makeSound(void) const;

};

#endif
