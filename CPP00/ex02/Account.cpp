/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:12:14 by kbolon            #+#    #+#             */
/*   Updated: 2024/11/04 12:20:24 by kbolon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
//#include <iomanip>
#include <ctime>
#include "Account.hpp"

//these data members are static and must be declared here to
//allocate memory to them when program is compiled.
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//empty construct if no input
Account::Account(){}

//constructor if initial deposit provided
Account::Account(int initialDeposit)
{
	this->_accountIndex = this->getNbAccounts();
	Account::_nbAccounts++;
	this->_amount = initialDeposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initialDeposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" 
		<< this->checkAmount() << ";created" << std::endl;
}

//destructor 
Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
		<< ";amount:" << this->checkAmount()
		<< ";closed" << std::endl;
	_totalAmount -= _amount;
	_nbAccounts--;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::_displayTimestamp(void)
{
	time_t	current_time;
	char	buffer[20];

	current_time = time(NULL);
	if (std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", 
		std::localtime(&current_time)))
	{
		std::cout << buffer;
	}
	else
		std::cout << "Error formatting time" << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
		<< ";total:" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbDeposits()
		<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->checkAmount()
		<< ";deposits:" << this->_nbDeposits 
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->checkAmount();
	this->_amount += deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << this->checkAmount();
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
	
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount();
	std::cout << ";withdrawal:";
	if (withdrawal > this->checkAmount())
	{
		std::cout << "refused"  <<std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << this->checkAmount()
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}
