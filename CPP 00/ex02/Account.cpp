/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:51:30 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/18 10:04:56 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//constructeur
Account::Account(int initial_deposit)
{
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts -1;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

//destructeur
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	_nbAccounts--;
}

//Affiche les infos sur la date et l 'heure
void	Account::_displayTimestamp( void )
{
	std::time_t actualTimeInSec = std::time(0);
	std::tm		*convertActualInRealtime = std::localtime(&actualTimeInSec);
	std::cout << "[" << (convertActualInRealtime->tm_year + 1900);
	std::cout << ((convertActualInRealtime->tm_mon + 1) < 10 ? "0" : "") << (convertActualInRealtime->tm_mon + 1);
	std::cout << (convertActualInRealtime->tm_mday < 10 ? "0" : "") << convertActualInRealtime->tm_mday;
	std::cout << "_";
	std::cout << (convertActualInRealtime->tm_hour < 10 ? "0" : "") << convertActualInRealtime->tm_hour ;
	std::cout << (convertActualInRealtime->tm_min < 10 ? "0" : "") << convertActualInRealtime->tm_min;
	std::cout << (convertActualInRealtime->tm_sec < 10 ? "0" : "") << convertActualInRealtime->tm_sec;
	std::cout << "]";
}

//Cette fonction permet de récupérer le nombre total de comptes bancaires créés dans le système.
int	Account::getNbAccounts( void )
{
	return(_nbAccounts);
}

//permet de récupérer le montant total d'argent dans tous les comptes bancaires du système.
int	Account::getTotalAmount( void )
{
	return(_totalAmount);
}
//permet de récupérer le nombre total de dépôts effectués dans tous les comptes bancaires du système.
int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
}

//permet de récupérer le nombre total de retraits effectués dans tous les comptes bancaires du système.
int	Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
}

//affiche des informations globales sur les comptes bancaires, notamment le nombre total de comptes,
// le montant total, le nombre total de dépôts et le nombre total de retraits.
void	Account::displayAccountsInfos( void )
{
	//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" <<_totalNbWithdrawals << std::endl;
}

//permet de faire un dépôt sur le compte bancaire. Elle prend en paramètre le montant à déposer.
void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << this->_amount;
	_totalAmount += deposit;
	this->_nbDeposits++;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
	_totalNbDeposits++;
}

//permet de faire un retrait du compte bancaire. Elle prend en paramètre le montant à retirer.
// Elle retourne true si le retrait est réussi et false si le solde est insuffisant.
bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_amount >= withdrawal)
	{
		_displayTimestamp();
		std::cout << " index:" << this->_accountIndex;
		std::cout << ";p_amount:" << this->_amount;
		std::cout << ";withdrawal:" << withdrawal;
		this->_amount -= withdrawal;
		std::cout << ";amount:" << this->_amount;
		this->_nbWithdrawals++;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return (true);
	}
	else
	{
		_displayTimestamp();
		std::cout << " index:" << this->_accountIndex;
		std::cout << ";p_amount:" << this->_amount;
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
}

//permet de vérifier le solde actuel du compte bancaire sans le modifier. Elle retourne le montant actuel.
int		Account::checkAmount( void ) const
{
	return(this->_amount);
}

//ffiche des informations sur l'état du compte bancaire, notamment l'indice du compte, le montant,
// le nombre de dépôts et le nombre de retraits.
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;

}
