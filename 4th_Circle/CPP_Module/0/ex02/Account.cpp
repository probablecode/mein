#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	time_t	cur = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	tm		*ptm = std::localtime(&cur);

	std::cout << "[" << std::put_time(ptm, "%Y%m%d_%H%M%S") << "] ";
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()\
		<< ";total:" << getTotalAmount()\
		<< ";deposits:" << getNbDeposits()\
		<< ";withdrawals:" << getNbWithdrawals()\
		<< std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	
	_nbAccounts++;
	_totalAmount += this->checkAmount();
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex\
		<< ";amount:" << this->checkAmount()\
		<< ";created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex\
		<< ";amount:" << this->checkAmount()\
		<< ";closed\n";
}

int	Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex\
		<< ";amount:" << this->checkAmount()\
		<< ";deposits:" << this->_nbDeposits\
		<< ";withdrawals:" << this->_nbWithdrawals\
		<< std::endl;
}

void	Account::makeDeposit( int deposit )
{	
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex\
		<< ";p_amount:" << this->checkAmount()\
		<< ";deposit:" << deposit;
	
	this->_amount += deposit;
	this->_nbDeposits++;

	std::cout << ";amount:" << this->checkAmount()\
		<< ";nb_deposits:" << this->_nbDeposits\
		<< std::endl;
	
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int		p_amount = this->checkAmount();
	bool	ret = (withdrawal <= p_amount);

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex\
		<< ";p_amount:" << p_amount\
		<< ";withdrawal:";

	if (ret == false)
		std::cout << "refused\n";
	else
	{
		std::cout << withdrawal;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;

		std::cout << ";amount:" << this->checkAmount()\
		<< ";nb_withdrawals:" << this->_nbWithdrawals\
		<< std::endl;

		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
	}
	return (ret);
}
