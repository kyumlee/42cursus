#include "./span.hpp"
#include <typeinfo>
Span::Span(void) {
	throw (EmptySpanException());
}

Span::Span(unsigned int num) {
	_size = num;
}

Span::Span(const Span &sp) : _size(sp.getSize()) {
	for (size_t i = 0; i < sp._vec.size(); i++)
		_vec.push_back(sp._vec.at(i));
}

Span				&Span::operator=(const Span &sp) {
	_size	= sp.getSize();

	while (!_vec.empty())
		_vec.pop_back();

	for (size_t i = 0; i < sp._vec.size(); i++)
		_vec.push_back(sp._vec.at(i));

	return (*this);
}

Span::~Span(void) {}

void				Span::addNumber(int num) {
	if (_vec.size() == _size)
		throw (ObjectIsFullException());

	_vec.push_back(num);
}

long				toLong(int num) {
	return (static_cast<long>(num));
}

unsigned int		Span::shortestSpan(void) const {
	if (_vec.size() <= 1)
		throw (NotEnoughNumbersException());

	std::vector<int>	temp = _vec;
	std::sort(temp.begin(), temp.end());
	int					size = temp.size();

	unsigned int	min = std::abs(toLong(temp[size - 1]) - toLong(temp[size - 2]));
	for (size_t i = temp.size() - 2; i > 0; i--) {
		unsigned int	minTemp = std::abs(toLong(temp[i]) - toLong(temp[i - 1]));
		if (minTemp < min)
			min = minTemp;
	}

	return (min);
}

unsigned int		Span::longestSpan(void) const {
	if (_vec.size() <= 1)
		throw (NotEnoughNumbersException());

	std::vector<int>	temp = _vec;
	std::sort(temp.begin(), temp.end());

	unsigned int	max = std::abs(toLong(temp[temp.size() - 1]) - toLong(temp[0]));
	
	return (max);
}

std::vector<int>	Span::getVec(void) const { return (_vec); }

size_t				Span::getSize(void) const { return (_size); }

int					Span::getElem(int i) const { return (_vec.at(i)); }

void				Span::deleteNumber(void) {
	if (_vec.empty())
		throw (NotEnoughNumbersException());

	_vec.pop_back();
}

void				Span::addRandomNumbers(void) {
	srand(time(NULL));

	for (size_t i = 0; i < _size; i++)
		addNumber(rand());
}

const char			*Span::EmptySpanException::what(void) const throw() {
	return ("span is empty");
}

const char			*Span::ObjectIsFullException::what(void) const throw() {
	return ("object is full");
}

const char			*Span::NotEnoughNumbersException::what(void) const throw() {
	return ("not enough numbers");
}

const char			*Span::IntOverflowException::what(void) const throw() {
	return ("int overflow");
}

std::ostream		&operator<<(std::ostream &os, const Span &sp) {
	os << "  Span: " << std::endl;
	for (size_t i = 0; i < sp.getVec().size(); i++)
		os << "    [" << i << "] = " << sp.getElem(i) << std::endl;

	return (os);
}
