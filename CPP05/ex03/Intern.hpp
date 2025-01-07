/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:40:03 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/18 16:57:40 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//#include <string>
//#include <iostream>
#include <map>
//#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
private:
	static AForm*	makeShrubberyCreationForm(const std::string& target);
	static AForm*	makeRobotomyRequestForm(const std::string& target);
	static AForm*	makePresidentialPardonForm(const std::string& target);

	typedef AForm*	(*makeFormFunction)(const std::string&);

	std::map<std::string, makeFormFunction> makeList;

public:
	Intern();
	Intern(const Intern& src);
	Intern & operator=(const Intern& src);
	~Intern();
	AForm*	makeForm(const std::string& name, const std::string& target);
	
	//Exception Classes
	class	FormNotFound : public std::exception {
	public:
		const char* what() const throw();
	};
};

