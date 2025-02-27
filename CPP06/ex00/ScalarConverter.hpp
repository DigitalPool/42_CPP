/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:48:45 by mac               #+#    #+#             */
/*   Updated: 2025/02/27 09:48:12 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

class ScalarConverter{
	private:

	public:
		ScalarConverter();
		ScalarConverter(std::string name, int _grade);
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();

		ScalarConverter &operator=( const ScalarConverter &other);

		// class GradeTooLowException : public std::exception{
		// 	public:
		// 		const char* what() const throw() {
		// 			return "Grade is too low";
		// 	}
		// };
};

std::ostream &operator<<(std::ostream &out, const ScalarConverter &ScalarConverter);

