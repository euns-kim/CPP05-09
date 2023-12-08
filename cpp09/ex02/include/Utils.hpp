#ifndef UTILS_HPP
# define UTILS_HPP

using std::cout;
using std::cerr;
using std::endl;

namespace Utils
{
	template <typename T, typename It>
	void	fillContainerRange(T &container, It first, It last)
	{
		container.empty();
		container.insert(container.end(), first, last);
	}

	template <typename T>
	void	printContainer(T const &container)
	{
		container::iterator it = container.begin();

		for (; it != container.end(); ++it)
			cout << *it << " ";
		cout << endl;
	}
}

#endif