/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:33:13 by mac               #+#    #+#             */
/*   Updated: 2025/03/17 08:37:00 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <stdexcept>
#include <string>

class BitcoinExchange {
	private:
		std::string _dataFile;
		std::map<std::string, float> _dataMap;
		std::map<std::string, float>::iterator _mapIt;
		std::map<std::string, float>::iterator _lowerIt;
		std::string trim(const std::string &str);
		bool getExchangeRateForDate(const std::string &date, float &rate);
		void handleHeader(std::ifstream &input);
		void compareLine(const std::string &line);

	public:
		BitcoinExchange(std::string dataFile);
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &other);

		// void readDataFile();
		void loadDataToMap(std::string &dataFile);
		void compareDates(const std::string &inputFile);

		class UnableToReadFile : public std::exception {
			public:
				const char* what() const throw() {
					return "unable to open data file";
				}
		};
};

#endif
