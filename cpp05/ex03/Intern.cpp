#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() { return; }

Intern::Intern(const Intern& i) { (void)i; return; }

Intern& Intern::operator=(const Intern& i) { (void)i; return *this; }

Intern::~Intern() { return; }

AForm* Intern::makeForm(const std::string& form_name, const std::string& target) const {
	const char* form_names[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
	int i = 0;
	int l = ((int)sizeof(form_names) / (int)sizeof(char*));
	while ((i < l && (form_names[i] != form_name))) { i++; }
	switch (i) {
		case 0:
			std::cout << "Intern creates " << form_name << "form\n";
			return new RobotomyRequestForm(target); break;
		case 1:
			std::cout << "Intern creates " << form_name << "form\n";
			return new PresidentialPardonForm(target); break;
		case 2:
			std::cout << "Intern creates " << form_name << "form\n";
			return new ShrubberyCreationForm(target); break;
		default:
			throw InvalidFormNameException();
	}
}

const char* Intern::InvalidFormNameException::what() const throw() {
	return "Invalid form name";
}
