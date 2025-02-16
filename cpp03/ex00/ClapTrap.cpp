/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:29:13 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/01 18:42:59 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(std::string name)
    : m_name(name), m_hit_points(default_hit_points), m_energy_points(default_energy_points), m_attack_damage(default_attack_damage) {
	std::cout << "A wild ClapTrap appears!\n";
    return;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap suddenly disappears...\n";
	return;
}

void ClapTrap::attack(const std::string& target) {
	if (m_hit_points <= 0) {
		std::cout << "ClapTrap is dead!..\n";
		return;
	} else if (m_energy_points <= 0) {
		std::cout << "Not enought energy...\n";
		return;
	}
	m_energy_points--;
	std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing " << m_attack_damage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (m_hit_points <= 0) {
		std::cout << "ClapTrap is already dead. Stop.\n";
		return;
	}
	std::cout << "ClapTrap " << m_name << " was attacked, and now lost " << amount << " hit points!\n";
	m_hit_points -= amount;
	if (m_hit_points <= 0) {
		std::cout << "ClapTrap " << m_name << " is down!\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (m_hit_points <= 0) {
		std::cout << "ClapTrap is already dead. Stop.\n";
		return;
	} else if (m_energy_points <= 0) {
		std::cout << "Not enought energy...\n";
		return;
	}
	m_energy_points--;
	if (m_hit_points + amount > 10) {
		amount = 10 - m_hit_points;
	}
	std::cout << "ClapTrap " << m_name << " was repaired, and now gained " << amount << " hit points!\n";
	m_hit_points += amount;
}
