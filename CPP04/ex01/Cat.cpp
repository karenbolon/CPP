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

#include "Cat.hpp"


Cat::Cat() : Animal() {
	_type = "Cat";
	try {
		_brain = new Brain();
	}
	catch ( const std::bad_alloc& bad) {
		throw bad;
	}
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal( copy ) {
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain();
}

Cat& Cat::operator=( const Cat &src ) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &src) {
		Animal::operator=(src);
		delete _brain;
		_brain = new Brain(*(src._brain));
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat deconstructor called" << std::endl;
	delete _brain;
}

void	Cat::makeSound() const {
	std::cout << "😺 Meow! Meow! 😺" << std::endl;
}
