/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:43:42 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/05 14:46:26 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		av += 1;
		while (*av)
		{
			std::string	str = *av;	
			for (size_t i = 0; i < str.size(); i++)
			{
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] -= 32;
				std::cout << str[i];
			}
			av++;
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
	return (0);
}
