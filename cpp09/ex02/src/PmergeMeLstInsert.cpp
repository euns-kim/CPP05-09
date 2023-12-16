#include "PmergeMe.hpp"

// void	PmergeMe::InsertPendToMainLst(void)
// {
	
// }

void	PmergeMe::generateSequenceLst(void)
{
	size_t n;
	size_t J;
	size_t prevJ;
	std::list<size_t>::iterator it;

	for (n = 3; n < _JacobLst.size(); ++n)
	{
		it = _JacobLst.begin();
		advance(it, n);
		J = *it;
		prevJ = *(--it);
		for (; J > prevJ; --J)
			_sequenceLst.push_back(J - 1);
	}

	prevJ = *(++it);
	for (J = _pendLst.size(); J > prevJ; --J)
		_sequenceLst.push_back(J - 1);
}

void	PmergeMe::generateJacobsthalLst(void)
{
	size_t n = 1;
	size_t J = 0;

	while (J <= _pendLst.size())
	{
		_JacobLst.push_back(J);
		J = std::pow(2, n - 1) - J;
		++n;
	}
}

void	PmergeMe::initMainAndPendLst(PairLst ab)
{
	PairLstIt it = ab.begin();
	int last = 0;

	if (_size % 2 == 1)
	{
		last = it->second;
		++it;
	}

	while (it != ab.end())
	{
		if (_mainLst.empty())
			_mainLst.push_back(it->second);
		_mainLst.push_back(it->first);
		_pendLst.push_back(it->second);
		++it;
	}

	if (last != 0)
		_pendLst.push_back(last);
}
