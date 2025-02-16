/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:04:15 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/17 15:54:37 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>

class Weapon {
  public:
    Weapon(std::string type);
    ~Weapon();
    const std::string& getType();
    void setType(std::string type);

  private:
    std::string type;
};
#endif
