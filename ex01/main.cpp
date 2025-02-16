/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:16:51 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/10 17:18:12 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.hpp"

void execute_command(std::string command, PhoneBook &pb) {
    if (command == "ADD")
        add(pb);
    else if (command == "SEARCH")
        search(pb);
    else if (command == "EXIT")
        exit_phonebook();
    return;
}

int main(void) {
    PhoneBook pb = PhoneBook();
    while (true) {
        std::string command = ask_for_command();
        execute_command(command, pb);
    }
    return 0;
}
