#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Costrutor

Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = Account::getNbAccounts();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";created" << std::endl;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
};

// Destructor

Account::~Account()
{

};

// Getters

int	Account::getNbAccounts( void )
{
	return(_nbAccounts);
};

int	Account::getTotalAmount( void )
{
	return(_totalAmount);
};

int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
};

int	Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
};

// Print

void	Account::displayAccountsInfos( void )
{

};

void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
};

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_amount += withdrawal;
	return (true);
};

int	Account::checkAmount( void ) const
{
	return (this->_amount);
};

void	Account::displayStatus( void ) const
{

};

void	Account::_displayTimestamp( void )
{

};
