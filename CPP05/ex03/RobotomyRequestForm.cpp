/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:52:09 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/17 15:29:09 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm( "RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& src ) :
	AForm( src ) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm &src ) {
	std::cout << "RobotomyRequestForm  assignment operator called" << std::endl;
	if (this != &src) {
		AForm::operator = (src);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Shrubbery Creation Form deconstructor called" << std::endl;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor ) const {
//	seed only once
	static bool seeded = false;
	if (!seeded) {
		std::srand(std::time(0));
		seeded = true;	
	}
	if (isExecutable(executor)) {
		int	random_number = (std::rand() % 2);
		if (random_number == 0) {
			std::cout << "drilling noises vvvv" << std::endl;
			std::cout << getTarget() << " has been robotomized" << std::endl;
		}
		else {
			std::cout << "Robotomy failed" << std::endl;
		}
	}
	else {
		throw GradeTooLowException();
	}
}