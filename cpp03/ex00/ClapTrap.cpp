/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:29:13 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/31 16:32:41 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "A wild ClapTrap appears!\n";
    return;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap suddenly disappears...\n";
	return;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_hit_points <= 0) {
		std::cout << "ClapTrap is dead!..\n";
		return;
	} else if (this->_energy_points <= 0) {
		std::cout << "Not enought energy...\n";
		return;
	}
	this->_energy_points--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points <= 0) {
		std::cout << "ClapTrap is already dead. Stop.\n";
		return;
	}
	std::cout << "ClapTrap " << this->_name << " was attacked, and now lost " << amount << " hit points!\n";
	this->_hit_points -= amount;
	if (this->_hit_points <= 0) {
		std::cout << "ClapTrap " << this->_name << " is down!\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hit_points <= 0) {
		std::cout << "ClapTrap is already dead. Stop.\n";
		return;
	} else if (this->_energy_points <= 0) {
		std::cout << "Not enought energy...\n";
		return;
	}
	this->_energy_points--;
	if (this->_hit_points + amount > 10) {
		amount = 10 - this->_hit_points;
	}
	std::cout << "ClapTrap " << this->_name << " was repaired, and now gained " << amount << " hit points!\n";
	this->_hit_points += amount;
}
