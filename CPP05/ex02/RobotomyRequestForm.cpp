/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:52:09 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/04 17:02:40 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw() {
	return("Error: Grade Too High");
};

const char* Form::GradeTooLowException::what() const throw() {
	return("Error: Grade Too Low");
};


Form::Form() : _name( "no_name" ), _signed( 0 ), _signing_grade ( 0 ), _execution_grade( 0 ) {
	std::cout << "Default constructor called: Form " << _name << " created with signing grade: " << _signing_grade 
	<< " and execution grade: " << _execution_grade << std::endl;
}

Form::Form(const std::string& name) : _name( name ), _signed( 0 ), _signing_grade ( 0 ), _execution_grade( 0 ) {
	std::cout << "String constructor called: Form " << _name << " created with signing grade: " << _signing_grade 
	<< " and execution grade: " << _execution_grade << std::endl;
}

Form::Form(const std::string& name, const int signing_grade, const int execution_grade) 
	: _name( name ), _signed( false ), _signing_grade ( signing_grade ), _execution_grade( execution_grade ) {
	std::cout << "Constructor called: Form " << _name << " created with signing grade: " << _signing_grade \
	<< " and execution grade " << _execution_grade << std::endl;
	if (signing_grade < 1 || execution_grade < 1) {
		throw (GradeTooHighException());
	}
	else if (signing_grade > 150 || execution_grade > 150) {
		throw (GradeTooLowException());
	}
}

Form::Form( const Form& src ) : _name(src._name), _signed(src._signed), _signing_grade(src._signing_grade), \
	_execution_grade(src._execution_grade) {
	std::cout << "Form copy constructor called" << std::endl;
}

//name is constant and can't be reassigned
Form& Form::operator=( const Form &src ) {
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &src) {
		this->_signed = src._signed;
	}
	return (*this);
}

const std::string	Form::getName() const {
	return (_name);
}

bool	Form::getSigned() const {
	return (_signed);
}

int		Form::getGradeToSign() const {
	return (_signing_grade);
}

int		Form::getGradeToExecute() const {
	return (_execution_grade);
}

void	Form::beSigned( const Bureaucrat& bureaucrat ) {
	if ( bureaucrat.getGrade() <= this->_signing_grade ) {
		if (!_signed)
			this->_signed = true;
	}
	else {
		throw ( GradeTooLowException() );
	}
}

Form::~Form() {
	std::cout << "Form deconstructor called" << std::endl;
}

std::ostream& operator<<(std::ostream&os, const Form& src) {
	if (src.getSigned() == true)
		os << src.getName() << ", signed by Bureaucrat level " << src.getGradeToSign() 
		<< " and executed by level " << src.getGradeToExecute();
	else
		os << src.getName() << ", Form not signed.";
	return os;
}