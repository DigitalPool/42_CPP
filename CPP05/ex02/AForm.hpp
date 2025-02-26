/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:19:03 by mac               #+#    #+#             */
/*   Updated: 2025/02/24 17:40:28 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>
#include <cstdbool>

class Bureaucrat;

class AForm{
	private:
		const std::string _name;
		bool _is_signed;
		const int _toSign_grade;
		const int _toExecute_grade;

	public:
		AForm();
		AForm(std::string _name, bool _is_signed, const int _toSign_grade, const int _toExecute_grade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw() {
					return "Grade is too high";
				}
		};

		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw() {
					return "Grade is too low";
			}
		};

		class UnsignedFormException : public std::exception{
			public:
				const char* what() const throw() {
					return "Form is nit signed";
			}
		};

		virtual void execute(Bureaucrat const &executor) const = 0;
		std::string getName() const;
		bool getIsSigned() const;
		int getToSignGrade() const;
		int getToExecuteGrade() const;
		void beSigned(const Bureaucrat &Bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);
