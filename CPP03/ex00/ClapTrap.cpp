/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:49:44 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/11 16:01:16 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("no_name"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
		std::cout << "Claptrap " << this->_name << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
		std::cout << "Claptrap " << this->_name << " constructor called" << std::endl;
}

/*initialises a new ClapTrap instance and copies the attribute values
from another ClapTrap instance called <copy>.*/
ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "Claptrap " << this->_name << " copy constructor called" << std::endl;
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
}

/* assigns one ClapTrap instance to another (both must be initialised to use 
this function).
*/
ClapTrap& ClapTrap::operator=( const ClapTrap &src ){
	
	std::cout << "Claptrap " << this->_name << " assignment operator overload called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

std::string		ClapTrap::getName() const{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints() const{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints() const{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage() const{
	return (this->_attackDamage);
}

//deconstructor
ClapTrap::~ClapTrap(){
	std::cout << "Claptrap " << this->_name << " deconstructor called" << std::endl;
}

//reduces energy points by 1 if able to attack (ClapTrap has energy and hitpoints)
void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints && this->_hitPoints)
	{
		this->_energyPoints--;
		std::cout << this->_name << " attacks " << target << " causing " 
			<< this->_attackDamage << " points of damage!" << std::endl;
	}
	else if(!_energyPoints && _hitPoints)
		std::cout << this->_name << "does not enough energy points to attack" << std::endl;
	else
		std::cout << this->_name << " does not have any hit points, they lose!" << std::endl;
}

//reduces hitpoints by the amount (as long as hitpoints > 0)
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints >= amount)
	{
		this->_hitPoints -= amount;
		std::cout << this->_name << " loses " << amount << " hit points!" << std::endl;
	}
	else
	{
		this->_hitPoints = 0;
		std::cout << this->_name << " has no more hit points left" << std::endl;
	}
}

//repairs ClapTrap at cost of 1 energy point and increases hitPoints to
//specified amount
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints && this->_hitPoints)
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << this->_name << " repairs itself, it gets " << amount
			<< " hit points back" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << "does not enough energy points to repair itself" << std::endl;
}