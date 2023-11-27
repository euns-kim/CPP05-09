#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>

class Span
{

	private:
		std::vector<int>	_container;
		unsigned int		_size;

	public:
		/* Orthodox Canonical Form */
		Span(void);
		Span(unsigned int size);
		Span(const Span &copy);
		Span &operator=(const Span &op);
		~Span(void);

		/* Method functions */
		void	addNumber(int n);
		void	fillContainerRandom(void);
		void	checkException(void);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	printContainer(void);

};

#endif