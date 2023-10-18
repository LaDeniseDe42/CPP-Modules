/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:58:47 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/29 11:15:44 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP


#include "Fixed.hpp"

class Point
{
private:
    const Fixed x_;
    const Fixed y_;

public:
    Point();
    Point(const float x, const float y);
    Point(const Point& newPoint);

    ~Point();

    Fixed getX() const;
    Fixed getY() const;

    Point& operator=(const Point &obj);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif