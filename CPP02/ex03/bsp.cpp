/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:23:37 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/08 16:28:37 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
Binary Space Partitioning (BPS): is taking something and dividing
it into smaller and smaller senctions, making it easier to find
or deal with things later on.

Triangle ABC:
-Start by choosing 1 side of the triangle as a "divider", for example
side AB is our dividing line. This will split the region that is inside
the triangle versus outside.
-We calculate where our points lie (in/out)
-
*/

/*
if the result is +, 0, or - it indicates different
orientations
*/
static float	area(const Point a, const Point b, const Point c)
{
	Fixed	area;

	area = (a.getX() * (b.getY() - c.getY()) +
		b.getX() * (c.getY() - a.getY()) +
		c.getX() * (a.getY() - b.getY())) / 2;
	
	if (area.toFloat() >= 0)
		return (area.toFloat() );
	else
		return (area.toFloat() * -1);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool	value;
	Fixed	totalArea = area(a, b, c);
	Fixed	area1 = area(point, a, b);
	Fixed	area2 = area(point, b, c);
	Fixed	area3 = area(point, c, a);

//	if (area1 == 0 || area2 == 0 || area3 == 0)
//		return (value = false);
	if (area1 + area2 + area3 == totalArea)
		return (value = true);
	else
		return (value = false);
}
