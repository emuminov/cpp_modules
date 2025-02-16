/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:25:43 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/18 17:38:46 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string name) : name(name),  weapon(NULL) {
	return;
}

HumanB::~HumanB() {
	return;
}

void HumanB::attack() const {
	if (weapon) {
		std::cout << this->name << " attacks with their " << this->weapon->getType() << '\n';
	} else {
		std::cout << this->name << " attacks with their " << "fist" << '\n';
	}
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}
