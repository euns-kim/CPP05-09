#ifndef TEST_HPP
#define TEST_HPP

using std::cout;
using std::cerr;
using std::endl;

namespace Test
{
	template <typename T>
	void printPairContainer(T &container)
	{
		typename T::iterator it = container.begin();
		cout << "----------------------------" << endl;
		for (it = container.begin(); it != container.end(); ++it)
			cout << it->first << " ";
		cout << endl;
		it = container.begin();
		for (it = container.begin(); it != container.end(); ++it)
			cout << it->second << " ";
		cout << endl;
		cout << "----------------------------" << endl;
	}
}

#endif