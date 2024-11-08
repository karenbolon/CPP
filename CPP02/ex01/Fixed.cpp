/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:49:44 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/08 10:43:39 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	_fixedPointValue = number << _fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
{
	_fixedPointValue = roundf(number * (1 << _fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy): _fixedPointValue(copy._fixedPointValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator= (const Fixed& overloadCopy)
{
	//check for self-assignment, we do not want to write over original
	if (this != &overloadCopy)
	{
		this->_fixedPointValue = overloadCopy._fixedPointValue;
	}
	std::cout <<"Copy assignment operator called" << std::endl;
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawbits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawbits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)(_fixedPointValue) / (1 << _fractionalBits));
}

int 	Fixed::toInt( void ) const
{
	return _fixedPointValue >> _fractionalBits;
}

/*overload the << operator (non-member function)
This overload tells std::cout (or any other output stream) 
how to output your custom class.  This is required if we need
to print things like fixed-point number, complex number, or date etc*/
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();//outputs the floating point value 
	return (os);
}
