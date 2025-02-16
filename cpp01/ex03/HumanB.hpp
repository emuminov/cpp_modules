/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:24:26 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/17 16:15:49 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
#include <string>

class HumanB {
  public:
    HumanB(std::string name);
    ~HumanB();
    void setWeapon(Weapon& w);
    void attack() const;

  private:
    std::string name;
    Weapon* weapon;
};
#endif
