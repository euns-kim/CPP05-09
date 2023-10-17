/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:12:39 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/17 18:44:57 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	printT(T const &value)
{
	std::cout << value << " ";
}

template <typename T, typename Func>
void	iter(T *arr, int const len, Func f)
{
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

// template <typename T>
// void	iter(T *arr, int len, void (*f)(T))
// {
// 	for (int i = 0; i < len; i++)
// 		f(arr[i]);
// }

#endif