/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:24:21 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/11 15:28:03 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
#define APP_H
#include "PhoneBook.hpp"

enum column_position {
    START,
    BETWEEN,
    END,
};

// add.cpp
void add(PhoneBook& pb);

// search.cpp
void search(PhoneBook& pb);

// common.cpp
void exit_phonebook();
void input_command(std::string* s);
std::string ask_for_command();
#endif
