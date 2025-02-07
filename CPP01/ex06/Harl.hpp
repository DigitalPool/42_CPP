/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:32:19 by mac               #+#    #+#             */
/*   Updated: 2025/01/17 08:05:13 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[91m"
#define GREEN   "\033[92m"
#define YELLOW  "\033[93m"
#define MAGENTA "\033[95m"

class Harl {

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:
	Harl();

	void complain( std::string level );
};

#endif
