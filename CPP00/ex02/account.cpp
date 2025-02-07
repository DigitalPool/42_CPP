/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 05:52:02 by mac               #+#    #+#             */
/*   Updated: 2025/01/08 20:24:22 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
				_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0){
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;

//Print all accounts now
	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"amount:" << this->checkAmount() << ";" <<
	"created" <<
	std::endl;
}

Account::~Account(){
	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"amount:" << this->checkAmount() << ";" <<
	"closed" << std::endl;
	Account::_nbAccounts--;
}

// [19920104_091532] index:7;p_amount:16576;deposit:20;amount:16596;nb_deposits:1

void	Account::makeDeposit( int deposit ){
	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"p_amount:" << this->checkAmount() << ";" <<
	"deposit:" << deposit << ";";

	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	std::cout <<
	"amount:" << this->checkAmount() << ";" <<
	"nb_deposits:" << this->_nbDeposits <<
	std::endl;
}

//[19920104_091532] index:1;amount:819;deposits:1;withdrawals:0
bool Account::makeWithdrawal( int withdrawal ){

	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"p_amount:" << this->checkAmount() << ";";

	if (this->checkAmount() < withdrawal){
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout <<
		"withdrawal:" << withdrawal << ";" <<
		"amount:" << this->checkAmount() << ";" <<
		"nb_withdrawals:" << this->_nbWithdrawals <<
		std::endl;
		return (true);
	}

}

int		Account::checkAmount() const{
	return (this->_amount);
}

void Account::_displayTimestamp(){
	time_t timestamp;

	timestamp = time(NULL);
	std::cout << std::put_time(localtime(&timestamp), "[%Y%m%d_%H%M%S] ");
}

//**************************************************************//
//utils
//**************************************************************//

// [19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
void	Account::displayStatus() const{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
		<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

//**************************************************************//
//getters
//**************************************************************//

//[19920104_091532] accounts:8;total:12442;deposits:8;withdrawals:6
void	Account::displayAccountsInfos(){
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
			<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

int Account::getNbAccounts(){
	return Account::_nbAccounts;
}

int Account::getTotalAmount(){
	return Account::_totalAmount;
}

int Account::getNbDeposits(){
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(){
	return Account::_totalNbWithdrawals;
}
