/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:43:03 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/07 18:53:08 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "iostream"

Contact::Contact()
    : first_name(""), last_name(""), nickname(""), phone_number(""),
      darkest_secret("") {
  return;
}

Contact::~Contact() { return; }

bool Contact::set_first_name(std::string first_name) {
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

std::string Contact::get_first_name() { return this->first_name; }

std::string Contact::get_last_name() { return this->last_name; }

std::string Contact::get_nickname() { return this->nickname; }

std::string Contact::get_phone_number() { return this->phone_number; }

std::string Contact::get_darkest_secret() { return this->darkest_secret; }
