/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:49:44 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/08 16:28:41 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _fixedPointValue(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	_fixedPointValue = number << _fractionalBits;
//	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float number)
{
	_fixedPointValue = roundf(number * (1 << _fractionalBits));
//	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy): _fixedPointValue(copy._fixedPointValue)
{
//	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator= (const Fixed& overloadCopy)
{
	//check for self-assignment, we do not want to write over original
	if (this != &overloadCopy)
	{
		this->_fixedPointValue = overloadCopy._fixedPointValue;
	}
//	std::cout <<"Copy assignment operator called" << std::endl;
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
//	std::cout << "getRawbits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits( int const raw )
{
//	std::cout << "setRawbits member function called" << std::endl;
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


//Incremental operators:
Fixed&	Fixed::operator--()
{
	_fixedPointValue--;
	return (*this);
}

Fixed&	Fixed::operator++()
{
	_fixedPointValue++;
	return (*this);
}

//the (int) is a placeholder to help the compiler differentiate
//between the prefix and postfix --operator
Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;

	_fixedPointValue--;
	return ( temp );
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;

	_fixedPointValue++;
	return ( temp );	
}

//Arithmetic operators:
/* 
Only one parameter (const Fixed& overloadCopy) is needed, because the 
left operand (the calling object) is implicitly available as *this. 
*/
Fixed	Fixed::operator+ (const Fixed& overloadCopy) const
{
	return (Fixed( this->toFloat() + overloadCopy.toFloat() ));
}

Fixed	Fixed::operator- (const Fixed& overloadCopy) const
{
	return (Fixed( this->toFloat() - overloadCopy.toFloat() ));
}

Fixed	Fixed::operator* (const Fixed& overloadCopy) const
{
	return (Fixed( this->toFloat() * overloadCopy.toFloat() ));
}

Fixed	Fixed::operator/ (const Fixed& overloadCopy) const
{
	return (Fixed( this->toFloat() / overloadCopy.toFloat() ));
}

//Comparison operators:
bool	Fixed::operator>(const Fixed& overloadCopy) const
{
	return (this->getRawBits() > overloadCopy.getRawBits() );
}

bool	Fixed::operator<(const Fixed& overloadCopy) const
{
	return (this->getRawBits() < overloadCopy.getRawBits() );
}

bool	Fixed::operator>=(const Fixed& overloadCopy) const
{
	return (this->getRawBits() >= overloadCopy.getRawBits() );
}

bool	Fixed::operator<=(const Fixed& overloadCopy) const
{
	return (this->getRawBits() <= overloadCopy.getRawBits() );
}

bool	Fixed::operator==(const Fixed& overloadCopy) const
{
	return (this->getRawBits() == overloadCopy.getRawBits() );
}

bool	Fixed::operator!=(const Fixed& overloadCopy) const
{
	return (this->getRawBits() != overloadCopy.getRawBits() );	
}

/*Public overloaded member functions*/
Fixed&	Fixed::min( Fixed& a, Fixed& b )
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed&	max( Fixed& a, Fixed& b )
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b )
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::max( const Fixed& a, const Fixed& b )
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

//overload the << operator (non-member function)
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();//outputs the floating point value 
	return (os);
}