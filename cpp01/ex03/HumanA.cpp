/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:09:52 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/18 17:35:07 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
    return;
}

HumanA::~HumanA() { return; }

void HumanA::attack() const {
    std::cout << this->name << " attacks with their " << this->weapon.getType()
              << '\n';
}
