/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:15:22 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/17 02:39:12 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <iostream>

int	Account::_nbAccounts(0);
int	Account::_totalAmount(0);
int	Account::_totalNbDeposits(0);
int	Account::_totalNbWithdrawals(0);

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created" << "\n";
	return;
}

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {

	std::cout << "accounts:" << getNbAccounts() << ";"
		<< "total:"	<< getTotalAmount()	<< ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals() << "\n";
}

Account::~Account( void ) {
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed" << "\n";
	return;
}

void Account::makeDeposit( int deposit ) {
	(void)deposit;
	return;
}
bool Account::makeWithdrawal( int withdrawal ) {
	(void)withdrawal;
	return true;
}
int	 Account::checkAmount( void ) const {
	return 1;
}
void Account::displayStatus( void ) const {
	return;
}

void Account::_displayTimestamp( void ) {
	time_t t(0);
	time(&t);
	struct tm* ti = localtime(&t);

	std::cout << "[" << ti->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << ti->tm_mon;
	std::cout << std::setfill('0') << std::setw(2) << ti->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << ti->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << ti->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << ti->tm_sec << "] ";
	return ;
}
