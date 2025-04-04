/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:52:03 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/10 14:38:56 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class	AForm {
private:
	const std::string	_name;
	const std::string	_target;
	bool				_signed;
	const int			_signing_grade;
	const int			_execution_grade;

public:
	AForm(const std::string& name, int signing_grade, int execution_grade, std::string target);
	AForm(const AForm& copy);
	AForm &operator=( const AForm &src );
	virtual ~AForm();

	//Getters
	const std::string	getName() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	const std::string	getTarget() const;

	//Grade manipulation
	void				beSigned( const Bureaucrat& Bureaucrat );
	bool				isExecutable( const Bureaucrat& Bureaucrat ) const;

	virtual void		execute( Bureaucrat const & executor ) const = 0;

	//Exception Classes
	class	GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	class	FormNotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};

};

std::ostream&	operator<<(std::ostream& os, const AForm& src);