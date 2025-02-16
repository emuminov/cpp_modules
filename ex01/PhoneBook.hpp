/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:46:39 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/10 16:19:30 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "iostream"

class PhoneBook {
  public:
    PhoneBook();
    ~PhoneBook();
    void add_contact(Contact c);
    Contact get_contact(unsigned int index);
    unsigned int get_len();

  private:
    unsigned int _contacts_pointer;
    unsigned int _len;
    Contact _contacts[8];
};
