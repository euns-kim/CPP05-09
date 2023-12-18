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

PairLst	PmergeMe::initPairLst(IntLst tmpLst)
{
	PairLst ab;

	IntLstIt it = tmpLst.begin();
	int prev;

	for(; it != --tmpLst.end() && it != tmpLst.end(); ++it)
	{
		prev = *it;
		++it;
		if (prev > *it)
			ab.push_back(std::make_pair(prev, *it));
		else
			ab.push_back(std::make_pair(*it, prev));
	}
	if (it != tmpLst.end())
		ab.push_back(std::make_pair(-1, *it));
	return (ab);
}

IntLst	PmergeMe::initIntLst(void)
{
	IntLst tmpLst;

	size_t i = 0;
	while (*(_input + i) != NULL)
	{
		tmpLst.push_back(strtol(*(_input + i), NULL, 10));
		++i;
	}
	return (tmpLst);
}

void	PmergeMe::sortIntLst(void)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);

	IntLst tmpLst = initIntLst();
	PairLst ab = initPairLst(tmpLst);

	// Test::printPairContainer(ab);
	mergeSortFirstLst(ab.begin(), ab.end());
	initMainAndPendLst(ab);

	// Test::printPairContainer(ab);
	// Utils::printContainer(_mainLst);
	// Utils::printContainer(_pendLst);

	generateJacobsthalLst();
	generateSequenceLst();
	insertPendToMainLst();
	insertLastToMainLst();

	// Utils::printContainer(_JacobLst);
	// Utils::printContainer(_sequenceLst);
	// Utils::printContainer(_mainLst);

	gettimeofday(&end, NULL);
	long seconds = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	_elapsedLst = seconds * 1000000 + microseconds;
}
