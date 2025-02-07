/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:36:08 by mac               #+#    #+#             */
/*   Updated: 2025/01/16 22:17:17 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAllOccurrences(std::string buffer, std::string s1, std::string s2)
{
	size_t pos = 0;
	size_t found;

	std::string result;
	// result.reserve(buffer.size());

	while (true){
		found = buffer.find(s1, pos);
		if (found == std::string::npos) {
			result += buffer.substr(pos);
			break;
		}
		result += buffer.substr(pos, found - pos);
		result += s2;
		pos = found + s1.size();
	}
	return result;
}

int main(int argc, char* argv[]) {

	if (argc != 4) {
		std::cerr << "Usage: ./exec <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string buffer;
	std::string outFilename = filename + ".replace";
	std::string replaced;

	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open())
	{
		std::cerr << "Unable to open file" << std::endl;
		return 1;
	}

	std::ofstream outFile(outFilename.c_str());
	if (!outFile.is_open()) {
		std::cerr << "Error: Could not create file \""
				  << outFilename << "\" for writing." << std::endl;
		return 1;
	}

	while(std::getline(inFile, buffer)) {
		replaced = replaceAllOccurrences(buffer, s1, s2);
		outFile << replaced << std::endl;
	}

	inFile.close();
	outFile.close();
	return 0;
}
