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

#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal() {
	_type = "WrongDog";
	std::cout << "WrongDog default constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& copy) : WrongAnimal( copy ) {
	std::cout << "WrongDog copy constructor called" << std::endl;
	_type = copy._type;
}

WrongDog& WrongDog::operator=( const WrongDog &src ) {
	std::cout << "WrongDog assignment operator called" << std::endl;
	if (this != &src)
		_type = src._type;
	return (*this);
}

WrongDog::~WrongDog() {
	std::cout << "WrongDog deconstructor called" << std::endl;
}

void	WrongDog::makeSound() const {
	std::cout << "WrongDog sound. 🐷 oink! " << std::endl;
}

