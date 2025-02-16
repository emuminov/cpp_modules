/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:39:18 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/19 19:30:09 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(const Point a, const Point b, const Point c, const Point p);

void test_bsp(const Point a, const Point b, const Point c, const Point p)
{
    if (bsp(a, b, c, p))
    {
        std::cout << p.get_x() << " " << p.get_y() << " is inside the triangle.\n";
    }
    else
    {
        std::cout << p.get_x() << " " << p.get_y() << " is not inside the triangle.\n";
    }
}

int main(void)
{
    Point a(0, 0);
    Point b(0, 5);
    Point c(5, 0);

    Point p1(2, 2);
    Point p2(10, 0);
    Point p3(0, 1);
    Point p4(5, 1);
    Point p5(2, 3);
    Point p6(2, 3.5f);

    test_bsp(a, b, c, p1);
    test_bsp(a, b, c, p2);
    test_bsp(a, b, c, p3);
    test_bsp(a, b, c, p4);
    test_bsp(a, b, c, p5);
    test_bsp(a, b, c, p6);
}
