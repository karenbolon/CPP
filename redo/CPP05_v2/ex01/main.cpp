#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>


int	main( void ) {
	Bureaucrat*	workforce[3] = {NULL, NULL, NULL};
	Form*		forms[4] = {NULL, NULL, NULL, NULL};

	std::cout << "Initialisation:" << std::endl;
	try {
		workforce[0] = new Bureaucrat("Tom", 1);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		workforce[1] = new Bureaucrat("Dick", 150);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		workforce[2] = new Bureaucrat("Harry", 42);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}
