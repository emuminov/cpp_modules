/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:19:15 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/20 19:55:17 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl() { return; }

Harl::~Harl() { return; }

void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*fns[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
                                  &Harl::error};
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            return (this->*fns[i])();
        }
    }
    std::cerr << "Wrong debug level!";
}

void Harl::debug(void) {
    std::cout << "I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-special-ketchup burger. I "
                 "really do!"
              << std::endl;
}

void Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money. You "
                 "didn’t put enough bacon in my burger! If you did, I wouldn’t "
                 "be asking for more!"
              << std::endl;
}

void Harl::warning(void) {
    std::cout
        << "I think I deserve to have some extra bacon for free. I’ve "
           "been coming for years whereas you started working here since last "
           "month."
        << std::endl;
}

void Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}
