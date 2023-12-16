#ifndef UTILS_HPP
# define UTILS_HPP

using std::cout;
using std::cerr;
using std::endl;

namespace Utils
{
	template <typename T>
	void	printContainer(T &container)
	{
		typename T::iterator it = container.begin();

		for (; it != container.end(); ++it)
			cout << *it << " ";
		cout << endl;
	}
}

#endif