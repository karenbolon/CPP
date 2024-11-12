/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:55:13 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/11 10:24:54 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
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
	
	Fixed&	operator= (const Fixed& src); //assignment operator

//getter:
	int		getRawBits( void ) const;
//setter:
	void	setRawBits( int const raw );
//public methods:
	float	toFloat( void ) const;
	int 	toInt( void ) const;
	
	~Fixed(); //destructor
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

