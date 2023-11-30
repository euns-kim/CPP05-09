#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cerr << "Usage: ./rpn [reverse Polish notation]" << std::endl;
	
	RPN	rpn = RPN(static_cast<std::string>(argv[1]));

	try {
		rpn.parser();
		rpn.calculateResult();
		rpn.printResult();
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}