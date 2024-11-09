/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:03:30 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/09 18:26:20 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap{
	private:
		std::string	_name;
	
	public:
		DiamondTrap();
		DiamondTrap( std::string Name );
		DiamondTrap( const DiamondTrap& copy );

		~DiamondTrap();

		DiamondTrap &operator=( const DiamondTrap &src );

		using	ScavTrap::attack;
		void	whoAmI();
};