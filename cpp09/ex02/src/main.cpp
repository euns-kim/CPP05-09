#include "PmergeMe.hpp"
#include "Test.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		cout << "Wrong input. Usage: ./PmergeMe [list of positive integers]" << endl;
		return (1);
	}

	if (Parser::isValidInput(++argv) == false)
	{
		cout << "Input not valid. Must be a list of positive integers" << endl;
		return (1);
	}

	size_t argNum = argc - 1;
	if (argNum < 5 || argNum > 3000)
	{
		cout << "PmergeMe sorts 5 to 3000 elements" << endl;
		return (1);
	}

	PmergeMe instance(argv, argNum);

	try {
		instance.pmm();
	} catch (std::exception &e) {
		cout << "Exception caught: " << e.what() << endl;
		return (1);
	}

	return (0);
}
