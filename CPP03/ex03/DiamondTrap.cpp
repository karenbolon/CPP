/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:03:10 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/09 18:42:33 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()  : ClapTrap(), FragTrap(), ScavTrap(){
	this->_name = "no_name";
	ClapTrap::_name = _name + "_clap";

	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(), ScavTrap(){
	this->_name = name;
	ClapTrap::_name = _name + "_clap";

	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " constructor has been called" << std::endl;
}
 
DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap( copy ), FragTrap( copy ), ScavTrap( copy ){
	std::cout << "DiamondTrap " << this->_name << " copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap &src ){

	if (this != &src)
	{
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
		std::cout << "DiamondTrap " << this->_name << " assignment operator called" << std::endl;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap " << this->_name << " deconstructor has been called" << std::endl;
}

void	DiamondTrap::whoAmI(){
	std::cout << "I have 2 names: " << this->_name << " and " << ClapTrap::_name << std::endl;
}
