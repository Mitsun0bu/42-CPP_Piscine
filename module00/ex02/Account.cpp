/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:58:55 by llethuil          #+#    #+#             */
/*   Updated: 2022/07/04 13:23:00 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	To test this programm, compile with :
		c++ tests.cpp Account.cpp -o tests.exe
	And run with :
		./test.exe
	Compare the output with log.txt
*/

# include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* Constructor of Account class */
Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	static int i = 0;

	_displayTimestamp();

	_accountIndex = i;
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts ++;
	_totalAmount += _amount;
	i ++;
	return ;
}

/* Destructor of Account class */
Account::~Account(void)
{
	_displayTimestamp();

	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
	return ;
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();

	std::cout << " accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposit:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount = this->_amount;
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits ++;

	_displayTimestamp();

	std::cout << " index:" << this->_accountIndex
			<< ";p_amount:" << p_amount
			<< ";deposit:" << deposit
			<< ";amount:" << this->_amount
			<< ";nb_deposits:" << this->_nbDeposits << std::endl;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount = this->_amount;

	if (withdrawal < this->_amount)
	{
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		this->_nbWithdrawals ++;

		_displayTimestamp();

		std::cout << " index:" << this->_accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << this->_amount
			<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		_displayTimestamp();

		std::cout << " index:" << this->_accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawals:refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount(void) const
{
	return (0);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();

	std::cout << " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

void	Account::_displayTimestamp(void)
{
	time_t	now = time(0);
	tm		*local_time = localtime(&now);

	std::cout << "[" << 1900 + local_time->tm_year;
	std::cout << std::setw(2) << std::setfill('0') << 1 + local_time->tm_mon;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_mday;
	std::cout << "_"<< std::setw(2) << std::setfill('0') << local_time->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_sec << "]";
}
