/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:38:46 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/09 17:51:38 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"


class FragTrap : public ClapTrap{
public:
	FragTrap();
	FragTrap( std::string Name );
	FragTrap( const FragTrap& copy );

	~FragTrap();

	FragTrap &operator=( const FragTrap &src );

 	void highFivesGuys( void );

};