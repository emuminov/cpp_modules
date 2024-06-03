/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:30:16 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/03 13:44:13 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void) {
    FragTrap ft1("Leonard");
    FragTrap ft2(ft1);
    FragTrap ft3 = ft1;
    std::string target = "training dummy";
    ft3.attack(target);
    ft3.attack(target);
    ft3.attack(target);
    ft3.attack(target);
    ft3.attack(target);
    ft3.takeDamage(8);
    ft3.beRepaired(3);
    ft3.beRepaired(15);
    ft3.attack(target);
    ft3.attack(target);
    ft3.attack(target);
    ft3.attack(target);
    ft3.attack(target);
    ft3.attack(target);
    ft3.takeDamage(17);
    ft3.attack(target);
    return 0;
}
