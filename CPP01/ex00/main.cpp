/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:09:37 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/05 16:04:16 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	zombie1("Petunia");
	zombie1.announce();
	std::cout << std::endl;

	Zombie *zombie2 = newZombie("Pascal");
	zombie2->announce();
	delete zombie2;
	std::cout << std::endl;

	randomChump("Buddy");
	std::cout << std::endl;

	return (0);
}