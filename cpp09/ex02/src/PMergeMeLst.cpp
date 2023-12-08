#include "PMergeMe.hpp"

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

	mergeSortFirstLst(ab);
}
