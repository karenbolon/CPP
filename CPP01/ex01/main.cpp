/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:09:37 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/01 16:48:06 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int	i = 5;
	Zombie *swarmOfZombies = zombieHorde(i, "Stumble-ina");
	for (int j = 0; j < i; j++)
	{
		
		swarmOfZombies[j].announce();
	}
	delete [] swarmOfZombies;
	return (0);
}
