/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:44:54 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/17 14:24:07 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

template <typename T_SWAP>
void	swap(T_SWAP &a, T_SWAP &b)
{
	T_SWAP	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T_MIN>
T_MIN	min(T_MIN a, T_MIN b)
{
	return (a < b ? a : b);
}

template <typename T_MAX>
T_MAX	max(T_MAX a, T_MAX b)
{
	return (a > b ? a : b);
}

int	main(void)
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
