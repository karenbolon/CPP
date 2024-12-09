/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:52:03 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/09 15:44:02 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <sys/stat.h>
#include <iostream>
#include <fstream>

class	ShrubberyCreationForm : public AForm {

public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	ShrubberyCreationForm &operator=( const ShrubberyCreationForm &src );
	~ShrubberyCreationForm();

	void	execute( const Bureaucrat& executor ) const;

};