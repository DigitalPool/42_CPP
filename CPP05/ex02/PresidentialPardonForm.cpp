/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:58:54 by mac               #+#    #+#             */
/*   Updated: 2025/02/24 22:23:34 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// class PresidentialPardonForm : public AForm{
// 	private:
// 		const std::string _target;
// 		PresidentialPardonForm();
// 	public:
// 		PresidentialPardonForm(std::string target);
// 		PresidentialPardonForm(const PresidentialPardonForm &other);
// 		virtual ~PresidentialPardonForm();

// 		PresidentialPardonForm &operator=(PresidentialPardonForm &PresidentialPardonForm);

// 		std::string getTarget() const;
// 		void execute (Bureaucrat const & executor) const;
// };

PresidentialPardonForm::PresidentialPardonForm()
		: AForm("PresidentialPardonForm", false, 25, 5), _target("default") {
	std::cout << "default constructor for PresidentialPardonForm called" << std::endl;
}
// AForm(std::string _name, bool _is_signed, const int _toSign_grade, const int _toExecute_grade);
PresidentialPardonForm::PresidentialPardonForm(std::string target)
		: AForm("PresidentialPardonForm", false, 25, 5), _target(target) {
	std::cout << "default constructor for PresidentialPardonForm called for target " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other)
		: AForm ("PresidentialPardonForm", false, 25, 5), _target(other.getTarget()) {
	std::cout << "Constructor for PresidentialPardonForm called for target " << other.getTarget() << std::endl;
	if (this != &other)
		*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "Destructor for PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &src) {
	//all the attributes of this class are constant so we cannot assign anything
	if (this == &src)
		return (*this);
	return (*this);
}

std::string PresidentialPardonForm::getTarget () const {
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false){
		throw (AForm::UnsignedFormException());
		std::cout << this->_target << " was not pardoned" << std::endl;
	}
	else if ( executor.getGrade() > this->getToExecuteGrade()){
		throw (AForm::GradeTooLowException());
		std::cout << this->_target << " was not pardoned" << std::endl;
	}
	else
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm *PresidentialPardonForm){
	out << "PresidentialPardonForm Target: "  << PresidentialPardonForm->getTarget() << std::endl;
	return out;
}
