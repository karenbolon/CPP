#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat jolene("Jolene", 1);
        std::cout << jolene << std::endl;

        jolene.incrementGrade(); // This will throw GradeTooHighException
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat candace("Candace", 151); // This will throw GradeTooLowException
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bill("Bill", 150);
        std::cout << bill << std::endl;

        bill.decrementGrade(); // This will succeed
        std::cout << bill << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	try {
        Bureaucrat helen;
        std::cout << helen << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }


    return 0;
}