/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:26:57 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/11 15:46:41 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
