#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

/* PUBLIC */

/*CONSTRUCTOR/ DECONSTRUCTOR*/

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << '\n';
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";close" << '\n';
}

int Account::getNbAccounts()
{
    return Account::_nbAccounts;
}

int Account::getTotalAmount()
{
    return Account::_totalAmount;
}

int Account::getNbDeposits()
{
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return Account::_totalNbWithdrawals;
}
void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts();
    std::cout << ";total:" << getTotalAmount();
    std::cout << ";deposits:" << getNbDeposits();
    std::cout << ";withdrawals:" << getNbWithdrawals() << '\n';
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
    std::cout << ";deposit:" << deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << '\n';
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
    std::cout << ";withdrawal:";
    if (_amount < withdrawal)
    {
        std::cout << "refused" << '\n';
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << '\n';
    return true;
}

int Account::checkAmount() const
{
    return _amount;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << '\n';
}

/* PRIVATE */

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
    std::time_t now = std::time(nullptr);
    struct std::tm *timeinfo = std::localtime(&now);

    std::cout << "[" << (timeinfo->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (timeinfo->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << timeinfo->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << timeinfo->tm_hour
              << std::setw(2) << std::setfill('0') << timeinfo->tm_min
              << std::setw(2) << std::setfill('0') << timeinfo->tm_sec << "]";
}

Account::Account(void) {}