#pragma once
#include "Bureaucrat.hpp"
#include <string>

class	Form {
  private:
    const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;
  public:
    Form();
	Form(const std::string& name);
	Form(const std::string &name, int grade_Sign, int grade_Execute);
	Form(const Form& src);

	Form& operator=(const Form& src);
	~Form();

	std::string		getName();
	bool			getSigned();
	int				getGradeToSign();
	int				getGradeToExecute();
	void			beSigned(const Bureaucrat& bureaucrat);

	class	GradeTooLowException : public std::exception {
		public:
		  virtual const char* what() const throw();
		  ~GradeTooLowException();
	  };
};

std::ostream& operator<<(std::ostream&os, const Form& src);