#include "RPN.hpp"

/* Orthodox Canonical Form */

RPN::RPN(void) : _input(NULL), _result(0)
{
	// std::cout << "[RPN] Default constructor called" << RESET << std::endl;
}

RPN::RPN(std::string input) : _input(input), _result(0)
{
	// std::cout << "[RPN] String constructor called" << RESET << std::endl;
}

RPN::RPN(const RPN &copy)
: _input(copy._input), _stack(std::stack<int>(copy._stack)), _result(copy._result)
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

int	RPN::safePeekPop(void)
{
	if (_stack.empty())
		throw std::logic_error("wrong input. Cannot calculate.");

	int topElement = _stack.top();
	_stack.pop();
	return (topElement);
}

void	RPN::calculator(char op)
{
	int rhs = safePeekPop();
	int lhs = safePeekPop();

    switch (op)
	{
		case '+':
			_stack.push(lhs + rhs);
			break;
		case '-':
			_stack.push(lhs - rhs);
			break;
		case '/':
			if (rhs == 0)
				throw std::logic_error("a number cannot be divided by 0");
			_stack.push(lhs / rhs);
			break;
		case '*':
			_stack.push(lhs * rhs);
			break;
		default:
			throw std::logic_error("wrong input. Cannot calculate.");
    }
}

void	RPN::calculateResult(void)
{
	unsigned int i = 0;

	while (i < _input.length())
	{
		if (_input[i] >= '0' && _input[i] <= '9')
			_stack.push(static_cast<int>(_input[i] - '0'));
		else if (strchr("+-*/", _input[i]) != NULL)
			calculator(_input[i]);
		else if (!isspace(_input[i]))
			throw std::logic_error("wrong input. Cannot calculate.");
		i++;
	}
	_result = safePeekPop();
	if (!_stack.empty())
		throw std::logic_error("wrong input. Cannot calculate.");
}

void	RPN::printResult(void)
{
	std::cout << "Result: " << _result << std::endl;
}
