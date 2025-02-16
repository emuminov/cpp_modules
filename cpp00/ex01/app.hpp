/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:24:21 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/10 19:52:21 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
#define APP_H
#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>

enum column_position {
    START,
    BETWEEN,
    END,
};

// add.cpp
void add(PhoneBook &pb);

// search.cpp
void search(PhoneBook &pb);

// common.cpp
void exit_phonebook();
void input_command(std::string* s);
std::string ask_for_command();
#endif
