/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:51:57 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/12 10:48:46 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
with this code, we can only increment Fixed const, it will not work with
regular constant.  

the binary value of 8 bits is 256 ( 2 + 4 + 8 + 16 + 32 + 64 + 128 = 256 )
a is initialised to 0 (0 / 256 = 0)
++a increments _fixedPointValue by 1 which in floating point is 
approximately 0.00390625 (1 / 256 ~= 0.00390625)
a++ increments _fixedPointValue by 0.00390625 + 0.00390625 = 0.0078125

b is initialised to( 5.05 * 256 ~= 1293) * (2 *256 = 512) / 256 ~= 2586
which is approx 10.1
*/

int main( void )
{
Fixed 		a;
Fixed const	b( Fixed( 5.05f ) * Fixed ( 2) );
Fixed		c(2);

std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;

std::cout << b << std::endl;

std::cout << Fixed::max( a, b ) << std::endl;

return (0);
}