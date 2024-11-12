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

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& copy ) : WrongAnimal() {
	std::cout << "WrongCat copy constructor called" << std::endl;
	_type = copy._type;
}

WrongCat& WrongCat::operator=( const WrongCat &src ) {
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &src)
		_type = src._type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat deconstructor called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "😺 Meow! Meow! 😺" << std::endl;
}
