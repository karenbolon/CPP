/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:26:57 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/11 16:24:04 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*When deconstructed, ScavTrap is fully deconstructed before moving
to the ClapTrap deconstructor. This ensures all resources are released.

This is critical because ScavTrap might depend on resources/functionality 
set up by ClapTrap. If ClapTrap were destroyed first, ScavTrap would be left 
invalid/incomplete during its own destruction, leading to potential errors.
*/
int	main()
{
	ScavTrap	Venus = ScavTrap("Venus");
	ScavTrap	Serena = ScavTrap("Serena");
	ScavTrap	Somebody;

	std::cout << std::endl;
//	std::cout << Serena.getName() << " has energy points " << Serena.getEnergyPoints()
//		<< " and hit points " << Serena.getHitPoints() << std::endl << std::endl;
	Venus.attack("Somebody");
	std::cout << Somebody.getName() << " has energy points " << Somebody.getEnergyPoints()
		<< " and hit points " << Somebody.getHitPoints() << std::endl << std::endl;
	
	Venus.attack("Serena");
	Somebody.takeDamage(40);
	Serena.takeDamage(40);
	Serena.takeDamage(40);
	std::cout << Serena.getName() << " has energy points " << Serena.getEnergyPoints()
		<< " and hit points " << Serena.getHitPoints() << std::endl << std::endl;
	
	Serena.beRepaired(40);
	std::cout << Serena.getName() << " has energy points " << Serena.getEnergyPoints()
		<< " and hit points " << Serena.getHitPoints() << std::endl << std::endl;

	Serena.attack("Venus");
	Venus.takeDamage(100);
	std::cout << Venus.getName() << " has energy points " << Venus.getEnergyPoints()
		<< " and hit points " << Venus.getHitPoints() << std::endl << std::endl;
	Venus.attack("Serena");
	Serena.guardGate();
	std::cout << std::endl;

}
