/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:14:58 by qdenizar          #+#    #+#             */
/*   Updated: 2023/09/29 14:13:25 by qdenizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed VectorialResult(Point const one, Point const two, Point const point)
{
    return (((two.getX().toFloat() - one.getX().toFloat()) * (point.getY().toFloat() - one.getY().toFloat())) - ((two.getY().toFloat() - one.getY().toFloat()) * (point.getX().toFloat() - one.getX().toFloat())));
} 


//il faut faire le calcul du vecteur de chaque segment
// AB = (b.x - a.x) * (point.y - a.y) - (b.y - a.y) * (point.x - a.x);
// BC = (c.x - b.x) * (point.y - b.y) - (c.y - b.y) * (point.x - b.x);
// CA = (a.x - c.x) * (point.y - c.y) - (a.y - c.y) * (point.x - c.x);
//si les 3 resultats sont du meme signe, le point est dans le triangle
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    if ((VectorialResult(a, b, point) >= 0
    && VectorialResult(b, c, point) >= 0
    && VectorialResult(c, a , point) >= 0)
    || (VectorialResult(a, b, point) <= 0
    &&  VectorialResult(b, c, point) <= 0
    && VectorialResult(c, a , point) <= 0))
    {
    if ((point.getX() == a.getX() && point.getY() == a.getY())
    || (point.getX() == b.getX() && point.getY() == b.getY())
    || (point.getX() == c.getX() && point.getY() == c.getY()))
        {
            //std::cout << "The coordinate of the searched point is the same as that of one of the vertices of the triangle" << std::endl;
            return (false);
        }
     return (true);
    }
    return (false);
}