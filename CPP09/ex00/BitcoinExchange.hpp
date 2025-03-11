/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:33:13 by mac               #+#    #+#             */
/*   Updated: 2025/03/11 10:20:16 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>



class BitcoinExchange {
	private:
		std::string _dataFile;

	public:
		BitcoinExchange(std::string dataFile);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &other);
		void readDataFile();

		class UnableToReadFile : public std::exception {
			public:
				const char* what() const throw(){
					return "unable to open data file";
				}
		};

};
#endif
