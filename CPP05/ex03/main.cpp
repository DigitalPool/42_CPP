#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	try {
		// Create a high-ranking bureaucrat that can sign and execute all forms.
		Bureaucrat boss("Boss", 1);
		// Create a lower-ranking bureaucrat that should fail execution.
		Bureaucrat intern("Intern", 150);

		// ----------- ShrubberyCreationForm Test -----------
		std::cout << "----- Testing ShrubberyCreationForm -----" << std::endl;
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;

		// Boss signs the form
		boss.signForm(shrub);
		// Boss executes the form (should create a file "home_shrubbery" with ASCII trees)
		boss.executeForm(shrub);

		// Intern tries to execute the form (should fail due to insufficient grade)
		intern.executeForm(shrub);

		// ----------- RobotomyRequestForm Test -----------
		std::cout << "\n----- Testing RobotomyRequestForm -----" << std::endl;
		RobotomyRequestForm robot("Bender");
		std::cout << robot << std::endl;

		// Boss signs the form
		boss.signForm(robot);
		// Execute several times to observe the 50% success chance (drilling noises and success/failure message)
		for (int i = 0; i < 5; i++) {
			boss.executeForm(robot);
		}

		// ----------- PresidentialPardonForm Test -----------
		std::cout << "\n----- Testing PresidentialPardonForm -----" << std::endl;
		PresidentialPardonForm pardon("Fry");
		std::cout << pardon << std::endl;

		// Boss signs the form
		boss.signForm(pardon);
		// Boss executes the form (should print that Fry has been pardoned)
		boss.executeForm(pardon);
	}
	catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	Intern someRandomIntern;
	AForm* rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf = someRandomIntern.makeForm("robotomy irequest", "Bender");
	return 0;
}
