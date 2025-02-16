/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:28:36 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/11 15:29:04 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.hpp"
#include <iomanip>
#include <iostream>
#include <cstdlib>

static void display_row_borders() {
    std::cout << "+----------";
    std::cout << "+----------";
    std::cout << "+----------";
    std::cout << "+----------+\n";
}

static void display_cell_content(int s, enum column_position pos) {
    if (pos == START)
        std::cout << '|';
    std::cout << std::setw(10) << std::right << s << '|';
    if (pos == END)
        std::cout << '\n';
}

static void display_cell_content(const std::string &s,
                                 enum column_position pos) {
    std::string s_to_print = "";
    if (s.size() > 10) {
        s_to_print = s.substr(0, 9);
        s_to_print += '.';
    } else
        s_to_print = s;
    if (pos == START)
        std::cout << '|';
    std::cout << std::setw(10) << std::right << s_to_print << '|';
    if (pos == END) {
        std::cout << '\n';
    }
}

static void display_all_contact_fields(Contact &c) {
    std::cout << "First name:     " << c.get_first_name() << '\n';
    std::cout << "Last name:      " << c.get_last_name() << '\n';
    std::cout << "Nickname:       " << c.get_nickname() << '\n';
    std::cout << "Phone number:   " << c.get_phone_number() << '\n';
    std::cout << "Darkest secret: " << c.get_darkest_secret() << '\n';
}

void search(PhoneBook &pb) {
    display_row_borders();
    display_cell_content("Index", START);
    display_cell_content("First name", BETWEEN);
    display_cell_content("Last name", BETWEEN);
    display_cell_content("Nickname", END);
    display_row_borders();
    int len = pb.get_len();
    for (int i = 0; i < len; i++) {
        display_cell_content(i + 1, START);
        display_cell_content(pb.get_contact(i).get_first_name(), BETWEEN);
        display_cell_content(pb.get_contact(i).get_last_name(), BETWEEN);
        display_cell_content(pb.get_contact(i).get_nickname(), END);
    }
    if (len > 0)
        display_row_borders();
    std::cout << "Please choose an entry with the correct index: ";
    std::string str_index = "";
    input_command(&str_index);
    int nbr_index = std::atoi(str_index.c_str());
    if (str_index.length() > 1 || !std::isdigit(str_index[0]) ||
        !(nbr_index >= 1 && nbr_index <= len)) {
        std::cout << "Incorrect index!\n";
        return;
    }
    Contact c = pb.get_contact(nbr_index - 1);
    display_all_contact_fields(c);
}
