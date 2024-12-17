/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:52:09 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/10 13:40:47 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <string>


PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm( "PresidentialPardonForm", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& src ) :
	AForm( src ) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm &src ) {
	std::cout << "PresidentialPardonForm  assignment operator called" << std::endl;
	if (this != &src) {
		AForm::operator = (src);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Shrubbery Creation Form deconstructor called" << std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor ) const {
	if (isExecutable(executor)) {
		std::cout << getTarget() << " is pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else {
		throw GradeTooLowException();
	}
}