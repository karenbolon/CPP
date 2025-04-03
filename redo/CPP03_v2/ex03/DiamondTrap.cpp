#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
	this->_Name = "No name";
	ClapTrap::_Name = _Name = _Name + "_clap_name";
	this->_Hit_points = FragTrap::_Hit_points;
	this->_Energy_points = ScavTrap::_Energy_points;
	this->_Attack_damage = FragTrap::_Attack_damage;
	std::cout << "DiamondTrap " << this->_Name << " default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name), FragTrap(Name), ScavTrap(Name) {
	ClapTrap::_Name = (Name + "_clap_name");
	this->_Name = Name;
	this->_Hit_points = FragTrap::_Hit_points;
	this->_Energy_points = ScavTrap::_Energy_points;
	this->_Attack_damage = FragTrap::_Attack_damage;

	std::cout << "DiamondTrap " << this->_Name << " parameter constructor called" << std::endl;

}

void DiamondTrap::attack(const std::string & target) {
	ScavTrap::attack(target);
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : FragTrap(copy), ScavTrap(copy){
	std::cout << "DiamondTrap " << this->_Name << " copy constructor called" << std::endl;
}


DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap deconstructor called" << std::endl;
}
  
	 
DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src) {
	if (this != &src)
	{
		_Name = src._Name;
		_Hit_points = src._Hit_points;
		_Energy_points = src._Energy_points;
		_Attack_damage = src._Attack_damage;
		std::cout << "DiamondTrap " << this->_Name << " assignment operator called" << std::endl;
	}
	return (*this);
}

void	DiamondTrap::whoAmI() {
	std::cout << "I have 2 names: 1) " << this->_Name 
		<< " and 2) " << ClapTrap::_Name << std::endl;
}
  
