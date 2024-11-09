/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:18:28 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/09 18:44:02 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()  : ClapTrap(){
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " default constructor has been called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructor has been called" << std::endl;
}
 
ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap( copy ){
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &src ){

	if (this != &src)
	{
		static_cast<ClapTrap&>(*this) = src;//calls ClapTrap assignment operator
		std::cout << "ScavTrap assignment operator called" << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << this->_name << " has left the building" << std::endl;
}

void	ScavTrap::attack( const std::string& target )
{
	if (this->_energyPoints && this->_hitPoints)	
	{
		this->_energyPoints--;
		std::cout << "BAM!!! " << this->_name << " attacks " << target << " causing " 
			<< this->_attackDamage << " points of damage and making " << target
			<< " shake and cower in fear! " << std::endl;
	}
	else if(!_energyPoints && _hitPoints)
		std::cout << this->_name << " does not enough energy points to attack.  Boohoo!" << std::endl;
	else
		std::cout << this->_name << " does not have any hit points, they lose! Sniff!" << std::endl;
}

void	ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}