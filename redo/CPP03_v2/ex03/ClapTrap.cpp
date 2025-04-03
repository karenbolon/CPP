#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor called" << std::endl;
	_Name = "No Name";
	_Hit_points = 10;
	_Energy_points = 10;
	_Attack_damage = 0;
}

ClapTrap::ClapTrap(std::string Name) : _Name(Name) {
	std::cout << "ClapTrap parametric constructor called" << std::endl;
	_Hit_points = 10;
	_Energy_points = 10;
	_Attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap const & copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->_Name = copy._Name;
	this->_Hit_points = copy._Hit_points;
	this->_Energy_points = copy._Energy_points;
	this->_Attack_damage = copy._Attack_damage;	
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap deconstructor called" << std::endl;
}

/* assigns one ClapTrap instance to another (both must be initialised to use 
this function).
*/
ClapTrap& ClapTrap::operator=( const ClapTrap &src ) {
	std::cout << "ClapTrap " << this->_Name << " assignment operator overload called" << std::endl;
	if (this != &src)
	{
		this->_Name = src._Name;
		this->_Hit_points = src._Hit_points;
		this->_Energy_points = src._Energy_points;
		this->_Attack_damage = src._Attack_damage;
	}
	return (*this);
}
	  
void	ClapTrap::attack(const std::string & target) {
	if (this->_Energy_points && this->_Hit_points) {
		this->_Energy_points--;
		std::cout << this->_Name << " attacks " << target << " causing "
			<< this->_Attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "Not enough Energy Points or Hit Points to attack" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	this->_Hit_points -= amount;
	std::cout << this->_Name << " has received " << amount << " points of damage " << std::endl;
	if (!this->_Hit_points)
		std::cout << this->_Name << " is dead" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_Energy_points) {
		this->_Energy_points--;
		this->_Hit_points += amount;
		std::cout << this->_Name << " has been repaired and has " << amount << " hit points added ";
	}
}

std::string	ClapTrap::getName() const {
	return this->_Name;
}

int	ClapTrap::getHitPoints() const {
	return this->_Hit_points;
}

int	ClapTrap::getEnergyPoints() const {
	return this->_Energy_points;
}

int	ClapTrap::getAttackDamage() const {
	return this->_Attack_damage;
}
