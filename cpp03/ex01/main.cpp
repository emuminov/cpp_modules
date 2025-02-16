/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:30:16 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/23 18:51:57 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
    ScavTrap st1("Leonard");
    ScavTrap st2(st1);
    ScavTrap st3("Don");
    st3 = st1;
    std::string target = "training dummy";
    st3.attack(target);
    st3.attack(target);
    st3.attack(target);
    st3.attack(target);
    st3.attack(target);
    st3.takeDamage(8);
    st3.beRepaired(3);
    st3.beRepaired(15);
    st3.attack(target);
    st3.attack(target);
    st3.attack(target);
    st3.attack(target);
    st3.attack(target);
    st3.attack(target);
    st3.takeDamage(90);
    st3.attack(target);
    st3.takeDamage(90);
    st3.attack(target);
    return 0;
}
