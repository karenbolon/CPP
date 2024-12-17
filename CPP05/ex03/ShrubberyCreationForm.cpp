/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:52:09 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/17 15:35:16 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <string>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm( "ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& src ) :
	AForm( src ) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm &src ) {
	std::cout << "ShrubberyCreationForm  assignment operator called" << std::endl;
	if (this != &src) {
		AForm::operator = (src);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery Creation Form deconstructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor ) const {
	if (isExecutable(executor) == true) {
		std::cout << "Form is signed and executable" << std::endl;
		std::string	fileName = getTarget() + "_shrubbery";
		std::ofstream	myfile(fileName.c_str());
		if (!myfile.is_open()) {
			std::cout << "Failed to open file ";
			throw std::ios_base::failure("Failed to create shrubbery file");
		}
		myfile << "          &&& &&  & &&" << std::endl 
				<< "      && &&&&|& && @ &&" << std::endl
				<< "      &\\ &/&&|&&\\&&/&&" << std::endl 
				<< "   && &&\\/@|&|/& \\/ && &&&" << std::endl
				<< "  && &&& \\ &&|& &&/&&&&& &&" << std::endl 
				<< "&&   && & &\\&|   /& & & &&& &&" << std::endl 
				<< " &&& && &&&&\\|& / &&  &   &" << std::endl 
				<< "     &@      |||  &      @"<< std::endl
				<< "             |||" << std::endl 
				<< "             |||" << std::endl 
				<< "             |||" << std::endl
				<< "           ~~~~~~~" << std::endl;
		myfile.close();
	}
	else {
		throw GradeTooLowException();
	}
}