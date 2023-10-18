/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:44:56 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/29 14:20:34 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(void)
{
	const Point a(-2, 6);
	const Point b(10, 2);
	const Point c(2, -3);
	const Point point(3, -1);
	const Point point2(1, 6);

	std::cout << "Coordonate of Point A x= " << a.getX() << " and y= " << a.getY() << std::endl;
	std::cout << "Coordonate of Point B x= " << b.getX() << " and y= " << b.getY() << std::endl;
	std::cout << "Coordonate of Point C x= " << c.getX() << " and y= " << c.getY() << std::endl;
	std::cout << std::endl;
	std::cout << "Coordonate of Point x= "<< point.getX() << " and y= " << point.getY() << std::endl;

	if (bsp(a, b, c, point) == true)
		std::cout << "\033[32m This is good, point is inside the triangle because the result is TRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31m No, point is not inside the triangle because the result is FALSE or The coordinate of the searched point is the same as that of one of the vertices of the triangle\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "Concerning Point2:" << std::endl; 
	std::cout << "Coordonate of Point2 x= "<< point2.getX() << " and y= " << point2.getY() << std::endl;
	if (bsp(a, b, c, point2) == true)
		std::cout << "\033[32m This is good, point2 is inside the triangle because the result is TRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31m No, point2 is not inside the triangle because the result is FALSE or The coordinate of the searched point is the same as that of one of the vertices of the triangle\033[0m " << std::endl;
	return (0);
}