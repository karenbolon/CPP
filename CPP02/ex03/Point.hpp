/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:55:13 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/08 16:08:30 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed _y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& copy);
		~Point();

		const Fixed &getX() const;
		const Fixed &getY() const;

		Point& operator=(const Point& copy);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
//std::ostream& operator<<(std::ostream& os, Point const point);

