/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:55:13 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/08 15:47:55 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
	int					_fixedPointValue;
	static const int	_fractionalBits;

public:
//constructors:
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed& copy);
	
	Fixed&	operator= (const Fixed& overloadCopy); //overload assignment

	Fixed&	operator--();
	Fixed&	operator++();
	Fixed	operator--(int);
	Fixed	operator++(int);
	
	Fixed	operator+ (const Fixed& overloadCopy) const;
	Fixed	operator- (const Fixed& overloadCopy) const;
	Fixed	operator* (const Fixed& overloadCopy) const;
	Fixed	operator/ (const Fixed& overloadCopy) const;
	
	bool	operator>(const Fixed& overloadCopy) const;
	bool	operator<(const Fixed& overloadCopy) const;
	bool	operator>=(const Fixed& overloadCopy) const;
	bool	operator<=(const Fixed& overloadCopy) const;
	bool	operator==(const Fixed& overloadCopy) const;
	bool	operator!=(const Fixed& overloadCopy) const;
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int 	toInt( void ) const;
	
	static Fixed&	min( Fixed& a, Fixed& b );
	static Fixed&	max( Fixed& a, Fixed& b );
	static const Fixed&	min( const Fixed& a, const Fixed& b );
	static const Fixed&	max( const Fixed& a, const Fixed& b );

	~Fixed(); //destructor
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

