#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor

Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = Account::getNbAccounts();
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";created" << std::endl;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
};

// Destructor

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";closed" << std::endl;
	Account::_nbAccounts--;
};

// Print

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "index:" << _nbAccounts << ";amount:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
};

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
};

void	Account::_displayTimestamp( void )
{
	char buffer[20];

	time_t now = time(NULL);
	struct tm* localTime = localtime(&now);
	strftime(buffer, 20, "[%Y%m%d_%H%M%S]", localTime);
	std::cout << buffer;
};

// Setters

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";deposit:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
};

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (this->checkAmount() >= withdrawal)
	{
		this->_nbWithdrawals++;
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";withdrawal:" << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		this->_amount -= withdrawal;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		return (true);
	}
	else
	{
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";withdrawal:refused" << std::endl;
		return (false);
	}
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

int	Account::checkAmount( void ) const
{
	return (this->_amount);
};
