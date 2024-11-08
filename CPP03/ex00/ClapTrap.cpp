/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:49:44 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/08 17:39:22 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("no_name"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	_name = copy._name;
	_hitPoints = copy._hitPoints;
	_energyPoints = copy._energyPoints;
	_attackDamage = copy._attackDamage;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &src ){

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
	return (_name);
}

unsigned int	ClapTrap::getHitPoints() const{
	return (_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints() const{
	return (_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage() const{
	return (_attackDamage);
}

ClapTrap::~ClapTrap(){}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints && _hitPoints)
	{
		_energyPoints--;
		std::cout << _name << " attacks " << target << " causing " 
			<< _attackDamage << " points of damage!" << std::endl;
	}
	else if (!_energyPoints && _hitPoints)
		std::cout << _name << "does not enough energy points to attack" << std::endl;
	else
		std::cout << _name << " is dead" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints >= amount)
	{
		_hitPoints -= amount;
		std::cout << _name << " loses " << amount << " hit points!" << std::endl;
	}
	else
	{
		_hitPoints = 0;
		std::cout << _name << " is dead" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints && _hitPoints)
	{
		_energyPoints--;
		_hitPoints = amount;
		std::cout << _name << " repairs itself, it gets " << amount
			<< " hit points back" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << "does not enough energy points to repair itself" << std::endl;
}