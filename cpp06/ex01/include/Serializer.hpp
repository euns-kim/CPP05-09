/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:28:52 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/13 17:53:23 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"

# define RESET	"\x1B[0m"
# define PEACH	"\x1B[38;2;255;153;153m"
# define HERB	"\x1B[38;2;204;255;229m"
# define GREY	"\x1B[38;2;224;224;224m"

class Serializer
{

	public:
		uintptr_t	serialize(Data *ptr);
		Data		*deserialize(uintptr_t raw);

		Serializer(void);
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &op);
		~Serializer(void);

};


#endif