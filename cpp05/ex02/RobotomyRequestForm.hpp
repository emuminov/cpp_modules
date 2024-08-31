#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& scf);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& scf);
		~RobotomyRequestForm();

	private:
		std::string m_target;
		static const int signing_grade = 72;
		static const int executing_grade = 45;
		void do_execution() const;
};
#endif
