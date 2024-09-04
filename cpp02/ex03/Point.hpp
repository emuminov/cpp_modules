/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:35:40 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/10 22:49:07 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
class Point {
  public:
    Point();
    Point(Fixed x, Fixed y);
    Point(const Point& p);
    Point& operator=(const Point& p);
    ~Point();
    const Fixed& get_x() const;
    const Fixed& get_y() const;

  private:
    const Fixed m_x;
    const Fixed m_y;
};

#endif
