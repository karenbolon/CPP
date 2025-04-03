#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() {}

Account::Account(int initial_deposit) {
	this->_accountIndex = this->getNbAccounts();
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account() {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	_totalAmount -= this->_amount;
	_nbAccounts--;
}

int Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

int Account::checkAmount(void) const {
	return this->_amount;
}

void	Account::_displayTimestamp( void ) {
	time_t timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);
  
	char buffer[20];
  
	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", &datetime);
	std::cout << buffer;
}

void Account:: displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() 
		<< ";total:" << Account::getTotalAmount() 
		<< ";deposits:" << Account::getNbDeposits() 
		<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}


void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
		<< ";amount:" << this->checkAmount() 
		<< ";deposits:" << this->_nbDeposits 
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	this->_amount += deposit;
	Account::_displayTimestamp();
	Account::_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;	
}

bool	Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	if (this->_amount < withdrawal) {
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	Account::_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;	
	std::cout << "index:" << _accountIndex << ";p_amount:" << this->checkAmount() << ";withdrawal:" << withdrawal
	<< "; amount:" << _amount << "; nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;

}



