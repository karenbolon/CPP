#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap() : ClapTrap() {
	_Hit_points = 100;
	_Energy_points = 100;
	_Attack_damage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name) {
		_Hit_points = 100;
		_Energy_points = 100;
		_Attack_damage = 30;
		std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap & src) : ClapTrap(src) {
	std::cout << "FragTrap copy constructor" << std::endl;
}


FragTrap::~FragTrap() {
	std::cout << "FragTrap deconstructor called" << std::endl;
}


FragTrap& FragTrap::operator=(FragTrap const & src) {
	if (this != &src)
	{
		static_cast<ClapTrap&>(*this) = src;
		std::cout << "FragTrap assignment overload called" << std::endl;
	}
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	std::cout << "Give me a high 5!!! 👏  Rock on! 🤙" << std::endl;
}
