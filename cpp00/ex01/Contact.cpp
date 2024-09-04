/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:15:57 by emuminov          #+#    #+#             */
/*   Updated: 2024/06/17 02:07:07 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
    : first_name(""), last_name(""), nickname(""), phone_number(""),
      darkest_secret("") {
    return;
}

Contact::~Contact() { return; }

bool Contact::set_first_name(const std::string& first_name) {
    if (first_name == "")
        return false;
    this->first_name = first_name;
    return true;
}

bool Contact::set_last_name(std::string last_name) {
    if (last_name == "")
        return false;
    this->last_name = last_name;
    return true;
}

bool Contact::set_nickname(std::string nickname) {
    if (nickname == "")
        return false;
    this->nickname = nickname;
    return true;
}

bool Contact::set_phone_number(std::string phone_number) {
    if (phone_number == "")
        return false;
    this->phone_number = phone_number;
    return true;
}

bool Contact::set_darkest_secret(std::string darkest_secret) {
    if (darkest_secret == "")
        return false;
    this->darkest_secret = darkest_secret;
    return true;
}

std::string Contact::get_first_name() const { return this->first_name; }

std::string Contact::get_last_name() const { return this->last_name; }

std::string Contact::get_nickname() const { return this->nickname; }

std::string Contact::get_phone_number() const { return this->phone_number; }

std::string Contact::get_darkest_secret() const { return this->darkest_secret; }
