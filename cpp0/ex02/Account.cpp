/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:50:51 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 10:50:55 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	print_time(void) {
	std::time_t t = std::time(NULL);
	std::tm *const Info = std::localtime(&t);
	std::cout.fill('0');
	std::cout << "["<< std::setw(2) << 1900 + Info->tm_year;
	std::cout << std::setw(2) << Info->tm_mon + 1 << std::setw(2) << Info->tm_mday << "_";
	std::cout << std::setw(2) << Info->tm_hour << std::setw(2) << Info->tm_min;
	std::cout << std::setw(2) << Info->tm_sec << "] ";
}

Account::Account(int initial_deposit) {
	print_time();
	Account::_totalAmount += initial_deposit;
	this->_nbWithdrawals = 0;
	this->_accountIndex = Account::getNbAccounts();
	Account::_nbAccounts++;
	std::cout << "index:" << this->_accountIndex << ";";
	this->_amount = initial_deposit;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbDeposits = 0;
	std::cout << "created" << std::endl;
	return ;
}

Account::~Account(void) {
	print_time();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	return ;
}

int Account::getNbAccounts(void) { 
	return (_nbAccounts);
}

int Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	print_time();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::displayStatus(void) const {
	print_time();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amounts:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit) {
	print_time();
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbDeposits++;
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	print_time();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount) {
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbWithdrawals++;
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals <<std::endl;
	return (true);
}
