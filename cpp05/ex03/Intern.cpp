#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() { return; }

Intern::Intern(const Intern& i) { (void)i; return; }

Intern& Intern::operator=(const Intern& i) { (void)i; return *this; }

Intern::~Intern() { return; }

AForm* Intern::make_robotomy_request_form(const std::string& target) const {
	return new RobotomyRequestForm(target);
}

AForm* Intern::make_presidential_pardon_form(const std::string& target) const {
	return new PresidentialPardonForm(target);
}

AForm* Intern::make_shrubbery_creation_form(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& target_form_name, const std::string& target) const {
	const t_form_creator form_creators[] = {
		{ "robotomy request", &Intern::make_robotomy_request_form },
		{ "presidential pardon", &Intern::make_presidential_pardon_form },
		{ "shrubbery creation", &Intern::make_shrubbery_creation_form }
	};

	int i = 0;
	int l = ((int)sizeof(form_creators) / (int)sizeof(t_form_creator));
	while ((i < l && (form_creators[i].name != target_form_name))) { i++; }

	switch (i) {
		case 0:
		case 1:
		case 2:
			std::cout << "Intern creates " << target_form_name << "form\n";
			return (this->*form_creators[i].create_form)(target);

		default:
			throw InvalidFormNameException();
	}
}

const char* Intern::InvalidFormNameException::what() const throw() {
	return "Invalid form name";
}
