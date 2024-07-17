/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:36:03 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/18 17:08:07 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void) {
    Zombie* horde = zombieHorde(5, "Joe");
    for (int i = 0; i < 5; i++) {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}
