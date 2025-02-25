/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:09:37 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/04 14:19:40 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	convertToNumber(std::string level)
{
	std::string list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (list[i] == level)
		{
			return (i);
		}
	}
	return (-1);
}

void	convertInput(std::string string)
{
	Harl	Harl1;
	int		number = convertToNumber(string);
	
	switch (number)
	{
		case 0:
			Harl1.complain("DEBUG");
		case 1:
			Harl1.complain("INFO");
		case 2:
			Harl1.complain("WARNING");
		case 3:
			Harl1.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
			<< std::endl;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		convertInput(av[1]);
	}
	else
	{
		std::cout << "usage: program word (DEBUG, ERROR, INFO, WARNING, ETC)" << std::endl;
		return (1);
	}
	return (0);
}
