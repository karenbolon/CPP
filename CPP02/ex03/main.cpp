/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:51:57 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/08 16:28:46 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
a is initialised to 0 (float 0.0) (0 / 256 = 0)
++a increments _fixedPointValue by 1 (1 / 256 ~= 0.00390625)
a++ increments _fixedPointValue by 0.00390625 + 0.00390625 = 0.0078125

b is initialised to( 5.05 * 256 ~= 1293) * (2 *256 = 512) / 256 ~= 2586
which is approx 10.1*/

int main( void )
{
	Point points[5] = {
		Point (5, 5),
		Point (-1, 10),
		Point (12, 20),
		Point (8, 2),
		Point (50, 50)
	};
	const	Point A(0, 0);
	const	Point B(10, 0);
	const	Point C(0, 10);

	for (int i = 0; i < 5; ++i)
	{	
		if (bsp(A, B, C, points[i]))
			std::cout << "Point P1 is inside the triangle." << std::endl;
		else
			std::cout << "Point P1 is outside the triangle." << std::endl;
	}
	return 0;
}