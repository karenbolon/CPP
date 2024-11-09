/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:18:23 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/09 17:52:12 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
public:
	ScavTrap();
	ScavTrap( std::string Name );
	ScavTrap( const ScavTrap& copy );

	~ScavTrap();

	ScavTrap &operator=( const ScavTrap &src );
	
	void	attack( const std::string& target );
	void	guardGate();
};