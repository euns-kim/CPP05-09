/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:43:01 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/17 18:43:42 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T_SWAP>
void	swap(T_SWAP &a, T_SWAP &b)
{
	T_SWAP	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T_MIN>
T_MIN const	&min(T_MIN const &a, T_MIN const &b)
{
	return (a < b ? a : b);
}

template <typename T_MAX>
T_MAX const	&max(T_MAX const &a, T_MAX const &b)
{
	return (a > b ? a : b);
}

#endif