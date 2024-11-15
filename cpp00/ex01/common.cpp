/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:31:16 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/11 15:29:48 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.hpp"
#include <cstdlib>
#include <iostream>

void exit_phonebook()
{
    std::cout << "EXIT\n";
    exit(EXIT_SUCCESS);
}

void input_command(std::string* s)
{
    std::getline(std::cin, *s);
    if (!std::cin)
    {
        if (std::cin.eof())
            exit_phonebook();
        else
        {
            std::cout << "\nIO error\n";
            exit(EXIT_FAILURE);
        }
    }
}

std::string ask_for_command()
{
    std::string command = "";
    std::cout << "Enter a new command: ";
    input_command(&command);
    return command;
}
