#include "PmergeMe.hpp"

/* Method functions */

void PmergeMe::printResult(void)
{
	cout << "Before:\t";
	for (size_t i = 0; i < _size; ++i)
		cout << *(_input + i) << " ";
	cout << endl;
	cout << "After:\t";
	Utils::printContainer(_mainVec);
	cout << "Time to process a range of " << _size << " elements with std::vector : " << _elapsedVec << " µs" << endl;
	cout << "Time to process a range of " << _size << " elements with std::list : " << _elapsedLst << " µs" << endl;
}

void	PmergeMe::pmm(void)
{
	sortIntVec();
	sortIntLst();
	printResult();
}

/* Orthodox Canonical Form */

PmergeMe::PmergeMe(void)
{
	// std::cout << "[PmergeMe] Default constructor called" << RESET << std::endl;
}

PmergeMe::PmergeMe(char **input, size_t size) : _input(input), _size(size)
{
	// std::cout << "[PmergeMe] Input constructor called" << RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
: _input(copy._input), _size(copy._size)
{
	// std::cout << "[PmergeMe] Copy constructor called" << RESET << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &op)
{
	_input = op._input;
	_size = op._size;
	// std::cout << "[PmergeMe] Copy assignment operator called" << RESET << std::endl;
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	// std::cout << "[PmergeMe] Destructor called" << RESET << std::endl;
}
