/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:16:37 by mac               #+#    #+#             */
/*   Updated: 2025/03/17 08:55:54 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string dataFile) : _dataFile(dataFile) {
	loadDataToMap(_dataFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange::~BitcoinExchange() { }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->_dataFile = other._dataFile;
		this->_dataMap = other._dataMap;
	}
	return *this;
}

// void BitcoinExchange::readDataFile() {
// 	std::ifstream datafile("data.csv");
// 	if (!datafile.is_open())
// 		throw(UnableToReadFile());
// 	std::string readLine;
// 	while (getline(datafile, readLine))
// 		std::cout << readLine << std::endl;
// 	datafile.close();
// }

void BitcoinExchange::loadDataToMap(std::string &dataFile) {
	std::ifstream inputTxt(dataFile);
	if (!inputTxt.is_open())
		throw(UnableToReadFile());
	std::string readLine;
	// Read first line to ignore the header title "data | value"
	std::getline(inputTxt, readLine);

	while (std::getline(inputTxt, readLine)) {
		std::istringstream tokenizedDataStream(readLine);
		std::string date, value;
		if (std::getline(tokenizedDataStream, date, ',') && std::getline(tokenizedDataStream, value)) {
			date = trim(date);
			value = trim(value);
			try {
				float rate = std::stof(value);
				_dataMap[date] = rate;
			} catch (const std::exception &e) {
				std::cerr << "Error: invalid data in data file for date "
						  << date << " with value: " << value << std::endl;
			}
		}
	}
	inputTxt.close();
}

std::string BitcoinExchange::trim(const std::string &str) {
	std::string s = str;
	size_t start = s.find_first_not_of(" \t");
	if (start != std::string::npos)
		s = s.substr(start);
	size_t end = s.find_last_not_of(" \t");
	if (end != std::string::npos)
		s = s.substr(0, end + 1);
	return s;
}

bool BitcoinExchange::getExchangeRateForDate(const std::string &date, float &rate) {
	_mapIt = _dataMap.find(date);
	if (_mapIt != _dataMap.end()) {
		rate = _mapIt->second;
		return true;
	}
	_lowerIt = _dataMap.lower_bound(date);
	if (_lowerIt == _dataMap.begin() && _lowerIt->first > date)
		return false;
	if (_lowerIt == _dataMap.end() || _lowerIt->first > date)
		--_lowerIt;
	rate = _lowerIt->second;
	return true;
}

void BitcoinExchange::handleHeader(std::ifstream &input) {
	std::string line;
	if (std::getline(input, line)) {
		if (line.find("date | value") != std::string::npos)
			std::cout << line << std::endl;
		else
			input.seekg(0);
	}
}

void BitcoinExchange::compareLine(const std::string &line) {
	std::istringstream tokenizedInputStream(line);
	std::string date, value;
	if (!(std::getline(tokenizedInputStream, date, '|') && std::getline(tokenizedInputStream, value))) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	date = trim(date);
	value = trim(value);
	float numericValue;
	try {
		numericValue = std::stof(value);
	} catch (const std::exception &e) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	if (numericValue < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return;
	}
	if (numericValue > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return;
	}
	float rate;
	if (!getExchangeRateForDate(date, rate)) {
		std::cerr << "Error: no matching date found for " << date << std::endl;
		return;
	}
	float result = numericValue * rate;
	std::cout << date << " => " << numericValue << " = " << result << std::endl;
}

void BitcoinExchange::compareDates(const std::string &inputFile) {
	std::ifstream input(inputFile);
	if (!input.is_open())
		throw std::runtime_error("Error: could not open file.");

	handleHeader(input);

	std::string line;
	while (std::getline(input, line)) {
		compareLine(line);
	}
	input.close();
}
