#include "PmergeMe.hpp"

// void	PmergeMe::InsertPendToMainVec(void)
// {
	
// }

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

	if (last != 0)
		_pendVec.push_back(last);
}
