/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:43:01 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/15 21:09:21 by eunskim          ###   ########.fr       */
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
T_MIN	min(T_MIN a, T_MIN b)
{
	return (a < b ? a : b);
}

template <typename T_MAX>
T_MAX	max(T_MAX a, T_MAX b)
{
	return (a > b ? a : b);
}

#endif