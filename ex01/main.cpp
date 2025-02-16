/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <emuminov@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:47:27 by emuminov          #+#    #+#             */
/*   Updated: 2024/05/08 19:25:32 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

enum column_position {
	START,
	BETWEEN,
	END,
};

std::string ask_for_command() {
  std::string command{};
  std::cout << "Enter a new command: ";
  if (!std::getline(std::cin >> std::ws, command))
	  exit(EXIT_SUCCESS);
  return command;
}

std::string ask_for_contact_field(std::string field_name) {
	std::cout << "Please enter " << field_name << ": ";
	std::string field_data {};
	if (!std::getline(std::cin >> std::ws, field_data))
		exit(EXIT_SUCCESS);
	return field_data;
}

void add(PhoneBook& pb) {
	Contact c {Contact()};
	if (!c.set_first_name(ask_for_contact_field("first name"))) {
		std::cout << "Invalid first name!\n";
		return;
	}
	if (!c.set_last_name(ask_for_contact_field("last name"))) {
		std::cout << "Invalid last name!\n";
		return;
	}
	if (!c.set_nickname(ask_for_contact_field("nickname"))) {
		std::cout << "Weird nickname!\n";
		return;
	}
	if (!c.set_phone_number(ask_for_contact_field("phone number"))) {
		std::cout << "Phone number is no good.\n";
		return;
	}
	if (!c.set_darkest_secret(ask_for_contact_field("darkest secret"))) {
		std::cout << "Ohoho! Bad dark secret.\n";
		return;
	}
	std::cout << "Added new contact!\n";
	pb.add_contact(c);
	std::cout << "Len is: " << pb.get_len() << '\n';
}

void display_column(int s, enum column_position pos) {
	if (pos == START)
		std::cout << '|';
	std::cout << std::setw(10) << std::right << s << '|';
	if (pos == END)
		std::cout << '\n';
}

void display_column(const std::string& s, enum column_position pos) {
	std::string s_to_print {};
	if (s.size() > 10) {
		s_to_print = s.substr(0, 9);
		s_to_print += '.';
	} else
		s_to_print = s;
	if (pos == START)
		std::cout << '|';
	std::cout << std::setw(10) << std::right << s_to_print << '|';
	if (pos == END)
		std::cout << '\n';
}

void display_contact_field(const char* msg, const std::string& field) {
	std::cout << msg << field << "\n";
}

void display_all_contact_fields(Contact& c) {
	display_contact_field("First name:   ", c.get_first_name());
	display_contact_field("Last name:    ", c.get_last_name());
	display_contact_field("Nickname:     ", c.get_nickname());
	display_contact_field("Phone number: ", c.get_phone_number());
	display_contact_field("Darkest:      ", c.get_darkest_secret());
}

void search(PhoneBook& pb) {
	display_column("Index", START);
	display_column("First name", BETWEEN);
	display_column("Last name", BETWEEN);
	display_column("Nickname", END);
	int len = pb.get_len();
	for (int i = 0; i < len; i++) {
		display_column(i + 1, START);
		display_column(pb.get_contact(i).get_first_name(), BETWEEN);
		display_column(pb.get_contact(i).get_last_name(), BETWEEN);
		display_column(pb.get_contact(i).get_nickname(), END);
	}
	std::cout << "Please choose an entry with the correct index: ";
	std::string str_index {};
	if (!std::getline(std::cin >> std::ws, str_index))
		exit(EXIT_SUCCESS);
	int nbr_index = std::atoi(str_index.c_str());
	if (str_index.length() > 1 || !std::isdigit(str_index[0]) || !(nbr_index >= 1 && nbr_index <= len)) {
		std::cout << "Incorrect index!\n";
		return;
	}
	Contact c = pb.get_contact(nbr_index - 1);
	display_all_contact_fields(c);
}

void execute_command(std::string command, PhoneBook& pb) {
	if (command == "ADD") {
		add(pb);
	} else if (command == "SEARCH") {
		search(pb);
	} else if (command == "EXIT") {
		exit(EXIT_SUCCESS);
	};
	return;
}

int main(void) {
  PhoneBook pb{PhoneBook()};
  while (true) {
	  std::string command = ask_for_command();
	  execute_command(command, pb);
  }
  return 0;
}
