/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:38:07 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/22 17:22:20 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stack>
#include <iostream>
#include "MutantStack.hpp"
#include <vector>

int main()
{

//main fournis
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
//std::stack<int, std::vector<int> > a;
//mes tests
MutantStack<char> Axel;
for(int i = 0; i != 26; i++)
{
    Axel.push('a' + i);
}
for(MutantStack<char>::iterator it2 = Axel.begin(); it2 != Axel.end(); it2++)
{
    std::cout << "\033[0;33m" << *it2 << "\033[0m ... ";
}
std::cout << std::endl;

MutantStack<float> test3;
test3.push(42.42);
MutantStack<float> test4(test3);
test4.push(84.84);
for(MutantStack<float>::iterator its2 = test4.begin(); its2 != test4.end(); its2++)
{
    std::cout << "\033[0;33m" << *its2 << "\033[0m ... ";
}
std::cout << std::endl;






return 0;
}