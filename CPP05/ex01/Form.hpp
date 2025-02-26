/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:19:03 by mac               #+#    #+#             */
/*   Updated: 2025/02/24 17:18:35 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #pragma once
#include <iostream>
#include <stdexcept>
#include <cstdbool>

class Bureaucrat;

class Form{
	private:
		const std::string _name;
		bool _is_signed;
		const int _toSign_grade;
		const int _toExecute_grade;

	public:
		Form();
		Form(std::string _name, bool _is_signed, const int _toSign_grade, const int _toExecute_grade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

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

		std::string getName() const;
		bool getIsSigned() const;
		int getToSignGrade() const;
		int getToExecuteGrade() const;
		void beSigned(const Bureaucrat &Bureaucrat);
};

std::ostream &operator<<(std::ostream &out, const Form &Form);
