/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:36:08 by mac               #+#    #+#             */
/*   Updated: 2025/01/17 08:02:16 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char** argv)
{

	Harl Harl;
	const int DEBUG = 0;
	const int INFO = 1;
	const int WARNING = 2;
	const int ERROR = 3;
	int x = 1337;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2) {
		std::cerr << "Usage: ./exec <switch>" << std::endl;
		return 1;
	}

	for (int i = 0; i < 4; i++)	{
		if (std::string(argv[1]) == levels[i])
			x = i;
	}

	switch (x){
		case DEBUG:
			Harl.complain("DEBUG");
			break;
		case INFO:
			Harl.complain("INFO");
			break;
		case WARNING:
			Harl.complain("WARNING");
			break;
		case ERROR:
			Harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	};
	return 0;
}
