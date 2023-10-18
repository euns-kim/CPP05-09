/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:37:09 by eunskim           #+#    #+#             */
/*   Updated: 2023/10/18 13:07:08 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
class Array
{
    private:
        T               *_arr;
        unsigned int    _size;

    public:
        Array(void);
        Array(unsigned int n);
        Array(Array<T> const &copy);
        Array &operator=(Array<T> const &op);
        ~Array(void);

        T	&operator[](unsigned int) const;
        int	size(void) const;

        void    printArray(void) const;

        class WrongIndexException : public std::exception
        {
            public:
               const char  *what() const throw();
        };

};

template <typename T>
Array<T>::Array(void) : _arr(NULL), _size(0)
{
    // cout << SKY << "Default constructor called" << RESET << endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    // cout << SKY << "Size constructor called" << RESET << endl;
	if (n != 0)
		_arr = new T[n];
	else
		_arr = NULL;
}

template <typename T>
Array<T>::Array(Array<T> const &copy)
{
	// cout << SKY << "Copy constructor called" << RESET << endl;
	_size = copy._size;
	if (copy._arr == NULL)
		_arr = NULL;
	else
	{
		_arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = copy._arr[i];
	}
}

template <typename T>
Array<T>   &Array<T>::operator=(Array<T> const &op)
{
    // cout << SKY << "Copy assignment operator called" << RESET << endl;
	if (this != &op)
	{
		_size = op._size;
    	if (_arr != NULL)
        	delete[] _arr;
		if (op._arr == NULL)
			_arr = NULL;
		else
		{
			_arr = new T[_size];
			for (unsigned i = 0; i < _size; i++)
				_arr[i] = op._arr[i];
		}
	}
    return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
    // cout << SKY << "Destructor called" << RESET << endl;
    if (_arr != NULL)
        delete[] _arr;
}

template <typename T>
T	&Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw WrongIndexException();
    return (_arr[i]);
}

template <typename T>
int Array<T>::size(void) const
{
    return (_size);
}

template <typename T>
void	Array<T>::printArray(void) const
{
    for (unsigned int i = 0; i < _size; i++)
        cout << _arr[i] << " " << endl;
}

template <typename T>
const char	*Array<T>::WrongIndexException::what(void) const throw()
{
    return ("index is out of bounds");
}
