#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const char* Form::GradeTooLowException::what() const throw() {
	return("Error: Grade Too Low");
};

Form::Form() : _name("Blank"), _signed(0), _gradeToSign(0), _gradeToExecute(0) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name) : _name(name), _signed(0), _gradeToSign(0), _gradeToExecute(0)  {
	std::cout << "Form name parameter constructor called" << std::endl;
}

Form::Form(const std::string &name, int grade_Sign, int grade_Execute) : _name(name), _signed(0), _gradeToSign(grade_Sign), _gradeToExecute(grade_Execute) {
	std::cout << "Form full parameter constructor called" << std::endl;
	if (grade_Sign > 150 || grade_Execute > 150)
		std::cout << "Cannot sign/execute form as bureaucrat has lowest grade of 150" << std::endl;
	else if (grade_Sign < 1 || grade_Execute < 1)
		std::cout << "Cannot sign/execute form as bureaucrat has highest grade of 1" << std::endl;
}

Form::Form(const Form& src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), 
	_gradeToExecute(src._gradeToExecute) {
	std::cout << "Form Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& src) {
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &src) {
		this->_signed = src._signed;
	}
	return (*this);
}

Form::~Form() {
	std::cout << "Form deconstructor called" << std::endl;
}

std::string	Form::getName() {
	return this->_name;
}

bool	Form::getSigned() {
	return this->_signed;
}

int	Form::getGradeToSign() {
	return this->_gradeToSign;
}

int	Form::getGradeToExecute() {
	return this->_gradeToExecute;
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		if (!_signed)
			this->_signed = 1;
	}
	else
		throw GradeTooLowException();
}


std::ostream& operator<<(std::ostream&os, const Form& src) {
	if (src.getSigned() == true)
		os << src.getName() << ", signed by Bureaucrat level " << src.getGradeToSign() 
		<< " and executed by level " << src.getGradeToExecute();
	else
		os << src.getName() << ", Form not signed.";
	return os;
}