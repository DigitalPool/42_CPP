/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:48:45 by mac               #+#    #+#             */
/*   Updated: 2025/02/24 22:17:35 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int _grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat &operator=( const Bureaucrat &other);

		const std::string getName() const;
		int getGrade() const;
		int setGrade(int grade);

		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &Form);

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

		void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

