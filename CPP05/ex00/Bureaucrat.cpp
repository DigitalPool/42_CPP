/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:48:37 by mac               #+#    #+#             */
/*   Updated: 2025/03/06 08:13:40 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	std::cout << "Bureaucrat default constructor called for " << this->_name << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

// Bureaucrat(const Bureaucrat &other);

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade){
	std::cout << "Bureaucrat copy constructor called for " << this->_name << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat default destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &other){
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

// 		const std::string getName() const;
// 		const int getGrade() const;
// 		int setGrade(int grade);

void Bureaucrat::incrementGrade() {
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

const std::string Bureaucrat::getName() const {
	return (this ->_name);
}

const int Bureaucrat::getGrade() const {
	return (this ->_grade);
}

int Bureaucrat::setGrade( int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
	return this->_grade;
}

// std::ostream ****** &Bureaucrat ******::operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat){
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}
