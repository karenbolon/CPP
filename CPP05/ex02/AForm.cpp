/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:52:09 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/09 17:08:36 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
	return("Error: Grade Too High");
};

const char* AForm::GradeTooLowException::what() const throw() {
	return("Error: Grade Too Low");
};

AForm::AForm(const std::string& name, const int signing_grade, const int execution_grade, const std::string target) : 
	_name( name ), _signed( false ), _signing_grade ( signing_grade ), _execution_grade( execution_grade ), _target( target) {
	std::cout << "Constructor called: AForm " << _name << " created with signing grade: " << _signing_grade \
	<< " and execution grade " << _execution_grade << std::endl;
	if (signing_grade < 1 || execution_grade < 1) {
		throw (GradeTooHighException());
	}
	else if (signing_grade > 150 || execution_grade > 150) {
		throw (GradeTooLowException());
	}
}

AForm::AForm( const AForm& src ) : _name(src._name), _signed(src._signed), _signing_grade(src._signing_grade), \
	_execution_grade(src._execution_grade), _target(src._target) {
	std::cout << "AForm copy constructor called" << std::endl;
}

//name is constant and can't be reassigned
AForm& AForm::operator=( const AForm &src ) {
	std::cout << "AForm assignment operator called" << std::endl;
	if (this != &src) {
		this->_signed = src._signed;
	}
	return (*this);
}

const std::string	AForm::getName() const {
	return (_name);
}

bool	AForm::getSigned() const {
	return (_signed);
}

int		AForm::getGradeToSign() const {
	return (_signing_grade);
}

int		AForm::getGradeToExecute() const {
	return (_execution_grade);
}

bool	AForm::isExecutable( const Bureaucrat& Bureaucrat ) const {
	if (!_signed) {
//		throw (FormNotSignedException());
		throw ( GradeTooLowException() );
	}
	if ( bureaucrat.getGrade() >= getGradeToExecuteGrade() ) {
		throw ( GradeTooLowException() );
	}
	return (true);
}

void	AForm::beSigned( const Bureaucrat& bureaucrat ) {
	if ( bureaucrat.getGrade() <= this->_signing_grade ) {
		if (!_signed)
			this->_signed = true;
	}
	else {
		throw ( GradeTooLowException() );
	}
}

AForm::~AForm() {
	std::cout << "Form deconstructor called" << std::endl;
}

std::ostream& operator<<(std::ostream&os, const AForm& src) {
	if (src.getSigned() == true)
		os << src.getName() << ", signed by Bureaucrat level " << src.getGradeToSign() 
		<< " and executed by level " << src.getGradeToExecute();
	else
		os << src.getName() << ", Form not signed.";
	return os;
}