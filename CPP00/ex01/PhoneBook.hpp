/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:59:58 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/05 15:29:52 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdlib>

class	Contact{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	
public:
	int			index;

	Contact() : index(-1) {}

	//setters for private attributes
	void	setFirstName(std::string s) {firstName = s;}
	void	setLastName(std::string s) {lastName = s;}
	void	setNickName(std::string s) {nickName = s;}
	void	setPhoneNumber(std::string s) {phoneNumber = s;}
	void	setDarkestSecret(std::string s) {darkestSecret = s;}

	//getters for private attributes
	std::string	getFirstName() {return (firstName);}
	std::string	getLastName() {return (lastName);}
	std::string	getNickName() {return (nickName);}
	std::string	getPhoneNumber() {return (phoneNumber);}
	std::string	getDarkestSecret() {return (darkestSecret);}
};

class PhoneBook
{
	public:
		Contact people[8];
};

int			charToInteger(char c);
void		printString(std::string str);
void		printPhonebook(PhoneBook book);
void		printContact(PhoneBook phoneBook, int i);
void		displayMenu();
void		addContacts(PhoneBook &phoneBook, int i);
std::string	integerToString(int n);
std::string	makeUpper(std::string input);
std::string	checkForDigits(std::string input);
std::string	checkEmptyString(std::string string);

#endif
