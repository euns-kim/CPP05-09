#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./rpn [reverse Polish notation]" << std::endl;
		return (1);
	}
	
	RPN	rpn = RPN(static_cast<std::string>(argv[1]));

	try {
		rpn.calculateResult();
		rpn.printResult();
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

// ./RPN "3 4 5 * +" = 23
// ./RPN "3 4 + 5 *" = 35
// ./RPN "3 4 5 * + 4 7 2 - * +" = 43
// ./RPN "3 4 + 5 + 4 / 0 * 1 * 4 + 5 7 + * 3 /" = 16
// ./RPN "5 1 2 + 4 * + 3 - 6 2 / +" = 17
// ./RPN "9 8 4 / * 5 3 2 * - + 9 5 2 3 + + * +" = 107