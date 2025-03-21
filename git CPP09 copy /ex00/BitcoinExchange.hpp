/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:33:13 by mac               #+#    #+#             */
/*   Updated: 2025/03/11 09:31:03 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <iterator>
#include <exception>

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <cctype>

class Btc
{
private:
	std::map <std::string, float> data;
	int _openError;
public:
	Btc();
	~Btc();
	Btc& operator=(Btc const &var);
	Btc(Btc const &var);

	void setData(std::string date, float value);

	void readInput(std::string inputPath);

	std::map<std::string, float> getData();
	std::vector<std::string> splitString(std::string str, char delimiter);
};

#endif
