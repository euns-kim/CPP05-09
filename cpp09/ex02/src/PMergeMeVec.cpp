#include "PMergeMe.hpp"

void	PMergeMe::mergeSortFirstVec(PairVec &ab, int const begin, int const end)
{
	if (begin >= end)
		return ;

	int mid = begin + (end - begin) / 2;
	mergeSortFirstVec(ab, begin, mid);
	mergeSortFirstVec(ab, mid + 1, end);
	mergeVec(ab, begin, mid, end);
}

PairVec	PMergeMe::initPairVec(void)
{
	PairVec ab;

	IntVecIt it = _tmpVec.begin();
	int prev;

	for (; it != _tmpVec.end()-- && it != _tmpVec.end(); ++it)
	{
		prev = *it;
		++it;
		if (prev > *it)
			ab.push_back(std::make_pair(prev, *it));
		else
			ab.push_back(std::make_pair(*it, prev));
	}
	if (it != _tmpVec.end())
		ab.push_back(std::make_pair(-1, *it));
	return (ab);
}

void	PMergeMe::sortIntVec(void)
{
	PairVec ab = initPairVec();
	
	mergeSortFirstVec(ab, 0, ab.size() - 2);
}
