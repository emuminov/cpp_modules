/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:16:08 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/18 16:35:51 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "str:       " << std::hex << &str << '\n';
	std::cout << "stringPTR: " << std::hex << stringPTR << '\n';
	std::cout << "stringREF: " << std::hex << &stringREF << '\n';

	std::cout << "str:       " << str << '\n';
	std::cout << "stringPTR: " << *stringPTR << '\n';
	std::cout << "stringREF: " << stringREF << '\n';
	return 0;
}
