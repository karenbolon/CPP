/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:48:41 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/05 15:12:47 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;
	int			i;
	std::string	input;

	system("clear");
	i = 0;
	while (1)
	{
		displayMenu();
		std::cin >> input;
		if (std::cin.eof())
			break;
		input = makeUpper(input);
		if (input == "ADD" || input == "1")
		{
			if (i < 8)
			{
				addContacts(phoneBook, i);
				i++;
			}
			else
			{
				i = 0;
				addContacts(phoneBook, i);
				i++;
			}
		}
		else if (input == "SEARCH" || input == "2")
		{
			int		index;
			system("clear");
			printPhonebook(phoneBook);
			std::cout << std::endl << "ENTER CONTACT INDEX NUMBER" << std::endl;
			std::cin >> input;
			if (input.length() > 1)
			{
				std::cout << std::endl << "ENTER CONTACT INDEX NUMBER BETWEEN 1 AND 8:" 
					<<std::endl <<std::endl;
				std::cin >> input;
			}
			index = charToInteger(input[0]) - 1;
			system("clear");
			if (index > 0 && index < 8)
				printContact(phoneBook, index);
			else
				std::cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND 8" 
					<< std::endl <<std::endl;
		}
		else if (input == "EXIT" || input == "3")
			exit(0);
		else
			std::cout << "FALSE ENTRY" <<std::endl <<std::endl;
	}
	return (0);
}
