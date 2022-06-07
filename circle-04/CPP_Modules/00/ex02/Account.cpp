#include <iostream>
#include <ctime>
#include "./Account.hpp"

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

int		Account::getNbAccounts( void ) { return (_nbAccounts); }
int		Account::getTotalAmount( void ) { return (_totalAmount); }
int		Account::getNbDeposits( void ) { return (_totalNbDeposits); }
int		Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

void	Account::_displayTimestamp( void ) {
	char	buffer[18];
	time_t	time;

	std::time(&time);
	std::strftime(buffer, 18, "[%Y%m%d_%H%M%S]", localtime(&time));
	std::cout << buffer << " ";
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account( void ) {
	_accountIndex = _nbAccounts++;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created" << std::endl;
}

Account::Account( int initial_deposit ) {
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created" << std::endl;
}

Account::~Account( void ) {
	_nbAccounts--;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	int	p_amount = _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << p_amount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << (_amount += deposit) << ";"
		<< "nb_deposits:" << ++_nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits += _nbDeposits;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	int	check;
	int	p_amount = _amount;

	_amount -= withdrawal;
	check = checkAmount();
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << p_amount << ";"
		<< "withdrawal:";
	if (check) {
		std::cout << withdrawal << ";"
			<< "amount:" << _amount << ";"
			<< "nb_withdrawals:" << ++_nbWithdrawals << std::endl;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += _nbWithdrawals;
		return (true);
	}
	else {
		_amount = p_amount;
		std::cout << "refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount( void ) const {
	if (_amount > 0) return (1);
	return (0);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals << std::endl;
}


