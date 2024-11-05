/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:00:20 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/05 15:39:13 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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

void	printPhonebook(PhoneBook book)
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
	std::cout << "INPUT IS NOT AN ACCEPTED DIGIT, PLEASE TRY AGAIN\n";
	return (0);
}

void	printContact(PhoneBook phoneBook, int i)
{
	if (i < 0 || i > 8 || phoneBook.people[i].index == -1)
	{
		std::cout << "PLEASE ENTER A VALID INDEX NUMBER\n\n";
		return ;
	}
	std::string	indexString;
	indexString = integerToString(phoneBook.people[i].index);
	std::cout << "INDEX:         " << indexString  << std::endl;
	std::cout << "FIRST NAME:    " << phoneBook.people[i].getFirstName() << std::endl;
	std::cout << "LAST NAME:     " << phoneBook.people[i].getLastName() << std::endl;
	std::cout << "NICKNAME:      " << phoneBook.people[i].getNickName() << std::endl;
	std::cout << "PHONENUMBER:   " << phoneBook.people[i].getPhoneNumber() << std::endl;
	std::cout << "DARKEST SECRET:" << phoneBook.people[i].getDarkestSecret() << std::endl;
	std::cout << std::endl << std::endl;
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

std::string	checkEmptyString(std::string input)
{
	while (input.empty())
	{
		std::cout << "EMPTY SPACE UNACCEPTED. TRY AGAIN:" <<std::endl <<std::endl;
		std::getline(std::cin, input);
	}
	return (input);
}

//std::cin takes input from keyboard and stores the first word in 
//my input variable but if there is more than one word entered 
//only the first word is stored in input and the rest is left
//in a buffer.  I used cin.ignore to ignore the remainder of what
//was entered.
void	addContacts(PhoneBook &phoneBook, int i)
{
	std::string	input;

	std::cin.ignore(1000, '\n');
	system("clear");
	phoneBook.people[i].index = i + 1;
	std::cout << "ENTER FIRST NAME:" << std::endl;
	std::getline(std::cin, input);
	input = checkEmptyString(input);
	phoneBook.people[i].setFirstName(makeUpper(input));
	system("clear");

	std::cout << "ENTER LAST NAME:" <<std::endl;
	std::getline(std::cin, input);
	checkEmptyString(input);
	phoneBook.people[i].setLastName(makeUpper(input));
	system("clear");

	std::cout << "ENTER NICKNAME:\n";
	std::getline(std::cin, input);
	input = checkEmptyString(input);
	phoneBook.people[i].setNickName(makeUpper(input));
	system("clear");

	std::cout << "ENTER PHONENUMBER:\n";
	std::getline(std::cin, input);
	input = checkEmptyString(input);
	phoneBook.people[i].setPhoneNumber(makeUpper(input));
	system("clear");

	std::cout << "ENTER DARKEST SECRET:\n";
	std::getline(std::cin, input);
	input = checkEmptyString(input);
	phoneBook.people[i].setDarkestSecret(makeUpper(input));
	system("clear");
}

void	displayMenu()
{
	std::cout << "OPTIONS:\n" << "1 ADD\n"  << "2 SEARCH\n" << "3 EXIT\n\n";
	std::cout << "SELECT NUMBER OR WORD:\n";
}
