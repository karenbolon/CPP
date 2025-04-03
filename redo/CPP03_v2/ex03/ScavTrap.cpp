#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap(){
	_Hit_points = 100;
	_Energy_points = 50;
	_Attack_damage = 20;
	std::cout << "ScavTrap: " << this->_Name << "default constructor" << std::endl; 
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_Hit_points = 100;
	_Energy_points = 50;
	_Attack_damage = 20;
	std::cout << "ScavTrap: " << this->_Name << "constructor" << std::endl; 
}

ScavTrap::ScavTrap(ScavTrap const & copy) : ClapTrap(copy) {
	std::cout << "ScavTrap copy constructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & src) {
	if (this != &src)
	{
		static_cast<ClapTrap&>(*this) = src;
		std::cout << "ScavTrap assignment overload called" << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << this->_Name <<": ScavTrap deconstructor" << std::endl;
}

void	ScavTrap::attack(const std::string & target) {
	if (this->_Energy_points && this->_Hit_points) {
		this->_Energy_points--;
		std::cout << "ScavTrap: " << this->_Name << " attacks 🤼‍♀️" << target << " causing "
			<< this->_Attack_damage << " points of damage!" << std::endl;
	}
	else
		std::cout << "Not enough Energy Points or Hit Points to attack" << std::endl;
	std::cout << "ScavTrap: " << this->_Name << " attacks " << target << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap:" << this->_Name << " is now in Gate Keeper mode 🥅" << std::endl;
}


