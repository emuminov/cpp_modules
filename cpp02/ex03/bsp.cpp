/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:45:10 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/10 23:32:55 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed sign(Point const a, Point const b, Point const c) {
	return (a.get_x() - c.get_x()) * (b.get_y() - c.get_y()) -
		(b.get_x() - c.get_x()) * (a.get_y() - c.get_y());
}

bool bsp(const Point a, const Point b, const Point c, const Point p) {
	Fixed d1 (sign(p, a, b));
	Fixed d2 (sign(p, b, c));
	Fixed d3 (sign(p, c, a));
	bool has_neg ((d1 < 0) || (d2 < 0) || (d3 < 0));
	bool has_pos ((d1 > 0) || (d2 > 0) || (d3 > 0));

	return !(has_neg && has_pos);
}
