/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:10:05 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/02 16:16:05 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) 
{
	this->_type = type;
}

Weapon::~Weapon(void)
{
}
const std::string& Weapon::getType(void)
{
	return (this->_type);
}

void Weapon::setType(const std::string& newType)
{
	this->_type = newType;
}

