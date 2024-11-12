/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:49:44 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/11 16:04:45 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("no_name"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "ClapTrap " << this->_name << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "Claptrap " << this->_name << " copy constructor called" << std::endl;
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &src ){
	std::cout << "Claptrap " << this->_name << " assignment operator called" << std::endl;
	if (this != &src)
	{
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
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

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << this->_name << " deconstructor called" << std::endl;
}

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