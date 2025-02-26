/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:44:14 by mac               #+#    #+#             */
/*   Updated: 2025/02/24 20:23:42 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// class Form{
// 	private:
// 		const std::string _name;
// 		bool _is_signed;
// 		const int _toSign_grade;
// 		const int _toExecute_grade;

// 	public:
// 		Form();
// 		Form(std::string _name, bool _is_signed, const int _toSign_grade, const int _toExecute_grade);
// 		Form &operator=(const Form &other);
// 		~Form();

Form::Form() : _name("default"), _is_signed(false), _toSign_grade(150), _toExecute_grade(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string _name, bool _is_signed, const int _toSign_grade, const int _toExecute_grade) :
	_name(_name), _is_signed(_is_signed), _toSign_grade(_toSign_grade), _toExecute_grade(_toExecute_grade) {

	std::cout << "Form default constructor called for " << _name <<
					"with toSign_grade " << _toSign_grade << "and toExecute_grade " << _toExecute_grade << std::endl;

}

Form::Form(const Form &other) : _name(other._name), _is_signed(other._is_signed), _toSign_grade(other._toSign_grade),
								_toExecute_grade(other._toExecute_grade){
	std::cout << "Form copy constructor called for " << this->_name << std::endl;

}

Form::~Form(){
	std::cout << "Form destructor called for " << this->_name << std::endl;
}

Form &Form::operator=(const Form &other){
	if (this != &other){
		// copy only the changable parameters
		this->_is_signed = other._is_signed;
	}
	return (*this);
}

void Form::beSigned(const Bureaucrat &Bureaucrat){
	if (this->_toSign_grade > 150)
		throw(GradeTooLowException());
	if (Bureaucrat.getGrade() <= this->_toSign_grade)
		this->_is_signed = true;
}

std::string Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _is_signed;
}

int Form::getToSignGrade() const {
	return _toSign_grade;
}

int Form::getToExecuteGrade() const {
	return _toExecute_grade;
}

// 		void beSigned(Bureaucrat &Bureaucrat);
// };

// std::ostream &operator<<(std::ostream &out, const Form &Form);

std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << "Form: " << form.getName() << ", signed: ";
	if (form.getIsSigned())
		out << "yes";
	else
		out << "no";
	out << ", required sign grade: " << form.getToSignGrade()
		<< ", required execute grade: " << form.getToExecuteGrade() << std::endl;
	return out;
}

