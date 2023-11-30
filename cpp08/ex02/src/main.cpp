#include "MutantStack.hpp"

int main(void)
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);
	}
	{
		MutantStack< int, std::vector<int> > mstack;

		mstack.push(25);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(45);
		mstack.push(7);

		MutantStack< int, std::vector<int> >::iterator it = mstack.begin();
		MutantStack< int, std::vector<int> >::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}

		// std::stack<int> s(mstack);
		std::stack< int, std::vector<int> > s(mstack);
	}
	{
		MutantStack< int, std::list<int> > mstack;

		mstack.push(3);
		mstack.push(1);

		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;

		mstack.push(33);
		mstack.push(54);
		mstack.push(7327);

		MutantStack< int, std::list<int> >::iterator it = mstack.begin();
		MutantStack< int, std::list<int> >::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}

		// std::stack< int, std::vector<int> > s(mstack);
		std::stack< int, std::list<int> > s(mstack);
	}
}
