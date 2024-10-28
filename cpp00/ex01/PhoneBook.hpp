/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:46:39 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/11 15:24:26 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.hpp"

class PhoneBook
{
  public:
    PhoneBook();
    ~PhoneBook();
    void add_contact(Contact c);
    Contact get_contact(unsigned int index) const;
    unsigned int get_len() const;

  private:
    unsigned int _contacts_pointer;
    unsigned int _len;
    Contact _contacts[8];
};
#endif
