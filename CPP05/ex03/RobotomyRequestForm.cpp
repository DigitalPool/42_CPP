/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:58:54 by mac               #+#    #+#             */
/*   Updated: 2025/02/26 09:21:03 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// class RobotomyRequestForm : public AForm{
// 	private:
// 		const std::string _target;
// 		RobotomyRequestForm();
// 	public:
// 		RobotomyRequestForm(std::string target);
// 		RobotomyRequestForm(const RobotomyRequestForm &other);
// 		virtual ~RobotomyRequestForm();

// 		RobotomyRequestForm &operator=(RobotomyRequestForm &RobotomyRequestForm);

// 		std::string getTarget() const;
// 		void execute (Bureaucrat const & executor) const;
// };

RobotomyRequestForm::RobotomyRequestForm()
		: AForm("RobotomyRequestForm", false, 72, 45), _target("default") {
	std::cout << "default constructor for RobotomyRequestForm called" << std::endl;
}
// AForm(std::string _name, bool _is_signed, const int _toSign_grade, const int _toExecute_grade);
RobotomyRequestForm::RobotomyRequestForm(std::string target)
		: AForm("RobotomyRequestForm", false, 72, 45), _target(target) {
	std::cout << "default constructor for RobotomyRequestForm called for target " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other)
		: AForm ("RobotomyRequestForm", false, 72, 45), _target(other.getTarget()) {
	std::cout << "Constructor for RobotomyRequestForm called for target " << other.getTarget() << std::endl;
	if (this != &other)
		*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "Destructor for RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &src) {
	//all the attributes of this class are constant so we cannot assign anything
	if (this == &src)
		return (*this);
	return (*this);
}

std::string RobotomyRequestForm::getTarget () const {
	return (this->_target);
}

// needs fixing
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() == false){
		throw (AForm::UnsignedFormException());
		std::cout << this->_target << " robotomy failed" << std::endl;
	}
	else if ( executor.getGrade() > this->getToExecuteGrade()){
		throw (AForm::GradeTooLowException());
		std::cout << this->_target << " robotomy failed" << std::endl;
	}
	else
	{
		if ( (std::rand() % 2) == 1)
			std::cout << this->_target << " has been robotomized successfully" << std::endl;
		else
			std::cout << this->_target << " robotomy failed" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm *RobotomyRequestForm){
	out << "RobotomyRequestForm Target: "  << RobotomyRequestForm->getTarget() << std::endl;
	return out;
}
