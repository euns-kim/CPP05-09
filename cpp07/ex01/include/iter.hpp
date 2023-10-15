/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:12:39 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/15 21:32:18 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	printT(T value)
{
	std::cout << value << " ";
}

template <typename T, typename Func>
void	iter(T *arr, int len, Func f)
{
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

#endif