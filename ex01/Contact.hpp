/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:43:04 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/10 17:17:28 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H
#include <string>

class Contact {
  public:
    Contact();
    ~Contact();
    bool set_first_name(std::string first_name);
    bool set_last_name(std::string last_name);
    bool set_nickname(std::string nickname);
    bool set_phone_number(std::string phone_number);
    bool set_darkest_secret(std::string darkest_secret);
    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_nickname() const;
    std::string get_phone_number() const;
    std::string get_darkest_secret() const;

  private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
};
#endif
