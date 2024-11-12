/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:55:13 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/11 15:59:16 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

/*
we need to change the private attributes to protected so that any 
inherited classes can access these attributes.  If we left it private,
ScavTrap couldn't use them (only ClapTrap) and the would have to rely on public 
or protected member functions to manipulate these values.

protected attributes make them accessible to any derived class (ClapTrap AND 
ScavTrap etc). This can be seen when the ScavTrap in instatiated as the energy points,
hit points, and attack damage are different values to the ClapTrap values.
*/

class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string Name);
	ClapTrap(const ClapTrap& copy);
	
	~ClapTrap();

	ClapTrap &operator=( const ClapTrap &src );
	
	std::string		getName() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergyPoints() const;
	unsigned int	getAttackDamage() const;
	
	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

};



