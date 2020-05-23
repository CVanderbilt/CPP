#include "Account.class.hpp"
#include <iostream>
#include <iomanip>
#include<ctime> 

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void){
    return (Account::_totalAmount);
}
int	Account::getNbDeposits(void){
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){
    return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{ 
    time_t tt; 
    struct tm * ti; 
   

    //std::cout << "[19920104_091532] "; return ;
   
    time (&tt); 
    ti = localtime(&tt); 
    std::cout << "[" << ti->tm_year + 1900 << std::setfill('0') << std::setw(2) << ti->tm_mon + 1
              << std::setfill('0') << std::setw(2) << ti->tm_wday << "_"
              << std::setfill('0') << std::setw(2) << ti->tm_hour
              << std::setfill('0') << std::setw(2) << ti->tm_min
              << std::setfill('0') << std::setw(2) << ti->tm_sec << "] "; 
}

void	Account::makeDeposit( int deposit )
{
    //index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
    if (deposit > 0)
    {
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
        this->_totalNbDeposits++;
        this->_nbDeposits++;
        this->_amount += deposit;
        this->_totalAmount += deposit;
        std::cout << ";deposit:" << deposit
                  << ";amount:" << this->_amount
                  << ";nb_deposits:" << this->_nbDeposits
                  << std::endl;
    }
}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
              << ";withdrawal:";
    if (this->_amount >= withdrawal)
    {
        this->_nbWithdrawals++;
        this->_totalNbWithdrawals++;
        this->_amount -= withdrawal;
        this->_totalAmount -= withdrawal;
        std::cout << withdrawal << ";amount:" << this->_amount
                  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return (true);
    }
    else
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    
}
void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();

    std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount()
              << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals()
              << std::endl;
}

Account::Account(int deposit)
{
    int index;

    index = this->_nbAccounts;
    this->_nbAccounts++;
    this->_totalAmount += deposit;
    this->_accountIndex = index;
    this->_amount = deposit > 0 ? deposit : 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << "index:" << index << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account()
{
    //index:0;amount:47;closed
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
              << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::displayStatus() const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
}

