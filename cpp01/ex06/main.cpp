/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:19:17 by emuminov          #+#    #+#             */
/*   Updated: 2024/07/17 16:28:31 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "*mumble mumble*\n";
        return EXIT_FAILURE;
    }
    Harl h = Harl();
    h.complain(argv[1]);
    return 0;
}
