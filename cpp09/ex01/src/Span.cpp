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

Span::Span(const Span &copy) : _container(std::vector<int>(copy._container)), _size(copy._size)
{
	// std::cout << "[Span] Copy constructor called" << RESET << std::endl;
}

Span &Span::operator=(const Span &op)
{
	if (this != &op)
	{
		this->_size = op._size;
		this->_container = std::vector<int>(op._container);
	}
	// std::cout << "[Span] Copy assignment operator called" << RESET << std::endl;
	return (*this);
}

Span::~Span(void)
{
	// std::cout << "[Span] Destructor called" << RESET << std::endl;
}

/* Method functions */

void	Span::addNumber(int n)
{
	if (_container.size() < _size)
		_container.push_back(n);
	else
		throw std::logic_error("the container is already full");
}

void	Span::fillContainerRandom(void)
{
	unsigned int currSize = _container.size();
	if (currSize == _size || _size == 0)
		return ;

	std::vector<int> tmp(_size - currSize);
	std::vector<int>::iterator itr = tmp.begin();
	for (; itr != tmp.end(); itr++)
		*itr = rand() % 30000 - 15000;
	_container.insert(_container.end(), tmp.begin(), itr);
}

void	Span::checkException(void)
{
	if (_container.size() == 0 || _container.size() == 1)
		throw std::logic_error("the container size too small to calculate spans");
}

unsigned int	Span::shortestSpan(void)
{
	checkException();
	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	int prev;

	std::sort(_container.begin(), _container.end());
	std::vector<int>::iterator itr = _container.begin();
	for (; itr != _container.end()--;)
	{
		prev = *itr;
		unsigned int tmp = static_cast<unsigned int>(*(++itr) - prev);
		shortest = std::min(shortest, tmp);
	}
	return (shortest);
}

unsigned int	Span::longestSpan(void)
{
	checkException();

	int	minElement = *std::min_element(_container.begin(), _container.end());
    int	maxElement = *std::max_element(_container.begin(), _container.end());
	return (maxElement - minElement);
}

void	Span::printContainer(void)
{
	std::cout << "List of integers: " << std::endl;
	std::vector<int>::iterator itr = _container.begin();
	for (; itr != _container.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}
