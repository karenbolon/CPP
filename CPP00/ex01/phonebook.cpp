/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:00:20 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/04 13:14:23 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	printString(std::string str)
{
	if (str.size() > 10)
	{
		str.resize(9);
		std::cout << str;
		std::cout << ".";
	}
	else
		std::cout << std::setw(10) << std::right << str;
}

std::string	integerToString(int n)
{
	std::stringstream	str;

	str << n;
	return (str.str());
}

void	printPhonebook(phoneBook book)
{
	int num = 0;
	int	bookLength = 8;
	std::string	indexString;
	std::cout << "            MY AWESOME PHONEBOOK\n";
	std::cout << "---------------------------------------------\n";
	std::cout << "|     INDEX|FIRST NAME| LAST NAME| NICK NAME|\n";
	std::cout << "|-------------------------------------------|\n";
	while (num < bookLength && book.people[num].index != -1)
	{
		std::cout << "|";
		indexString = integerToString(book.people[num].index);
		printString(indexString);
		std::cout << "|";
		printString(book.people[num].getFirstName());
		std::cout << "|";
		printString(book.people[num].getLastName());
		std::cout << "|";
		printString(book.people[num].getNickName());
		std::cout << "|\n";
		num++;
	}
	std::cout << "---------------------------------------------\n";
}

int		charToInteger(char c)
{
	if (c >= '1' && c <= '9')
		return (c - '0');
	std::cout << "INPUT IS NOT A DIGIT, PLEASE TRY AGAIN\n";
	return (0);
}

void	printContact(phoneBook phoneBook, int i)
{
	if (i < 0 || i > 8 || phoneBook.people[i].index == -1)
	{
		std::cout << "PLEASE ENTER A VALID INDEX NUMBER\n\n";
		return ;
	}
	std::string	indexString;
	std::cout << "INDEX:         ";
	indexString = integerToString(phoneBook.people[i].index);
	printString(indexString);
	std::cout << "\nFIRST NAME:    ";
	printString(phoneBook.people[i].getFirstName());
	std::cout << "\nLAST NAME:     ";
	printString(phoneBook.people[i].getLastName());
	std::cout << "\nNICKNAME:      ";
	printString(phoneBook.people[i].getNickName());
	std::cout << "\nPHONENUMBER:   ";
	printString(phoneBook.people[i].getPhoneNumber());
	std::cout << "\nDARKEST SECRET:";
	printString(phoneBook.people[i].getDarkestSecret());
	std::cout << "\n\n";
}

std::string	makeUpper(std::string input)
{
	size_t	i;

	i = 0;
	while (i < input.length())
	{
		if (input[i] >= 'a' && input[i] <= 'z')
			input[i] -= 32;
		i++;
	}
	return (input);
}

//std::cin takes input from keyboard and stores the first word in 
//my input variable but if there is more than one word entered 
//only the first word is stored in input and the rest is left
//in a buffer.  I used cin.ignore to ignore the remainder of what
//was entered.
void	addContacts(phoneBook &phoneBook, int i)
{
	std::string	input;

	std::cin.ignore(1000, '\n');
	system("clear");
	phoneBook.people[i].index = i + 1;
	std::cout << "ENTER FIRST NAME:\n";
	std::getline(std::cin, input);
	phoneBook.people[i].setFirstName(makeUpper(input));
	system("clear");

	std::cout << "ENTER LAST NAME:\n";
	std::getline(std::cin, input);
	phoneBook.people[i].setLastName(makeUpper(input));
	system("clear");

	std::cout << "ENTER NICKNAME:\n";
	std::getline(std::cin, input);
	phoneBook.people[i].setNickName(makeUpper(input));
	system("clear");

	std::cout << "ENTER PHONENUMBER:\n";
	std::getline(std::cin, input);
	phoneBook.people[i].setPhoneNumber(makeUpper(input));
	system("clear");

	std::cout << "ENTER DARKEST SECRET:\n";
	std::getline(std::cin, input);
	phoneBook.people[i].setDarkestSecret(makeUpper(input));
	system("clear");
}

void	displayMenu()
{
	std::cout << "OPTIONS:\n" << "1 ADD\n"  << "2 SEARCH\n" << "3 EXIT\n\n";
	std::cout << "SELECT NUMBER OR WORD:\n";
}

int	main()
{
	phoneBook	phoneBook;
	int			i;
	std::string	input;

	system("clear");
	i = 0;
	while (1)
	{
		displayMenu();
		std::cin >> input;
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
			std::cout << "\nENTER CONTACT INDEX NUMBER\n";
			std::cin >> input;
			if (input.length() > 1)
			{
				std::cout << "\nENTER CONTACT INDEX NUMBER BETWEEN 1 AND 8:\n";
				std::cin >> input;
			}
			index = charToInteger(input[0]) - 1;
			system("clear");
			if (index >= 0 && index < 8)
				printContact(phoneBook, index);
			else
				std::cout << "PLEASE ENTER A NUMBER BETWEEN 1 AND 8\n";
		}
		else if (input == "EXIT" || input == "3")
			exit(0);
		else
			std::cout << "FALSE ENTRY\n\n";
	}
	return (0);
}
