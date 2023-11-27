#include "Span.hpp"

/* Orthodox Canonical Form */

Span::Span(void)
{
	// std::cout << "[Span] Default constructor called" << RESET << std::endl;
}

Span::Span(unsigned int size) : _size(size)
{
	// std::cout << "[Span] Size constructor called" << RESET << std::endl;
}

Span::Span(const Span &copy)
{
	// std::cout << "[Span] Copy constructor called" << RESET << std::endl;
	*this = copy;
}

Span &Span::operator=(const Span &op)
{
	if (this != &op)
	{
		this._size = op._size;
		this._container.assign(op._container.begin(), op._container.end());
	}
	// std::cout << "[Span] Copy assignment operator called" << RESET << std::endl;
	return (*this);
}

Span::~Span(void)
{
	// std::cout << "[Span] Destructor called" << RESET << std::endl;
}

/* Method functions */

void	Span::addNumber(int n);
{
	if (_container.size() < _size)
		_container.push_back(n);
	else
		throw std::logic_error("the container is already full");
}

void	Span::fillContainerRandom(void);
{
	currSize = _container.size();
	if (currSize == _size || _size == 0)
		return ;

	std::vector<int> tmp(_size - currSize);
	std::vector<int>::iterator itr = tmp.begin();
	for (; itr != tmp.end(); itr++)
		*itr = rand() % 30000;
	_container.insert(tmp.begin(), itr);
}

void	Span::checkException(void);
{
	if (_container.size() == 0 || _container.size() == 1)
		throw std::logic_error("size too small to calculate spans");
}

int		Span::shortestSpan(void);
{

}

int		Span::longestSpan(void);
{
	// max - min
}

void	Span::printContainer(void);
{
	std::cout << "List of integers: " << std::endl;
	for (int n : _container)
		std::cout << n << " ";
	std::cout << std::endl;
}
