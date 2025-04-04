#pragma once
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
  private:
	std::string	_name;
	int			_grade;
  public:
    Bureaucrat();
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat &operator=(const Bureaucrat &src);

	~Bureaucrat();
	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();

	class	GradeTooHighException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& src);