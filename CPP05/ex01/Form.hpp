/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:52:03 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/04 17:00:58 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

class	Form {
private:
	const std::string	_name;
	bool				_signed;
	const int			_signing_grade;
	const int			_execution_grade;

public:
	Form();
	Form(const std::string& name);
	Form(const std::string& name, int signing_grade, int execution_grade);
	Form(const Form& copy);
	Form &operator=( const Form &src );
	~Form();

	//Getters
	const std::string	getName() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	//Grade manipulation
	void				beSigned(const Bureaucrat& Bureaucrat);

	//Exception Classes
	class	GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

};

std::ostream&	operator<<(std::ostream& os, const Form& src);