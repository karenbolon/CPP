/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:09:37 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/04 14:20:40 by kbolon           ###   ########.fr       */
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
	std::cout << "[ DEBUG ]" << std::endl
		<< "I love having extra bacon for my" << std::endl
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< "I really do!" << std::endl << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl
		<< "I cannot believe adding extra bacon costs more money."
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t"
		<< "be asking for more!" << std::endl << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free."
		<< "I’ve been coming for years whereas you started working here since"
		<< "last month." << std::endl << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl
		<< "This is unacceptable! I want to speak to the manager"
		<< " now." << std::endl << std::endl;
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
