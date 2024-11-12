/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:49:44 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/11 10:07:35 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPoint( 0 )
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& copy )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPoint = copy.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator= (const Fixed& overloadCopy)
{
	//check for self-assignment, we do not want to write over original
	std::cout <<"Copy assignment operator called" << std::endl;
	if (this != &overloadCopy)
		this->_fixedPoint = overloadCopy.getRawBits();
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawbits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixedPoint = raw;
}
