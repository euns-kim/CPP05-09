#include "PmergeMe.hpp"
#include "Test.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		cerr << "Wrong input. Usage: ./PmergeMe [list of positive integers]" << endl;
		return (1);
	}

	if (Parser::isValidInput(++argv) == false)
	{
		cerr << "Input not valid. Must be a list of positive integers" << endl;
		return (1);
	}

	PmergeMe instance(argv, argc - 1);

	try {
		instance.pmm();
	} catch (std::exception &e) {
		cerr << "Exception caught: " << e.what() << endl;
		return (1);
	}

	return (0);
}
