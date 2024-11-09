/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:26:57 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/09 17:32:47 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	Venus = ScavTrap("Venus");
	ScavTrap	Serena = ScavTrap("Serena");

	Venus.attack("Serena");
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

}
