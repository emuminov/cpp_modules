/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:45:10 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/21 18:25:48 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed abs(Fixed f) { return f < Fixed(0) ? f * Fixed(-1) : f; }

/* formula for finding area of a triangle in coordinate geometry:
 * 0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) */
Fixed area(const Point a, const Point b, const Point c) {
    return abs(Fixed(0.5f) * (a.get_x() * (b.get_y() - c.get_y()) +
                              b.get_x() * (c.get_y() - a.get_y()) +
                              c.get_x() * (a.get_y() - b.get_y())));
}

/* point is in the triangle if the area of thee subtriangles created
 * with point p are equal to the area of the whole triangle:
 * A = A1 + A2 + A3*/
bool bsp(const Point a, const Point b, const Point c, const Point p) {
    Fixed triangle_area = area(a, b, c);
    return (triangle_area == (area(p, b, c) + area(a, p, c) + area(a, b, p)));
}
