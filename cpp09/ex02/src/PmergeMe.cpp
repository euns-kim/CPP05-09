#include "PMergeMe.hpp"

/* Method functions */

void PMergeMe::printResult(void)
{
	cout << "Before:\t";
	Utils::printContainer(_input);
	cout << "After:\t";
	Utils::printContainer(_tmpVec);
	cout << "Time to process a range of " << _tmpVec.size() << " elements with std::vector : " << _elapsedVec << " milliseconds" << endl;
	cout << "Time to process a range of " << _tmpLst.size() << " elements with std::list : " << _elapsedLst << " milliseconds" << endl;
}

void	PMergeMe::initContainers(void)
{
	Utils::fillContainerRange(_tmpVec, _input.begin(), _input.end());
	Utils::fillContainerRange(_tmpLst, _input.begin(), _input.end());
}

void	PMergeMe::pmm(void)
{
	if (_input.empty())
		throw std::logic_error("input empty");
	if (_input.size() < 5 || _input.size() > 3000)
		throw std::runtime_error("the program sorts 5 to 3000 elements");
	else
	{
		initContainers();
		sortIntVec();
		sortIntLst();
	}
	printResult();
}

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
: _input(copy._input), _tmpVec(IntVec(copy._tmpVec)), _tmpLst(IntLst(copy._tmpLst))
{
	// std::cout << "[PMergeMe] Copy constructor called" << RESET << std::endl;
}

PMergeMe &PMergeMe::operator=(const PMergeMe &op)
{
	_input = op._input;
	_tmpVec = IntVec(op._tmpVec);
	_tmpLst = IntLst(op._tmpLst);
	// std::cout << "[PMergeMe] Copy assignment operator called" << RESET << std::endl;
	return (*this);
}

PMergeMe::~PMergeMe(void)
{
	// std::cout << "[PMergeMe] Destructor called" << RESET << std::endl;
}
