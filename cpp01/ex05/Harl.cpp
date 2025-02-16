/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:19:15 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/22 13:51:11 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl() { return; }

Harl::~Harl() { return; }

void Harl::complain(std::string level)
{
    size_t hash = 0;
    size_t len = level.length();
    for (size_t i = 0; i < len; i++)
    {
        hash = hash + level[i] + len;
        hash ^= 13;
    }
    enum LevelsHash
    {
        debug = 373,
        info = 314,
        warning = 530,
        error = 384,
    };

    void (Harl::*fn)(void);
    switch (hash)
    {
    case debug:
        fn = &Harl::debug;
        break;
    case info:
        fn = &Harl::info;
        break;
    case warning:
        fn = &Harl::warning;
        break;
    case error:
        fn = &Harl::error;
        break;
    default:
        std::cerr << "[complain complain]\n";
        return;
    }
    (this->*fn)();
}

void Harl::debug(void)
{
    std::cout << "[DEBUG]\n";
    std::cout << "I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-special-ketchup burger. I "
                 "really do!"
              << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You "
                 "didn’t put enough bacon in my burger! If you did, I wouldn’t "
                 "be asking for more!"
              << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]\n";
    std::cout << "I think I deserve to have some extra bacon for free. I’ve "
                 "been coming for years whereas you started working here since last "
                 "month."
              << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
