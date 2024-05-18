/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:09:37 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/18 17:36:40 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H
#include "Weapon.hpp"

class HumanA {
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	void attack() const;

private:
	std::string name;
	Weapon& weapon;
};
#endif
