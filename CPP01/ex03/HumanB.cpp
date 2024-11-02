/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:10:05 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/02 16:53:05 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _weapon(NULL)
{
	this->_name = name;
	std::cout << "HumanB(" << name << ") was created with no weapon" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << this->_name << " destroyed" << std::endl;
}

void HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their "
		<< this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}