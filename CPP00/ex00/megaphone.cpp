/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:43:42 by kbolon            #+#    #+#             */
/*   Updated: 2024/08/05 17:44:28 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		av += 1;
		while (*av)
		{
			char	*str = *av;	
			while (*str)
			{
				if (*str >= 'a' && *str <= 'z')
					*str -= 32;
				std::cout << *str;
				str++;
			}
			av++;
			std::cout << ' ';
		}
		std::cout << '\n';
	}
	return (0);
}
