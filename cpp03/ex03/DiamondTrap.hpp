/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:22:01 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/23 18:23:14 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
  public:
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap& dt);
    DiamondTrap& operator=(const DiamondTrap& dt);
    ~DiamondTrap();
	using FragTrap::attack;
    void whoAmI();

  private:
    std::string m_name;
};
#endif
