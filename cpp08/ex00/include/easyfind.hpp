#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename Container>
typename Container::iterator easyfind(Container &container, const int &toFind)
{
	typename Container::iterator itr = \
	std::find(container.begin(), container.end(), toFind);

	if (itr == container.end())
		throw std::runtime_error("given integer not found");
	return (itr);
}

#endif
