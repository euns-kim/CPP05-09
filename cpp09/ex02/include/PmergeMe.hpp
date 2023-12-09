#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iterator>
# include <sys/time.h>
# include "Parser.hpp"
# include "Utils.hpp"
# include "Test.hpp"

typedef std::pair<int, int> Pair;

typedef std::vector<Pair> PairVec;
typedef PairVec::iterator PairVecIt;
typedef IntVec::iterator IntVecIt;

typedef	std::list<Pair> PairLst;
typedef std::list<int> IntLst;
typedef PairLst::iterator PairLstIt;
typedef IntLst::iterator IntLstIt;

class PmergeMe
{

	private:
		PmergeMe(void);

		IntVec _input;
		IntVec _tmpVec;
		IntLst _tmpLst;
		// long _elapsedVec;
		// long _elapsedLst;

	public:
		PmergeMe(IntVec input);
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &op);
		~PmergeMe(void);

		void pmm(void);
		void initContainers(void);

		void sortIntVec(void);
		PairVec initPairVec(void);
		void mergeSortFirstVec(PairVec &ab, size_t const begin, size_t const end);
		void mergeVec(PairVec &ab, size_t const begin, size_t const mid, size_t const end);

		void sortIntLst(void);
		PairLst initPairLst(void);
		void mergeSortFirstLst(PairLstIt begin, PairLstIt end);
		void mergeLst(PairLstIt begin, PairLstIt mid, PairLstIt end);
		PairLst createSubLst(PairLstIt begin, PairLstIt end);
		PairLstIt calculateMidLst(PairLstIt begin, PairLstIt end);

		// void printResult(void);
		
};

#endif