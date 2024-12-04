/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:14:33 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/04 17:16:54 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>


int	main( void ) {
	Bureaucrat*	workforce[3] = {NULL, NULL, NULL};
	Form*		forms[4] = {NULL, NULL, NULL, NULL};

	std::cout << "Initialisation:" << std::endl;
	try {
		workforce[0] = new Bureaucrat("Tom", 1);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		workforce[1] = new Bureaucrat("Dick", 150);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		workforce[2] = new Bureaucrat("Harry", 42);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try {
		std::cout << std::endl << "Initialising forms" << std::endl;
		forms[0] = new Form("Incident Report", 50, 50);
		forms[1] = new Form("Leave Request", 100, 100);
		forms[2] = new Form();
		forms[3] = new Form("test", 200, 100);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "Work on Forms" << std::endl;
	try {
		workforce[0]->signForm(*forms[0]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		workforce[1]->signForm(*forms[0]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		workforce[2]->signForm(*forms[0]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		workforce[0]->signForm(*forms[2]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "Cleanup" << std::endl;
	for (size_t i = 0; i < 3; i++) {
		if (workforce[i])
			delete workforce[i];
	}
	for (size_t i = 0; i < 4; i++) {
		if (forms[i])
			delete forms[i];
	}
	
}