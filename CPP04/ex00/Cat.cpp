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
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat( const Cat& copy ) : Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	_type = copy._type;
}

Cat& Cat::operator=( const Cat &src ) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &src)
		_type = src._type;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat deconstructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "😺 Meow! Meow! 😺" << std::endl;
}
