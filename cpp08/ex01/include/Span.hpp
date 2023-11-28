#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <iostream>
# include <algorithm>
# include <cstdlib>

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
		void			addNumber(int n);
		void			fillContainerRandom(void);
		template <typename Itr>
		void			fillContainerRange(Itr first, Itr last);
		void			checkException(void);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		void			printContainer(void);

};

template <typename Itr>
void	Span::fillContainerRange(Itr first, Itr last)
{
	if (std::distance(first, last) + _container.size() > _size)
		throw std::logic_error("no efficient place to insert integers");
	_container.insert(_container.end(), first, last);
}

#endif