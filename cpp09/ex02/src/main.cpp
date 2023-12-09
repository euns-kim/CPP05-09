#include "PmergeMe.hpp"
#include "Test.hpp"

// for test without parser
int main(void)
{
	IntVec tmpVec;
	tmpVec.push_back(3);
	tmpVec.push_back(2);
	tmpVec.push_back(8);
	tmpVec.push_back(6);
	tmpVec.push_back(4);
	tmpVec.push_back(7);
	tmpVec.push_back(10);
	tmpVec.push_back(0);
	tmpVec.push_back(9);
	tmpVec.push_back(5);
	tmpVec.push_back(34);
	tmpVec.push_back(10);
	tmpVec.push_back(0);
	tmpVec.push_back(9);
	tmpVec.push_back(30);
	tmpVec.push_back(17);
	tmpVec.push_back(22);
	tmpVec.push_back(32);
	tmpVec.push_back(38);
	tmpVec.push_back(48);
	tmpVec.push_back(1);
	tmpVec.push_back(322);
	tmpVec.push_back(344);
	tmpVec.push_back(90);
	tmpVec.push_back(30);

	PmergeMe instance(tmpVec);

	try {
		instance.pmm();
	} catch (std::exception &e) {
		cerr << "Exception caught: " << e.what() << endl;
		return (1);
	}

	return (0);
}

// int main(int argc, char **argv)
// {
// 	if (argc == 1)
// 	{
// 		cout << "Wrong input. Usage: ./PMergeMe [list of positive integers]" << endl;
// 		return (1);
// 	}

// 	IntVec tmpVec;

// 	try {
// 		if (argc == 2)
// 			tmpVec = Parser::parser(static_cast<std::string>(argv[1]));
// 		else
// 			tmpVec = Parser::parser(++argv);
// 	} catch (std::exception &e) {
// 		cerr << "Exception caught: " << e.what() << endl;
// 		return (1);
// 	}

// 	PMergeMe instance(tmpVec);

// 	try {
// 		instance.pmm();
// 	} catch (std::exception &e) {
// 		cerr << "Exception caught: " << e.what() << endl;
// 		return (1);
// 	}

// 	return (0);
// }
