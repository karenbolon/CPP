/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:49:44 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/11 16:26:37 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal( copy ) {
	std::cout << "Dog copy constructor called" << std::endl;
	_type = copy._type;
}

Dog& Dog::operator=( const Dog &src ) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &src)
		_type = src._type;
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog deconstructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "🐶 Arf! Arf! 🐶" << std::endl;
}

