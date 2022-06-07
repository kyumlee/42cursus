#ifndef __MATERIA_SOURCE_HPP__
# define __MATERIA_SOURCE_HPP__

# include "./IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource {

	private:
		AMateria		*_memory[4];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &ms);
		~MateriaSource(void);
		MateriaSource			&operator=(const MateriaSource &ms);
		virtual void			learnMateria(AMateria *);
		virtual AMateria		*createMateria(std::string const &type);
		AMateria				*getMemory(int idx) const;

};

#endif
