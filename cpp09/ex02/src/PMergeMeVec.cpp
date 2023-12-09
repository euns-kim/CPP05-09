#include "PmergeMe.hpp"

void	PmergeMe::mergeVec(PairVec &ab, size_t const begin, size_t const mid, size_t const end)
{
	size_t sizeLeft = mid - begin + 1;
	size_t sizeRight = end - mid;

	PairVec left(sizeLeft);
	PairVec right(sizeRight);

	for (size_t i = 0; i < sizeLeft; ++i)
		left[i] = ab[begin + i];
	for (size_t j = 0; j < sizeRight; ++j)
		right[j] = ab[mid + j + 1];

	size_t indexLeft = 0;
	size_t indexRight = 0;
	size_t indexAB = begin;

	while (indexLeft < sizeLeft && indexRight < sizeRight)
	{
		if (left[indexLeft].first < right[indexRight].first)
		{
			ab[indexAB] = left[indexLeft];
			indexLeft++;
		}
		else
		{
			ab[indexAB] = right[indexRight];
			indexRight++;
		}
		indexAB++;
	}

	while (indexLeft < sizeLeft)
	{
		ab[indexAB] = left[indexLeft];
		indexAB++;
		indexLeft++;
	}
	while (indexRight < sizeRight)
	{
		ab[indexAB] = right[indexRight];
		indexAB++;
		indexRight++;
	}
}

void	PmergeMe::mergeSortFirstVec(PairVec &ab, size_t const begin, size_t const end)
{
	if (begin >= end)
		return ;

	size_t mid = begin + (end - begin) / 2;
	mergeSortFirstVec(ab, begin, mid);
	mergeSortFirstVec(ab, mid + 1, end);
	mergeVec(ab, begin, mid, end);
}

PairVec	PmergeMe::initPairVec(void)
{
	PairVec ab;

	IntVecIt it = _tmpVec.begin();
	int prev;

	for (; it != --_tmpVec.end() && it != _tmpVec.end(); ++it)
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

void	PmergeMe::sortIntVec(void)
{
	PairVec ab = initPairVec();
	
	cout << "Before Sorting:" << endl;
	Test::printPairContainer(ab);
	mergeSortFirstVec(ab, 0, ab.size() - 1);
	cout << "After Sorting:" << endl;
	Test::printPairContainer(ab);
}
