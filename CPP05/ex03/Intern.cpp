/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:41:48 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/17 15:53:39 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern & src) {
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern & Intern::operator=(const Intern & src) {
	if (this != src)
		*this = src;
	(*this);
}

Intern::~Intern(){}

AForm	Intern::makeForm(std::string name, std::string target) {
	
}






