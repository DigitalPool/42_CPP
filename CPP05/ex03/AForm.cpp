/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:44:14 by mac               #+#    #+#             */
/*   Updated: 2025/02/27 09:39:25 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// class AForm{
// 	private:
// 		const std::string _name;
// 		bool _is_signed;
// 		const int _toSign_grade;
// 		const int _toExecute_grade;

// 	public:
// 		AForm();
// 		AForm(std::string _name, bool _is_signed, const int _toSign_grade, const int _toExecute_grade);
// 		AForm &operator=(const AForm &other);
// 		~AForm();

// AForm::AForm() : _name("default"), _is_signed(false), _toSign_grade(150), _toExecute_grade(150) {
// 	std::cout << "AForm default constructor called" << std::endl;
// }

AForm::AForm(std::string _name, bool _is_signed, const int _toSign_grade, const int _toExecute_grade) :
	_name(_name), _is_signed(_is_signed), _toSign_grade(_toSign_grade), _toExecute_grade(_toExecute_grade) {

	std::cout << "AForm default constructor called for " << _name <<
					" with to Sign_grade " << _toSign_grade << " and to Execute_grade " << _toExecute_grade << std::endl;

}

AForm::AForm(const AForm &other) : _name(other._name), _is_signed(other._is_signed), _toSign_grade(other._toSign_grade),
								_toExecute_grade(other._toExecute_grade){
	std::cout << "AForm copy constructor called for " << this->_name << std::endl;

}

AForm::~AForm(){
	std::cout << "AForm destructor called for " << this->_name << std::endl;
}

AForm &AForm::operator=(const AForm &other){
	if (this != &other){
		// copy only the changable parameters
		this->_is_signed = other._is_signed;
	}
	return (*this);
}

void AForm::beSigned(const Bureaucrat &Bureaucrat){
	if (this->_toSign_grade > 150)
		throw(GradeTooLowException());
	if (Bureaucrat.getGrade() <= this->_toSign_grade)
		this->_is_signed = true;
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _is_signed;
}

int AForm::getToSignGrade() const {
	return _toSign_grade;
}

int AForm::getToExecuteGrade() const {
	return _toExecute_grade;
}


// std::ostream &operator<<(std::ostream &out, const AForm &AForm);

std::ostream &operator<<(std::ostream &out, const AForm &AForm) {
	out << "AForm: " << AForm.getName() << ", signed: ";
	if (AForm.getIsSigned())
		out << "yes";
	else
		out << "no";
	out << ", required sign grade: " << AForm.getToSignGrade()
		<< ", required execute grade: " << AForm.getToExecuteGrade() << std::endl;
	return out;
}

