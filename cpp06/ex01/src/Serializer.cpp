/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:38:53 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/13 17:48:04 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

/* Orthodox Canonical Form */

Serializer::Serializer(void)
{
	// std::cout << PEACH << "[Serializer] Default constructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	(void) copy;
	// std::cout << PEACH << "[Serializer] Copy constructor called" << RESET << std::endl;
}

Serializer &Serializer::operator=(const Serializer &op)
{
	(void) op;
	// std::cout << PEACH << "[Serializer] Copy assignment operator called" << RESET << std::endl;
	return (*this);
}

Serializer::~Serializer(void)
{
	// std::cout << PEACH << "[Serializer] Destructor called" << RESET << std::endl;
}
