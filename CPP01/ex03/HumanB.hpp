/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:09:52 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/02 16:51:52 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon	*_weapon;

	public:
		HumanB(std::string name);
		~HumanB(void);
		void	attack(void);
		void	setWeapon(Weapon &weapon);
};

