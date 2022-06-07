#ifndef __DATA_HPP__
# define __DATA_HPP__

# include <iostream>

typedef struct	_data {
	char		c;
	int			i;
	float		f;
	double		d;
}				Data;

uintptr_t	serialize(Data *ptr);

Data		*deserialize(uintptr_t raw);

#endif
