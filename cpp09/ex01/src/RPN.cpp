#include "RPN.hpp"

/* Orthodox Canonical Form */

RPN::RPN(void) : _input(NULL), _result(0)
{
	// std::cout << "[RPN] Default constructor called" << RESET << std::endl;
}

RPN::RPN(std::string _input) : _input(input), _result(0)
{
	// std::cout << "[RPN] String constructor called" << RESET << std::endl;
}

RPN::RPN(const RPN &copy) : _input(input), _stack(std::stack<int>(copy._stack)), _result(0)
{
	// std::cout << "[RPN] Copy constructor called" << RESET << std::endl;
}

RPN &RPN::operator=(const RPN &op)
{
	if (this != &op)
	{
		this->_input = op._input;
		this->_stack = std::stack<int>(op._stack);
		this->_result = op._result;
	}
	// std::cout << "[RPN] Copy assignment operator called" << RESET << std::endl;
	return (*this);
}

RPN::~RPN(void)
{
	// std::cout << "[RPN] Destructor called" << RESET << std::endl;
}

/* Method functions */

void	RPN::RPNparser(void) {}
void	RPN::calculateResult(void) {}
void	RPN::printResult(void) {}
