#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	// Test case 1: Bureaucrat with a high enough grade to sign the form.
	try {
		Bureaucrat alice("Alice", 30);  // Grade 30 is high enough for a form requiring 50.
		Form form1("Form1", false, 50, 25);  // Required grade to sign: 50; execute: 25.

		std::cout << "Before signing:" << std::endl;
		std::cout << alice << std::endl;
		std::cout << form1 << std::endl;

		// Alice attempts to sign form1.
		alice.signForm(form1);

		std::cout << "After signing:" << std::endl;
		std::cout << form1 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception caught during test 1: " << e.what() << std::endl;
	}

	std::cout << "--------------------------------" << std::endl;

	// Test case 2: Bureaucrat with a too-low grade trying to sign a form.
	try {
		Bureaucrat bob("Bob", 100);  // Grade 100 is too low for a form requiring 50.
		Form form2("Form2", false, 50, 25);

		std::cout << "Before signing:" << std::endl;
		std::cout << bob << std::endl;
		std::cout << form2 << std::endl;

		// Bob attempts to sign form2.
		bob.signForm(form2);

		std::cout << "After signing:" << std::endl;
		std::cout << form2 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Exception caught during test 2: " << e.what() << std::endl;
	}

	return 0;
}
