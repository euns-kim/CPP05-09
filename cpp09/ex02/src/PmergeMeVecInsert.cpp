#include "PmergeMe.hpp"

size_t	PmergeMe::binarySearchVec(int right, int toInsert)
{
	int left = 0;
	int mid;

	while (left <= right)
	{
		mid = left + (right - left) / 2;

		if (toInsert > _mainVec.at(mid))
			left = mid + 1;
		else if (toInsert < _mainVec.at(mid))
			right = mid - 1;
		else
			return (mid);
	}
	if (toInsert > _mainVec.at(mid))
		return (mid + 1);
	return (mid);
}

void	PmergeMe::insertLastToMainVec(void)
{
	if (_last == 0)
		return ;
	size_t pos = binarySearchVec(_mainVec.size() - 1, _last);
	_mainVec.insert(_mainVec.begin() + pos, _last);
}

void	PmergeMe::insertPendToMainVec(void)
{
	if (_pendVec.empty() || _pendVec.size() == 1)
		return ;

	size_t addedCnt = 0;

	std::vector<size_t>::iterator it = _sequenceVec.begin();
	for (; it != _sequenceVec.end(); ++it)
	{
		int toInsert = _pendVec.at(*it);
		size_t pos = binarySearchVec(*it + 1 + addedCnt, toInsert);
		_mainVec.insert(_mainVec.begin() + pos, toInsert);
		++addedCnt;
	}
}

void	PmergeMe::generateSequenceVec(void)
{
	size_t n;
	size_t J;
	size_t prevJ;

	for (n = 3; n < _JacobVec.size(); ++n)
	{
		J = _JacobVec.at(n);
		prevJ = _JacobVec.at(n - 1);
		for (; J > prevJ; --J)
			_sequenceVec.push_back(J - 1);
	}

	prevJ = _JacobVec.at(n - 1);
	for (J = _pendVec.size(); J > prevJ; --J)
		_sequenceVec.push_back(J - 1);
}

void	PmergeMe::generateJacobsthalVec(void)
{
	size_t n = 1;
	size_t J = 0;

	while (J <= _pendVec.size())
	{
		_JacobVec.push_back(J);
		J = std::pow(2, n - 1) - _JacobVec.at(n - 1);
		++n;
	}
}

void	PmergeMe::initMainAndPendVec(PairVec ab)
{
	size_t i = 0;
	int last = 0;

	if (_size % 2 == 1)
		last = ab.at(i++).second;

	while (i < ab.size())
	{
		if (_mainVec.empty())
			_mainVec.push_back(ab.at(i).second);
		_mainVec.push_back(ab.at(i).first);
		_pendVec.push_back(ab.at(i).second);
		++i;
	}

	_last = last;
}
