/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:39:13 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/28 16:57:04 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed {
public:
	Fixed(void);
	Fixed(int nbr);
	Fixed(const Fixed& f);
	Fixed &operator=(const Fixed& f);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _raw;
	static const int fractional_bits = 8;
};

