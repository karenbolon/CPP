/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:05:47 by kbolon            #+#    #+#             */
/*   Updated: 2024/12/17 15:31:04 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return("Error: Grade Too High");
};

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return("Error: Grade Too Low");
};

Bureaucrat::Bureaucrat() : _name( "no_name" ), _grade( 150 ) {
	std::cout << "Default constructor: Bureaucrat " << _name << " created with grade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name) : _name( name ), _grade( 150 ) {
	std::cout << "String constructor: Bureaucrat " << _name << " created with grade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name( name ), _grade( grade ) {
	std::cout << "Bureaucrat " << _name << " created with grade: " << _grade << std::endl;
	if (grade < 1) {
		throw (GradeTooHighException());
	}
	else if (grade > 150) {
		throw (GradeTooLowException());
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat& src ) : _name(src._name), _grade(src._grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat &src ) {
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &src)
		_grade = src._grade;
	return (*this);
}

const std::string	Bureaucrat::getName() const {
	return (this->_name);
}

int		Bureaucrat::getGrade() const{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade() {
	if (_grade > 1) {
		std::cout << "Original grade: " << _grade << std::endl;
		_grade--;
		std::cout << "New grade after promotion: " << _grade << std::endl;
	}
	else {
		throw (GradeTooHighException());
	}
}

void	Bureaucrat::decrementGrade() {
	if (_grade < 150) { //if grade is already 150, it would go out of scope
		std::cout << "Original grade: " << _grade << std::endl;
		_grade++;
		std::cout << "New grade afer demotion: " << _grade << std::endl;
	}
	else {
		throw (GradeTooLowException());
	}
}

void	Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cerr << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << _name << " couldn't sign " << form.getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm( AForm const & form) {
	try  {
		form.execute(*this);
		std::cerr << _name << " executed " << form.getTarget() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << _name << " couldn't execute " << form.getTarget() << " because " << e.what() <<std::endl;
	}
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat deconstructor called" << std::endl;
}

std::ostream& operator<<(std::ostream&os, const Bureaucrat& src) {
	if (src.getGrade())
		os << src.getName() << ", bureaucrat grade " << src.getGrade();
	else
		os << src.getName() << ", bureaucrat not graded yet.";
	return os;
}