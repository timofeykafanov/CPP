// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                Created on  : Thu Feb 27 12:00:00 2025                      //
//                Last update : Thu Feb 27 12:00:00 2025                      //
//                Made by : New Developer <dev@gbu.com>                       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

void Account::_displayTimestamp(void) {
    std::time_t now = std::time(NULL);
    std::tm* localTime = std::localtime(&now);

    std::cout << "[" 
              << localTime->tm_year + 1900
              << std::setfill('0') << std::setw(2) << localTime->tm_mon + 1
              << std::setfill('0') << std::setw(2) << localTime->tm_mday
              << "_"
              << std::setfill('0') << std::setw(2) << localTime->tm_hour
              << std::setfill('0') << std::setw(2) << localTime->tm_min
              << std::setfill('0') << std::setw(2) << localTime->tm_sec
              << "] ";
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() 
              << ";total:" << getTotalAmount() 
              << ";deposits:" << getNbDeposits() 
              << ";withdrawals:" << getNbWithdrawals() 
              << std::endl;
}

Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    
    _nbAccounts++;
    _totalAmount += initial_deposit;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";created" 
              << std::endl;
}

Account::Account(void) {
    _accountIndex = _nbAccounts;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    
    _nbAccounts++;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";created" 
              << std::endl;
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";closed" 
              << std::endl;
}

void Account::makeDeposit(int deposit) {
    int p_amount = _amount;
    _amount += deposit;
    _nbDeposits++;
    
    _totalAmount += deposit;
    _totalNbDeposits++;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";p_amount:" << p_amount 
              << ";deposit:" << deposit 
              << ";amount:" << _amount 
              << ";nb_deposits:" << _nbDeposits 
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";p_amount:" << _amount;
    
    if (_amount < withdrawal) {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    
    _amount -= withdrawal;
    _nbWithdrawals++;
    
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    
    std::cout << ";withdrawal:" << withdrawal 
              << ";amount:" << _amount 
              << ";nb_withdrawals:" << _nbWithdrawals 
              << std::endl;
    return true;
}

int Account::checkAmount(void) const {
    return _amount;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";deposits:" << _nbDeposits 
              << ";withdrawals:" << _nbWithdrawals 
              << std::endl;
}
