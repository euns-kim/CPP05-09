#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iterator>
# include <sys/time.h>
# include <iostream>
# include <stdexcept>
# include <string>
# include <cmath>
# include "Utils.hpp"
# include "Test.hpp"
# include "Parser.hpp"

using std::cout;
using std::cerr;
using std::endl;

typedef std::pair<int, int> Pair;

typedef std::vector<Pair> PairVec;
typedef PairVec::iterator PairVecIt;
typedef std::vector<int> IntVec;
typedef IntVec::iterator IntVecIt;

typedef	std::list<Pair> PairLst;
typedef std::list<int> IntLst;
typedef PairLst::iterator PairLstIt;
typedef IntLst::iterator IntLstIt;

class PmergeMe
{

	private:
		PmergeMe(void);

		char	**_input;
		size_t	_size;

		IntVec	_mainVec;
		IntVec	_pendVec;
		std::vector<size_t>	_JacobVec;
		std::vector<size_t>	_sequenceVec;

		IntLst	_mainLst;
		IntLst	_pendLst;
		std::list<size_t>	_JacobLst;
		std::list<size_t>	_sequenceLst;

	public:
		PmergeMe(char **input, size_t size);
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &op);
		~PmergeMe(void);

		void pmm(void);

		/* Merge Vector */
		void sortIntVec(void);
		IntVec initIntVec(void);
		PairVec initPairVec(IntVec tmpVec);
		void mergeSortFirstVec(PairVec &ab, size_t const begin, size_t const end);
		void mergeVec(PairVec &ab, size_t const begin, size_t const mid, size_t const end);

		/* Insertion Vector */
		void initMainAndPendVec(PairVec ab);
		void generateJacobsthalVec(void);
		void generateSequenceVec(void);
		// void InsertPendToMainVec(void);

		/* Merge List */
		void sortIntLst(void);
		IntLst initIntLst(void);
		PairLst initPairLst(IntLst tmpLst);
		void mergeSortFirstLst(PairLstIt begin, PairLstIt end);
		void mergeLst(PairLstIt begin, PairLstIt mid, PairLstIt end);
		PairLst createSubLst(PairLstIt begin, PairLstIt end);
		PairLstIt calculateMidLst(PairLstIt begin, PairLstIt end);

		/* Insertion List */
		void initMainAndPendLst(PairLst ab);
		void generateJacobsthalLst(void);
		void generateSequenceLst(void);
		// void InsertPendToMainLst(void);

		// void printResult(void);
		
};

#endif