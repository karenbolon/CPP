
#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("Nameless"), _grade(-1) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(-1) {
	std::cout << "Bureaucrat name parameter constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat name/grade parameter constructor called" << std::endl;
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat deconstructor called" << std::endl;
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

std::string	Bureaucrat::getName() const{
	return this->_name;
}

int			Bureaucrat::getGrade() const{
	return this->_grade;
}

void		Bureaucrat::incrementGrade() {
	if (this->_grade <= 1)
		throw GradeTooHighException();
	_grade--;
	std::cout << "new grade: " << this->_grade << std::endl;
}

void		Bureaucrat::decrementGrade() {
	if (this->_grade >= 150)
		throw GradeTooLowException();
	_grade++;
	std::cout << "new grade: " << this->_grade << std::endl;
}
  
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream& operator<<(std::ostream&os, const Bureaucrat& src) {
	if (src.getGrade() > 0)
		os << src.getName() << ", bureaucrat grade " << src.getGrade();
	else
		os << src.getName() << ", bureaucrat not graded yet.";
	return os;
}