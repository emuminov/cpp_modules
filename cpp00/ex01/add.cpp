/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:23:38 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/11 15:25:46 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.hpp"
#include <iostream>

static std::string ask_for_contact_field(const std::string& field_name) {
    std::string field_data = "";
    std::cout << "Please enter " << field_name << ": ";
    input_command(&field_data);
    return field_data;
}

void add(PhoneBook& pb) {
    Contact c = Contact();
    if (!c.set_first_name(ask_for_contact_field("first name"))) {
        std::cout << "Invalid first name!\n";
        return;
    }
    if (!c.set_last_name(ask_for_contact_field("last name"))) {
        std::cout << "Invalid last name!\n";
        return;
    }
    if (!c.set_nickname(ask_for_contact_field("nickname"))) {
        std::cout << "Weird nickname!\n";
        return;
    }
    if (!c.set_phone_number(ask_for_contact_field("phone number"))) {
        std::cout << "Phone number is no good.\n";
        return;
    }
    if (!c.set_darkest_secret(ask_for_contact_field("darkest secret"))) {
        std::cout << "Ohoho! Bad dark secret.\n";
        return;
    }
    std::cout << "Added new contact!\n";
    pb.add_contact(c);
}
