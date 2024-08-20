#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

void Form::check_grade(int grade) {
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(std::string name, int signing_grade, int executing_grade) :
	m_name(name),
	m_signing_grade(signing_grade),
	m_executing_grade(executing_grade),
	m_is_signed(false) {
	check_grade(m_signing_grade);
	check_grade(m_executing_grade);
}

Form::Form(const Form& f) :
	m_name(f.m_name),
	m_signing_grade(f.m_signing_grade),
	m_executing_grade(f.m_executing_grade),
	m_is_signed(f.m_is_signed) {
	return;
}

Form& Form::operator=(const Form& f) {
	if (&f == this)
		return *this;
	m_is_signed = f.m_is_signed;
	return *this;
}

Form::~Form() { return; }

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > m_signing_grade)
		throw Form::GradeTooLowException();
	m_is_signed = true;
}

const std::string& Form::get_name() const { return m_name; }

bool Form::get_is_signed() const { return m_is_signed; }

int Form::get_signing_grade() const { return m_signing_grade; }

int Form::get_executing_grade() const { return m_executing_grade; }

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream &o, const Form &f) {
	if (!f.get_is_signed()) {
		std::cout << "Form " << f.get_name() 
			<< " can be signed by a bureaucrat of grade "
			<< f.get_signing_grade()
			<< " and executed by bureaucrat of grade "
			<< f.get_executing_grade();
	} else {
		std::cout << "Form " << f.get_name() 
			<< " is already signed";
	}
	return o;
}
