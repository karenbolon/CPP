/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:41:48 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/18 17:08:50 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	makeList.insert(std::make_pair("presidential pardon", &makePresidentialPardonForm));
	makeList.insert(std::make_pair("robotomy request", &makeRobotomyRequestForm));
	makeList.insert(std::make_pair("shrubbery creation", &makeShrubberyCreationForm));
}

Intern::Intern(const Intern & src) {
	(void)src;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern & Intern::operator=(const Intern & src) {
	(void)src;
	return (*this);
}

Intern::~Intern(){}

AForm*	Intern::makeShrubberyCreationForm(const std::string& target){
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomyRequestForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}
AForm*	Intern::makePresidentialPardonForm(const std::string& target){
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target) {
	std::map<std::string, makeFormFunction>::const_iterator it = makeList.find(name);
	if (it != makeList.end())
		return (it->second(target));
	else{
		std::cerr << "Error: " << name << " form not found." << std::endl;
		throw(FormNotFound());
	}
	
}

const char* Intern::FormNotFound::what() const throw() {
	return("Error: Form not found.");
};






