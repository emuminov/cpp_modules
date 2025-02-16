/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:26:49 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/23 18:36:17 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name", FragTrap::default_hit_points,
               ScavTrap::default_energy_points,
               FragTrap::default_attack_damage),
      FragTrap(name), ScavTrap(name), m_name(name) {
    std::cout << "A wild DiamondTrap appears!\n";
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap suddenly disappears...\n";
    return;
}

DiamondTrap::DiamondTrap(const DiamondTrap& dt)
    : ClapTrap(dt.ClapTrap::m_name, FragTrap::default_hit_points,
               ScavTrap::default_energy_points,
               FragTrap::default_attack_damage),
      FragTrap(dt), ScavTrap(dt), m_name(dt.m_name) {
    std::cout << "DiamondTrap " << m_name << " clones itself!\n";
    return;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& ct) {
    m_name = ct.m_name;
    ClapTrap::m_name = ct.ClapTrap::m_name;
    std::cout << "DiamondTrap " << m_name << " clones itself!\n";
    return *this;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am... " << ClapTrap::m_name << "! No, wait... I am "
              << m_name << "!\n";
}
