/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:14:33 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/28 14:24:37 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>



int main() {
//creation
	Bureaucrat*	Jolene = nullptr;
	Bureaucrat*	Candace = nullptr;
	Bureaucrat*	Bill = nullptr;
	Bureaucrat*	Bob = nullptr;

	try {
		Jolene = new Bureaucrat("Jolene", 1);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Candace = new Bureaucrat("Candace", -1);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Bill = new Bureaucrat("Bill", 150);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Bob = new Bureaucrat("Bob", 160);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

//increment
	std::cout << std::endl << "Incrementing Bureaucrats" << std::endl;
	try {
		std::cout << "Jolene has grade: " << Jolene->getGrade() << std::endl;
		Jolene->incrementGrade();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Bill->incrementGrade();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

//decrement
	std::cout << std::endl << "Decrementing Bureaucrats" << std::endl;
	try {
		Jolene->decrementGrade();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		Bill->decrementGrade();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	delete Jolene;
	delete Bill;
	delete Bob;
	delete Candace;

}