/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:58:28 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/29 11:11:44 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

                                            //CONSTRUCTOR
                                            
//default constructor
Point::Point() : x_(0) , y_(0)
{

}

//Constructor that takes as parameters two constant floating-point numbers.
//And initializes X and Y
Point::Point(const float x, const float y) : x_(x) , y_(y)
{

}



//Copy constructor
Point::Point(const Point& newPoint) : x_(newPoint.x_), y_(newPoint.y_)
{ 
    
}

                                            //operator overload
                                    
Point& Point::operator=(const Point &obj)
{
    if (this != &obj)
    {
        (Fixed) this->x_ = obj.getX();
        (Fixed) this->y_ = obj.getY();
    }
    return (*this);
}

                                            //FUNCTIONS



Fixed Point::getX() const
{
    return (this->x_);
}

Fixed Point::getY() const
{
    return (this->y_);
}



                                            //DESTRUCTOR
Point::~Point()
{

}