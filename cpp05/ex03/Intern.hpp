#ifndef INTERN_HPP
#define INTERN_HPP
#include <exception>
#include <string>
class AForm;
class Intern {
	public:
		Intern();
		Intern(const Intern& i);
		Intern& operator=(const Intern& i);
		~Intern();

		AForm* makeForm(const std::string& form_name, const std::string& target) const;

		class InvalidFormNameException : public std::exception {
			virtual const char* what() const throw();
		};
};
#endif
