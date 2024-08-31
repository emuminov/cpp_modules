#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(
		"Robotomy request form",
		signing_grade,
		executing_grade
	), m_target(target) { return; }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& scf) : AForm(scf), m_target(scf.m_target) { return; }

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& scf) {
	if (&scf == this)
		return *this;
	this->m_target = scf.m_target;
	return *this;
}

void RobotomyRequestForm::do_execution() const {
	srand(time(NULL));
	int n = rand();
	if ((n % 2) == 0) {
		std::cout << m_target << " was robotomized successefully!\n";
		return;
	}
	std::cout << "Robotomy on " << m_target << " failed...\n";
}

RobotomyRequestForm::~RobotomyRequestForm() { return; }
