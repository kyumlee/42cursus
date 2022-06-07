#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

# include <iostream>

template <typename T>
class	Array {

	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &arr);
		~Array(void);

		Array	&operator=(const Array &arr);
		T		&operator[](const int i);
		
		class	OutOfRangeException : public std::exception {
			const char	*what(void) const throw();
		};

		int		size(void) const;

};
		
template <typename T>
Array<T>::Array(void) {
	_size	= 0;
	_array	= new T[_size];
};

template <typename T>
Array<T>::Array(unsigned int n) {
	_size	= n;
	_array	= new T[_size];
};

template <typename T>
Array<T>::Array(const Array &arr) {
	_size	= arr._size;
	_array	= new T[_size];

	for (int i = 0; i < static_cast<int>(_size); i++)
		_array[i]	= arr._array[i];
};

template <typename T>
Array<T>::~Array(void) {
	delete [] _array;
}


template <typename T>
Array<T>	&Array<T>::operator=(const Array &arr) {
	if (_size)
		delete [] _array;

	_size	= arr._size;
	_array	= new T[_size];

	for (int i = 0; i < static_cast<int>(_size); i++)
		_array[i]	= arr._array[i];

	return (*this);
};

template <typename T>
T			&Array<T>::operator[](const int i) {
	try {
		if (i < 0 || i >= static_cast<const int>(_size)) throw OutOfRangeException();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (_array[i]);
};

template <typename T>
const char	*Array<T>::OutOfRangeException::what(void) const throw() {
	return ("index out of range");
};

template <typename T>
int		Array<T>::size(void) const { return (_size); };

#endif
