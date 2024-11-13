/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:55:13 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/13 17:47:46 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

/*
Use const to ensure certain parts of the code cannot change certain values, 
which helps prevent accidental changes and makes the code more predictable 
and safer.

When a member function is marked as const, it guarantees that calling this 
function will not modify the internal state of the object. Use const with 
member functions that do not modify the internal state of the object.
Example: If a function only retrieves data (like getType()) but doesn’t 
change any members of the class, it should be const

Since const is used in the declaration (const Animal* Dog1 = new Dog(), only
const member functions can be called/used on it).

By marking makeSound() as const, you can call it on any const Animal* or 
const Dog*. 

*/

class Animal {
protected:
	std::string		_type;

public:
	Animal();
	Animal(const Animal& copy);
	Animal &operator=( const Animal &src );
	virtual ~Animal();

	std::string		getType() const;
	virtual void	makeSound() const;
};



