/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:35:28 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/18 19:28:33 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

Point::Point() : m_x(0), m_y(0) { return; }

Point::Point(Fixed x, Fixed y) : m_x(x), m_y(y) { return; }

Point::~Point() { return; }

Point::Point(const Point& p) : m_x(p.m_x), m_y(p.m_y) { return; }

Point& Point::operator=(const Point& p)
{
    (void)p;
    std::cerr << "Error! Cannot copy assign.\n";
    return *this;
}

const Fixed& Point::get_x() const { return m_x; }

const Fixed& Point::get_y() const { return m_y; }
