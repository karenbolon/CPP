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
	try {
		_brain = new Brain();
	}
	catch ( const std::bad_alloc& bad) {
		throw bad;
	}
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal( copy ) {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain();
}

Dog& Dog::operator=( const Dog &src ) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &src) {
		Animal::operator=(src);
		delete _brain;
		_brain = new Brain(*(src._brain));
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog deconstructor called" << std::endl;
	delete _brain;
}

void	Dog::makeSound() const {
	std::cout << "🐶 Arf! Arf! 🐶" << std::endl;
}
