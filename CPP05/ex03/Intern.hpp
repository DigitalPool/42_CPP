/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:41:40 by mac               #+#    #+#             */
/*   Updated: 2025/02/26 14:37:50 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

class AForm;

class Intern{
	public:
		Intern();
		Intern(Intern &other);
		Intern &operator=(Intern &src);
		~Intern();

		AForm *makeForm (const std::string formName, const std::string formTarget);

		class FormNameDoesnotExist : public std::exception{
			public:
				const char* what() const throw() {
					return "Form name doesn't exist";
				}
		};

	};
