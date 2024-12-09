/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:52:09 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/09 16:54:14 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm( "shrubberyCreationForm", 145, 137, target) {}

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
	if (isExecutable(executor)) {
		std::ofstream	myfile(getTarget() + "_shrubbery");
		if (!myfile.is_open()) {
			throw std::ios_base::failure("Failed to create shrubbery file");
		}
		myfile << "          &&& &&  & &&" << std::endl 
				<< "      && &\\/&\\|& ()|/ @, &&" << std::endl
				<< "      &\\/(/&/&||/& /_/)_&/_&" << std::endl 
				<< "   &() &\\/&|()|/&\\/ '% & () &" << std::endl
				<< "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl 
				<< "&&   && & &| &| /& & % ()& /&&" << std::endl 
				<< " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl 
				<< "     &&      |||       &      &"<< std::endl
				<< "             |||" << std::endl 
				<< "             |||" << std::endl 
				<< "             |||" << std::endl
				<< "       , -=-~  .-^- _" << std::endl;
		myfile.close();
	}
	else {
		throw GradeTooLowException();
	}
}