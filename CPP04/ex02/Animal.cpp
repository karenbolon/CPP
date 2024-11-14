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

#include "Animal.hpp"

Animal::Animal() : _type( "Animal" ) {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal( const Animal& copy ) {
	std::cout << "Animal copy constructor called" << std::endl;
	_type = copy._type;
}

Animal& Animal::operator=( const Animal &src ) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &src)
		_type = src._type;
	return (*this);
}

std::string		Animal::getType() const{
	return (this->_type);
}

Animal::~Animal(){
	std::cout << "Animal deconstructor called" << std::endl;
}

void	Animal::makeSound() const{
	std::cout << "Animal sound...grr!!" << std::endl;
}