#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <stdexcept>

class RPN
{

	private:
		std::string		_input;
		std::stack<int>	_stack;
		int				_result;

	public:
		RPN(void);
		RPN(std::string	input);
		RPN(const RPN &copy);
		RPN &operator=(const RPN &op);
		~RPN(void);

		void	RPNparser(void);
		void	calculateResult(void);
		void	printResult(void);

};

#endif