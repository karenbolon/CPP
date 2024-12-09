/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:55:13 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/09 16:55:56 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {
protected:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name);
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat &operator=( const Bureaucrat &src );
	~Bureaucrat();

	//Getters
	const std::string	getName() const;
	int					getGrade() const;

	//Grade manipulation
	void				incrementGrade();
	void				decrementGrade();

	//Exception Classes
	class	GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	void				signForm( AForm& form );
	void				executeForm( AForm const & form);

};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& src);

