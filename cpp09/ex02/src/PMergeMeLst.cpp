#include "PmergeMe.hpp"

PairLstIt	PmergeMe::calculateMidLst(PairLstIt begin, PairLstIt end)
{
	PairLstIt slow = begin;
	PairLstIt fast = begin;

	while (fast != end && ++fast != end)
	{
		++slow;
		++fast;
	}
	return (slow);
}

PairLst	PmergeMe::createSubLst(PairLstIt begin, PairLstIt end)
{
	PairLst ret;
	PairLstIt it = begin;

	for (; it != end; ++it)
		ret.push_back(*it);
	return (ret);
}

void	PmergeMe::mergeLst(PairLstIt begin, PairLstIt mid, PairLstIt end)
{
	PairLst left = createSubLst(begin, mid);
	PairLst right = createSubLst(mid, end);

	PairLstIt beginLeft = left.begin();
	PairLstIt beginRight = right.begin();
	PairLstIt beginAB = begin;

	while (beginLeft != left.end() && beginRight != right.end())
	{
		if (beginLeft->first < beginRight->first)
		{
			*beginAB = *beginLeft;
			++beginLeft;
		}
		else
		{
			*beginAB = *beginRight;
			++beginRight;
		}
		++beginAB;
	}

	while (beginLeft != left.end())
	{
		*beginAB = *beginLeft;
		++beginAB;
		++beginLeft;
	}
	while (beginRight != right.end())
	{
		*beginAB = *beginRight;
		++beginAB;
		++beginRight;
	}
}

void	PmergeMe::mergeSortFirstLst(PairLstIt begin, PairLstIt end)
{
	if (std::distance(begin, end) <= 1)
		return ;
	
	PairLstIt mid = calculateMidLst(begin, end);
	mergeSortFirstLst(begin, mid);
	mergeSortFirstLst(mid, end);
	mergeLst(begin, mid, end);
}

PairLst	PmergeMe::initPairLst(void)
{
	PairLst ab;

	IntLstIt it = _tmpLst.begin();
	int prev;

	for(; it != --_tmpLst.end() && it != _tmpLst.end(); ++it)
	{
		prev = *it;
		++it;
		if (prev > *it)
			ab.push_back(std::make_pair(prev, *it));
		else
			ab.push_back(std::make_pair(*it, prev));
	}
	if (it != _tmpLst.end())
		ab.push_back(std::make_pair(-1, *it));
	return (ab);
}

void	PmergeMe::sortIntLst(void)
{
	PairLst ab = initPairLst();

	cout << "Before Sorting:" << endl;
	Test::printPairContainer(ab);
	mergeSortFirstLst(ab.begin(), ab.end());
	cout << "After Sorting:" << endl;
	Test::printPairContainer(ab);
}
