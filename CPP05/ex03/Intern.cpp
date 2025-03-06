/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:46:02 by mac               #+#    #+#             */
/*   Updated: 2025/03/06 08:16:58 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// #include "AForm.hpp"
// #include "Bureaucrat.hpp"
// #include <iostream>
// #include <fstream>

// class AForm;

// class Intern : public AForm{
// 	private:
// 		Intern();
// 	public:
// 		Intern(Intern &other);
// 		virtual ~Intern();
// 		Intern &operator=(Intern &src);

// 		AForm *makeForm (std::string formName, AForm *Aform);
// 		class FormNameDoesnotExist : public std::exception{
// 			public:
// 				const char* what() throw() {
// 					return "Form name doesn't exist";
// 				}
// 		};

// };

// std::ostream &operator<<(std::ostream &out, Intern *Intern);

Intern::Intern(){
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern &other){
	*this = other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern(){
	std::cout << "Intern destructor called" << std::endl;
}

// there is nothing to copy. Always remember that.
Intern &Intern::operator=(Intern &src){
	// *this = src;
	(void) src;
	return *this;
	std::cout << "Intern copy assignment operator called" << std::endl;
}

// Define a function pointer type for functions that create AForm objects
typedef AForm* (*formCreator)(const std::string &target);

static AForm* createShrubbery(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string &target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string &target) {
	return new PresidentialPardonForm(target);
}


AForm *Intern::makeForm(const std::string formName, const std::string target) {
	struct FormMapping {
		std::string name;
		formCreator creator;
	};

	FormMapping mappings[3] = {
		{ "shrubbery creation", createShrubbery },
		{ "robotomy request",   createRobotomy },
		{ "presidential pardon", createPardon }
	};
	for (int i = 0; i < 3; i++) {
		if (mappings[i].name == formName) {
			AForm *form = mappings[i].creator(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	std::cout << "Intern: Unknown form name \"" << formName << "\"" << std::endl;
	return NULL;
}
