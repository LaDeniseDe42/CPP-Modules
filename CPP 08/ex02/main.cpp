/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:38:07 by qdenizar          #+#    #+#             */
/*   Updated: 2023/11/23 09:37:34 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stack>
#include <iostream>
#include "MutantStack.hpp"
#include <vector>

int main()
{
std::cout << "\033[1mTEST AVEC LE MAIN FOURNIS\033[0m " << std::endl;
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
std::cout << std::endl;


std::cout << "\033[1mTEST AVEC CHAR \033[0m" << std::endl;
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
std::cout << std::endl;

std::cout << "\033[1mTEST AVEC DES FLOATS ET COPY OPERATOR \033[0m" << std::endl;
MutantStack<float> test3;
test3.push(42.42);
MutantStack<float> test4(test3);
test4.push(84.84);
for(MutantStack<float>::iterator its2 = test4.begin(); its2 != test4.end(); its2++)
{
    std::cout << "\033[0;33m" << *its2 << "\033[0m ... ";
}
std::cout << std::endl;
std::cout << std::endl;

std::cout << "\033[1mTEST AVEC STRING\033[0m" << std::endl;
MutantStack<std::string> testString;
testString.push("Patate");
testString.push("Gants");
testString.push("Souris");
testString.push("stop");
testString.push("popMePlease");
testString.pop();
for(MutantStack<std::string>::iterator its2 = testString.begin(); its2 != testString.end(); its2++)
{
    std::cout << "\033[0;33m" << *its2 << "\033[0m ... ";
}
std::cout << std::endl;
std::cout << std::endl;


return 0;
}