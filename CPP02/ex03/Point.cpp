/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:49:44 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/08 16:29:11 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
//	std::cout << "default point constructor called" << std::endl;
}
//initialises the points in the class to those provided
Point::Point( const float x, const float y) : _x(Fixed (x)), _y(Fixed(y))
{
//	std::cout << "point constructor called" << std::endl;
}

//copy constructor
Point::Point( const Point& copy)  : _x(copy.getX() ), _y(copy.getY() )
{
//	std::cout << "point copy constructor called" << std::endl;
	*this = copy;
}

Point::~Point()
{
//	std::cout << "deconstructor called" << std::endl;
}

const Fixed &Point::getX()const
{
	return (this->_x);
}

const Fixed &Point::getY() const
{
	return (this->_y);
}


Point&	Point::operator=(const Point& copy)
{
	//check for self-assignment, we do not want to write over original
	if (this != &copy)
	{
		(Fixed) _x = copy.getX();
		(Fixed) _y = copy.getY();
	//	std::cout <<"Point assignment operator called" << std::endl;
		}
	return (*this);
}