#include "ClapTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap	Venus = ClapTrap("Venus");
	ClapTrap	Serena = ClapTrap("Serena");
	ClapTrap	Somebody;

	std::cout << std::endl;
	Venus.attack("Serena");
	Serena.takeDamage(4);
	Serena.takeDamage(4);
	std::cout << Serena.getName() << " has energy points " << Serena.getEnergyPoints()
		<< " and hit points " << Serena.getHitPoints() << std::endl << std::endl;
	
	Somebody.beRepaired(10);
	std::cout << Somebody.getName() << " has energy points " << Somebody.getEnergyPoints()
		<< " and hit points " << Somebody.getHitPoints() << std::endl << std::endl;
	
	Serena.beRepaired(4);
	std::cout << Serena.getName() << " has energy points " << Serena.getEnergyPoints()
		<< " and hit points " << Serena.getHitPoints() << std::endl << std::endl;

	Serena.attack("Venus");
	Venus.takeDamage(10);
	std::cout << Venus.getName() << " has energy points " << Venus.getEnergyPoints()
		<< " and hit points " << Venus.getHitPoints() << std::endl << std::endl;
	Venus.attack("Serena");
	std::cout << std::endl;

}