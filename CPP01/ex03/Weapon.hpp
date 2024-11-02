/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:09:52 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/02 16:48:28 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string	_type;
		Weapon	*_weapon;
	public:
		Weapon(std::string	type);
		~Weapon(void);
		const std::string& getType(void);
		void setType(const std::string& newType);
};


#endif
