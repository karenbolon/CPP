/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:55:13 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/06 16:29:27 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Fixed
{
private:
	int					fixedPointNumber;
	static const int	fractionalBits;
public:
	fixed(/* args */);
	copyFixed(/* args */)
	~fixed();
	int	getFixedPointNumber();
	void	setFixedPointNumber();
};

Fixed::Fixed(/* args */)
{
}

Fixed::~Fixed()
{
}

Fixed::int	getFixedPointNumber(int	number)
{
	return (fixedPointNumbe);
}

Fixed::void	setFixedPointNumber()
{
	
}

int	Fixed::fractionalBits = 8; 