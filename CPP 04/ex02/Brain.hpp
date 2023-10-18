/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:11:49 by qdenizar          #+#    #+#             */
/*   Updated: 2023/10/06 15:19:35 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
    protected:
    
    std::string ideas[100];

    public:
    //Orthodox Canonical Form
    Brain(); //default constructor
    Brain(const Brain&	newBrain); //cpy constructor
    Brain& operator=(Brain const & objectToCopy); //Copy assignment operator
    ~Brain(); //destructor

    void setIdeas(std::string ideas, std::string ideas2);
    void getIdeas();

};

#endif