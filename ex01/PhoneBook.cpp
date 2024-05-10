/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:19:13 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/10 16:19:26 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contacts_pointer(0), _len(0) { return; }

PhoneBook::~PhoneBook() { return; }

void PhoneBook::add_contact(Contact contact) {
    this->_contacts[this->_contacts_pointer] = contact;
    this->_contacts_pointer++;
    if (this->_contacts_pointer >= 8)
        this->_contacts_pointer = 0;
    if (this->_len < 8)
        this->_len++;
    return;
}

Contact PhoneBook::get_contact(unsigned int index) {
    if (index > this->_len - 1) {
        return this->_contacts[this->_len - 1];
    }
    return this->_contacts[index];
}

unsigned int PhoneBook::get_len() { return this->_len; }
