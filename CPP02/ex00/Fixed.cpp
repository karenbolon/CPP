/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:49:44 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/07 11:53:53 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
	this->_fixedPoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	this->_fixedPoint = copy._fixedPoint;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed&	Fixed::operator= (const Fixed& overloadCopy)
{
	//check for self-assignment, we do not want to write over original
	if (this != &overloadCopy)
	{
		this->_fixedPoint = overloadCopy._fixedPoint;
	}
	std::cout <<"Copy assignment operator called" << std::endl;
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawbits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawbits member function called" << std::endl;
	this->_fixedPoint = raw;
}
