#include "PMergeMe.hpp"

PairLstIt	PMergeMe::calculateMidLst(PairLstIt begin, PairLstIt end)
{
	PairLstIt slow = begin;
	PairLstIt fast = begin;

	while (fast != end && ++fast != end)
	{
		++slow;
		++fast;
	}
	return (++slow);
}

PairLst PMergeMe::createSubLst(PairLstIt begin, PairLstIt end)
{
	PairLst ret;

	for (; begin != end; ++begin)
		ret.push_back(*begin);
	return (ret);
}

void	PMergeMe::mergeLst(PairLst &ab, PairLstIt begin, PairLstIt mid, PairLstIt end)
{
	PairLst left = createSubLst(begin, mid);
	PairLst right = createSubLst(mid, end);

	PairLstIt beginLeft = begin;
	PairLstIt beginRight = mid;
	PairLstIt beginAB = begin;

	while (beginLeft != mid && beginRight != end)
	{
		if (*beginLeft < *beginRight)
		{
			*beginAB = *beginLeft;
			beginLeft++;
		}
		else
		{
			*beginAB = *beginRight;
			beginRight++;
		}
		beginAB++;
	}

	if (beginLeft != mid)
		*beginAB = *beginLeft;
	if (beginRight != end)
		*beginAB = *beginRight;
}

void	PMergeMe::mergeSortFirstLst(PairLst &ab, PairLstIt begin, PairLstIt end)
{
	if (std::distance(begin, end) <= 1)
		return ;
	
	PairLstIt mid = calculateMidLst(begin, end);
	mergeSortFirstLst(ab, begin, mid);
	mergeSortFirstLst(ab, mid, end);
	mergeLst(ab, begin, mid, end);
}

PairLst	PMergeMe::initPairLst(void)
{
	PairLst ab;

	IntLstIt it = _tmpLst.begin();
	int prev;

	for(; it != _tmpLst.end()-- && it != _tmpLst.end(); ++it)
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

void	PMergeMe::sortIntLst(void)
{
	PairLst ab = initPairLst();

	mergeSortFirstLst(ab, ab.begin(), ab.end()--);
}
