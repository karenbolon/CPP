/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:14:33 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/18 17:19:57 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat*	workforce[3] = {NULL, NULL, NULL};
	AForm*		forms[4] = {NULL, NULL, NULL, NULL};
	Intern someRandomIntern;


	try {
		forms[0] = someRandomIntern.makeForm("robotomy request", "Bender");
		forms[1] = someRandomIntern.makeForm("shrubbery creation", "Garden");
		forms[2] = someRandomIntern.makeForm("robotomy request", "Robot");
		forms[3] = someRandomIntern.makeForm("presidential pardon", "Alice");

	} catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		workforce[0] = new Bureaucrat("Tom", 1);
		workforce[1] = new Bureaucrat("Dick", 24);
		workforce[2] = new Bureaucrat("Harry", 144);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try {
		workforce[0]->signForm(*forms[0]);
		workforce[1]->signForm(*forms[1]);
//		workforce[2]->signForm(*forms[2]);//grade to low
		workforce[1]->signForm(*forms[2]);
		workforce[0]->signForm(*forms[3]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		workforce[0]->executeForm(*forms[0]);
		workforce[1]->executeForm(*forms[1]);
		workforce[2]->executeForm(*forms[2]);
		workforce[0]->executeForm(*forms[3]);
	}
	catch (const std::exception& e) {
		std::cerr << "Error for " << ": " << e.what() << std::endl;
	}
	std::cout << std::endl;
	for (size_t i = 0; i < 3; i++) {
		if (workforce[i])
			delete workforce[i];
	}
	std::cout << std::endl;
	for (size_t i = 0; i < 4; i++) {
		if (forms[i])
			delete forms[i];
	}
}
