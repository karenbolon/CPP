/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:14:33 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/17 15:37:33 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>


int	main( void ) {
	Bureaucrat*	workforce[3] = {NULL, NULL, NULL};
	AForm*		forms[4] = {NULL, NULL, NULL, NULL};

	try {
		workforce[0] = new Bureaucrat("Tom", 1);
		workforce[1] = new Bureaucrat("Dick", 24);
		workforce[2] = new Bureaucrat("Harry", 144);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		std::cout << std::endl;
		forms[0] = new ShrubberyCreationForm("Shrub_1");
		forms[1] = new RobotomyRequestForm("Robot_1");
		forms[2] = new RobotomyRequestForm("Robot_2");
		forms[3] = new PresidentialPardonForm("Hunter_Biden");
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try {
		workforce[0]->signForm(*forms[0]);
		workforce[1]->signForm(*forms[1]);
		workforce[2]->signForm(*forms[2]);
		workforce[2]->signForm(*forms[3]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		workforce[0]->signForm(*forms[3]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}	
	std::cout << std::endl;
	for (size_t i = 0; i < 4; i++) {
		if (forms[i]) {
			for (size_t j = 0; j < 3; j++) {
				try {
					workforce[j]->executeForm(*forms[i]);
				}
				catch (const std::exception& e) {
					std::cerr << "Error for " << workforce[j]->getName() << ": " << e.what() << std::endl;
				}
				std::cout << std::endl;
			}
		}
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
