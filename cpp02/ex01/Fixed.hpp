/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:39:13 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/30 16:27:01 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed {
  public:
    Fixed(void);
    Fixed(const int raw);
    Fixed(const float raw);
    Fixed(const Fixed& f);
    Fixed& operator=(const Fixed& f);
    ~Fixed(void);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

  private:
    int _raw;
    static const int scale = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);
