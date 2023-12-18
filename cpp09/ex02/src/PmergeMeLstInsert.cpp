#include "PmergeMe.hpp"

size_t	PmergeMe::binarySearchLst(int right, int toInsert)
{
	int left = 0;
	int mid;
	IntLstIt it;

	while (left <= right)
	{
		it = _mainLst.begin();
		mid = left + (right - left) / 2;
		advance(it, mid);
		if (toInsert > *it)
			left = mid + 1;
		else if (toInsert < *it)
			right = mid - 1;
		else
			return (mid);
	}
	if (toInsert > *it)
		return (mid + 1);
	return (mid);
}

void	PmergeMe::insertLastToMainLst(void)
{
	if (_last == 0)
		return ;
	size_t pos = binarySearchLst(_mainLst.size() - 1, _last);
	IntLstIt it = _mainLst.begin();
	advance(it, pos);
	_mainLst.insert(it, _last);
}

void	PmergeMe::insertPendToMainLst(void)
{
	if (_pendLst.empty() || _pendLst.size() == 1)
		return ;

	size_t addedCnt = 0;

	std::list<size_t>::iterator it = _sequenceLst.begin();
	for (; it != _sequenceLst.end(); ++it)
	{
		IntLstIt it2 = _pendLst.begin();
		advance(it2, *it);
		int toInsert = *it2;
		size_t pos = binarySearchLst(*it + 1 + addedCnt, toInsert);
		IntLstIt toInsertIt = _mainLst.begin();
		advance(toInsertIt, pos);
		_mainLst.insert(toInsertIt, toInsert);
		++addedCnt;
	}
}

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

	it = _JacobLst.begin();
	advance(it, n - 1);
	prevJ = *it;
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

	_last = last;
}
