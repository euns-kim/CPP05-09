#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <vector>
# include <list>
# include <iostream>

template < typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{

	public:
		MutantStack(void) : std::stack<T, Container>() {}
		MutantStack(const MutantStack &copy) : std::stack<T, Container>(copy._mstack) {}
		MutantStack &operator=(const MutantStack &op) {
			if (this != &op) {
				std::stack<T, Container>::operator=(op);
				return (*this);
			}
		}
		virtual ~MutantStack(void) {}

		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

		typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }

		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		const_iterator cbegin() { return this->c.cbegin(); }
		const_iterator cend() { return this->c.cend(); }

		typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator crbegin() { return this->c.crbegin(); }
		const_reverse_iterator crend() { return this->c.crend(); }

};

#endif
