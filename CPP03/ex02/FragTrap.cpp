/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:38:54 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/09 18:00:20 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()  : ClapTrap(){
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " constructor has been called" << std::endl;
}
 
FragTrap::FragTrap(const FragTrap& copy) : ClapTrap( copy ){
	std::cout << "FragTrap " << this->_name << " copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap &src ){

	if (this != &src)
	{
		static_cast<ClapTrap&>(*this) = src;//calls ClapTrap assignment operator
		std::cout << "FragTrap " << this->_name << " assignment operator called" << std::endl;
	}
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << this->_name << " deconstructor has been called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "You can do this " << _name << "! Give me a high five!! 🙏 " << std::endl;
}
