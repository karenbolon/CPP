/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:09:37 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/03 17:22:11 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my"
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money."
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t"
		<< "be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free."
		<< "I’ve been coming for years whereas you started working here since"
		<< "last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager"
		<< " now." << std::endl;
}

void	Harl::complain(std::string level)
{
	functionList list[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};
	for (int i = 0; i < 4; i++)
	{
		if (list[i].level == level)
		{
			(this->*(list[i].function))();
			return ;
		}
	}
	std::cout << level << " is not a valid level" << std::endl;
}
