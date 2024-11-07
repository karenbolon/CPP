/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:55:13 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/07 15:50:17 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

/*COPY CONSTRUCTOR automatically copies everything from the original object.
By using the 'const Fixed&', we tell the compiler that we are copying the 
contents of the original but not making changes to it. The '&' basically says
we are taking a 'peak' at the original object before copying it.  It is in the
function in Fixed.cpp that we make the actual copy.

COPY ASSIGNMENT OPERATOR is like a tool that overwrites the copy to match the
original. It does not create a new copy.

If a new object has to be created before the copying can occur, the copy 
constructor is used (note: this includes passing or returning objects by value).

If a new object does not have to be created before the copying can occur, 
the assignment operator is used.

ORTHODOX CANONICAL FORM: must have:
- a default constructor: A constructor that takes no arguments and initializes 
	the object to a valid, default state.
- a copy constructor: A constructor that allows creating a new object as a 
	copy of an existing object. It takes a const reference to the original 
	object to avoid modifying it.
- a copy assignment operator: An operator overload (operator=) that allows 
	assigning one object to another, overwriting the existing object’s data. 
	This operator also takes a const reference to the other object and checks 
	for self-assignment to avoid unnecessary copying.
- a destructor: A function that is called when an object goes out of scope or 
	is deleted. The destructor cleans up any resources the object may have 
	acquired during its lifetime, such as memory or file handles.
*/
	
class Fixed
{
private:
	int					_fixedPoint;
	static const int	_fractionalBits;

public:
	Fixed(); //default constructor
	Fixed(const Fixed& copy); //copy constructor
	Fixed&	operator= (const Fixed& overloadCopy); //overload assignment
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	
	~Fixed(); //destructor
};



