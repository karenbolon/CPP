/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:10:05 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/02 16:44:38 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//Syntax: : _name(name), _weapon(weapon) means that the member 
//variables _name and _weapon are being initialized with the 
//values passed as parameters (name and weapon).
HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout << "HumanA(" << name << ") was created with " 
		<< weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << this->_name << " destroyed" << std::endl;
}

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their "
		<< this->_weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon weapon)
{
	this->_weapon = weapon;
}
