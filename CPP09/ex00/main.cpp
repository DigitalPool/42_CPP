/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:51 by mac               #+#    #+#             */
/*   Updated: 2025/03/11 10:22:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string dataFile) : _dataFile(dataFile) {

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){
	this->_dataFile = other._dataFile;
	*this = other;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
	if (this != &other) {
		this->_dataFile = other._dataFile;
	}
	return *this;
}

void BitcoinExchange::readDataFile(){
	std::ifstream datafile("data.csv");
	if (!datafile.is_open())
		throw(UnableToReadFile());

	std::string readLine;
	while (getline(datafile, readLine))
		std::cout << readLine << std::endl;
	datafile.close();
}

int main(){
	// if(argc != 2){
	// 	std::cerr << "invalid arguments: ./btc input.txt" << std::endl;
	// 	return -1;
	// }
	BitcoinExchange bitcoinExchange("data.txt");
	bitcoinExchange.readDataFile();
	return 0;
}
