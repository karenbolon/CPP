/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:09:37 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/05 16:19:12 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// HumanA requires a Weapon reference passed at the 
//time of creation. This ensures that HumanA always 
//has a weapon and cannot exist without one.
//
// HumanB is designed to allow the weapon to be set 
//or changed later.  This means HumanB can exist 
//without a weapon initially and has more flexibility.
int main()
{
	Weapon	club = Weapon("crude spiked club");
	HumanA	bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	std::cout << std::endl;

	Weapon	club1 = Weapon("crude spiked club");
	HumanB	jim("Jim");
	jim.setWeapon(club1);
	jim.attack();
	club1.setType("some other type of club");
	jim.attack();
	std::cout << std::endl;
	return 0;
}
