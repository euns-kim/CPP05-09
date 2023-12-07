#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iterator>
# include "Parser.hpp"

typedef std::pair<int, int> Pair;

typedef std::vector<Pair> PairVec;
typedef PairVec::iterator PairVecIt;
typedef IntVec::iterator IntVecIt;

typedef	std::list<Pair> PairLst;
typedef std::list<int> IntLst;
typedef PairLst::iterator PairLstIt;
typedef IntLst::iterator IntLstIt;

class PMergeMe
{

	private:
		PMergeMe(void);

		IntVec _input;
		IntVec _resultVec;
		IntLst _resultLst;

	public:
		PMergeMe(IntVec input);
		PMergeMe(const PMergeMe &copy);
		PMergeMe &operator=(const PMergeMe &op);
		~PMergeMe(void);

		void pmm(void);

		PairVec initPairVec(void);
		PairLst initPairLst(void);

		void printResult(void);

};

#endif