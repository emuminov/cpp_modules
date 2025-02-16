/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:37:46 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/03 13:38:42 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
  public:
    FragTrap(std::string name);
    FragTrap(const FragTrap& st);
    FragTrap& operator=(const FragTrap& st);
    ~FragTrap();

    void highFiveGuys(void);
    void attack(const std::string& target);

  private:
    static const int default_hit_points = 100;
    static const int default_energy_points = 100;
    static const int default_attack_damage = 30;
};

#endif
