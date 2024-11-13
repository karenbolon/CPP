/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:09:48 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/12 16:47:01 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type( "WrongAnimal" ) {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy ) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	_type = copy._type;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal &src ) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &src)
		_type = src._type;
	return (*this);
}

std::string		WrongAnimal::getType() const{
	return (this->_type);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal deconstructor called" << std::endl;
}

void	WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal sound..eee! eee! 🐵" << std::endl;
}