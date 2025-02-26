#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b("Alice", 2);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << "After increment: " << b << std::endl;

		// exception
		b.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "----------------------------" << std::endl;

	try {
		Bureaucrat c("Bob", 149);
		std::cout << c << std::endl;
		c.decrementGrade();
		std::cout << "After decrement: " << c << std::endl;
		// exception
		c.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
