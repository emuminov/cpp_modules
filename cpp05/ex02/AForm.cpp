#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

void AForm::check_grade(int grade) {
	if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(std::string name, int signing_grade, int executing_grade) :
	m_name(name),
	m_signing_grade(signing_grade),
	m_executing_grade(executing_grade),
	m_is_signed(false) {
	check_grade(m_signing_grade);
	check_grade(m_executing_grade);
}

AForm::AForm(const AForm& f) :
	m_name(f.m_name),
	m_signing_grade(f.m_signing_grade),
	m_executing_grade(f.m_executing_grade),
	m_is_signed(f.m_is_signed) {
	return;
}

AForm& AForm::operator=(const AForm& f) {
	if (&f == this)
		return *this;
	m_is_signed = f.m_is_signed;
	return *this;
}

AForm::~AForm() { return; }

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > m_signing_grade)
		throw AForm::GradeTooLowException();
	m_is_signed = true;
}

const std::string& AForm::get_name() const { return m_name; }

bool AForm::get_is_signed() const { return m_is_signed; }

int AForm::get_signing_grade() const { return m_signing_grade; }

int AForm::get_executing_grade() const { return m_executing_grade; }


void AForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > m_executing_grade)
		throw GradeTooLowException();
	if (!m_is_signed)
		throw NotSignedException();
	do_execution();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char* AForm::NotSignedException::what() const throw() {
	return "The form is not signed";
}

std::ostream& operator<<(std::ostream &o, const AForm &f) {
	if (!f.get_is_signed()) {
		std::cout << "Form " << f.get_name() 
			<< " can be signed by a bureaucrat of grade "
			<< f.get_signing_grade()
			<< " and executed by bureaucrat of grade "
			<< f.get_executing_grade();
	} else {
		std::cout << "AForm " << f.get_name() 
			<< " is already signed";
	}
	return o;
}
