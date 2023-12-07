#include "PMergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		cout << "Wrong input. Usage: ./PMergeMe [list of positive integers]" << endl;
		return (1);
	}

	IntVec tmpVec;

	try {
		if (argc == 2)
			tmpVec = Parser::parser(static_cast<std::string>(argv[1]));
		else
			tmpVec = Parser::parser(++argv);
	} catch (std::exception &e) {
		cerr << "Exception caught: " << e.what() << endl;
		return (1);
	}

	PMergeMe instance(tmpVec);

	try {
		instance.pmm();
	} catch (std::exception &e) {
		cerr << "Exception caught: " << e.what() << endl;
		return (1);
	}

	return (0);
}
