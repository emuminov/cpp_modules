/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:33:41 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/15 12:42:26 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    std::string result = argv[1];
    for (int i = 2; i < argc; i++) {
        result += argv[i];
	}
    for (unsigned long i = 0; i < result.size(); i++) {
        std::cout << toupper(result[i]);
	}
	std::cout << std::endl;
    return 0;
}
