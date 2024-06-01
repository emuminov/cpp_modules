/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:30:12 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/01 18:45:25 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
  public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& ct);
    ClapTrap& operator=(const ClapTrap& ct);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
	
  protected:
    std::string m_name;
    int m_hit_points;
    int m_energy_points;
    int m_attack_damage;
	static const int default_hit_points = 10;
	static const int default_energy_points = 10;
	static const int default_attack_damage = 0;
};

#endif
