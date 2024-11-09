/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:26:57 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/09 18:36:50 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	Venus = DiamondTrap("Venus");
	std::cout << std::endl;
	
	DiamondTrap	Serena = DiamondTrap("Serena");
	std::cout << std::endl;

	Venus.attack("Serena");
	Serena.takeDamage(40);
	Serena.takeDamage(40);
	std::cout << Serena.getName() << " has energy points " << Serena.getEnergyPoints()
		<< " and hit points " << Serena.getHitPoints() << std::endl << std::endl;
	
	Serena.beRepaired(40);
	std::cout << Serena.getName() << " has energy points " << Serena.getEnergyPoints()
		<< " and hit points " << Serena.getHitPoints() << std::endl << std::endl;

	Serena.attack("Venus");
	Venus.highFivesGuys();
	
	std::cout << std::endl;
	Venus.takeDamage(100);
	std::cout << Venus.getName() << " has energy points " << Venus.getEnergyPoints()
		<< " and hit points " << Venus.getHitPoints() << std::endl << std::endl;
	Venus.attack("Serena");
	std::cout << std::endl;
	
	Serena.guardGate();
	std::cout << std::endl;
	
	Serena.whoAmI();
	std::cout << std::endl;

}
