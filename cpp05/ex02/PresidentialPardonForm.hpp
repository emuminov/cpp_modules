#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& scf);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& scf);
		~PresidentialPardonForm();

	private:
		std::string m_target;
		static const int signing_grade = 25;
		static const int executing_grade = 5;
		void do_execution() const;
};
#endif
