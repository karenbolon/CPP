/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:14:33 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/09 16:58:17 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>


int	main( void ) {
	Bureaucrat*	workforce[3] = {NULL, NULL, NULL};
	AForm*		forms[4] = {NULL, NULL, NULL, NULL};

	std::cout << "\033[1:32mInitialisation\033[0m" << std::endl;
	try {
		std::cout << "Trying Michel, grade 1: ";
		workforce[0] = new Bureaucrat("Michel", 1);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		std::cout << "Trying Gilbert, grade 150: ";
		workforce[1] = new Bureaucrat("Gilbert", 150);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		std::cout << "Trying Monique, grade 42: ";
		workforce[2] = new Bureaucrat("Monique", 42);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::cout << std::endl << "\033[1:32mInitialising forms\033[0m" << std::endl;
		forms[0] = new ShrubberyCreationForm("referat_1");
//		forms[1] = new RobotomyRequestForm("robot_42");
//		forms[2] = new RobotomyRequestForm("robot_21");
//		forms[3] = new PresidentialPardonForm("Hugues");
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "\033[1:32mForms recap\033[0m" << std::endl;
	for (size_t i = 0; i < 3; i++) {
		if (forms[i])
			std::cout << *forms[i] << std::endl;
	}

	std::cout << std::endl << "\033[1:32mSigning forms\033[0m" << std::endl;
	try {
		workforce[0]->signForm(*forms[0]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		workforce[2]->signForm(*forms[1]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		workforce[2]->signForm(*forms[1]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		workforce[0]->signForm(*forms[3]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "\033[1:32mUsing forms\033[0m" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		try {
			workforce[0]->executeForm(*forms[0]);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			workforce[1]->executeForm(*forms[0]);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			workforce[0]->executeForm(*forms[1]);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			workforce[0]->executeForm(*forms[2]);
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	
	std::cout << std::endl << "\033[1:32mCleanup\033[0m" << std::endl;
	for (size_t i = 0; i < 3; i++) {
		if (workforce[i])
			delete workforce[i];
	}
	for (size_t i = 0; i < 4; i++) {
		if (forms[i])
			delete forms[i];
	}
}