#include "PMergeMe.hpp"

/* Method functions */



/* Orthodox Canonical Form */

PMergeMe::PMergeMe(void)
{
	// std::cout << "[PMergeMe] Default constructor called" << RESET << std::endl;
}

PMergeMe::PMergeMe(IntVec input) : _input(input)
{
	// std::cout << "[PMergeMe] Default constructor called" << RESET << std::endl;
}


PMergeMe::PMergeMe(const PMergeMe &copy)
: _input(copy._input), _resultVec(IntVec(copy._resultVec)), _resultLst(IntLst(copy._resultLst))
{
	// std::cout << "[PMergeMe] Copy constructor called" << RESET << std::endl;
}

PMergeMe &PMergeMe::operator=(const PMergeMe &op)
{
	_input = op._input;
	_resultVec = IntVec(op._resultVec);
	_resultLst = IntLst(op._resultLst);
	// std::cout << "[PMergeMe] Copy assignment operator called" << RESET << std::endl;
	return (*this);
}

PMergeMe::~PMergeMe(void)
{
	// std::cout << "[PMergeMe] Destructor called" << RESET << std::endl;
}
