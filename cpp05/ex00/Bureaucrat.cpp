#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

void Bureaucrat::check_grade(int grade) {
	if (grade < highest_grade)
		throw GradeTooHighException();
	else if (grade > lowest_grade)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name),
	m_grade(grade) {
		check_grade(m_grade);
	}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : m_name(b.m_name),
	m_grade(b.m_grade) { return; }

Bureaucrat Bureaucrat::operator=(const Bureaucrat &b) {
	if (&b == this)
		return *this;
	m_grade = b.m_grade;
	return *this;
}

Bureaucrat::~Bureaucrat() { return; }

int Bureaucrat::getGrade() const { return m_grade; }

const std::string& Bureaucrat::getName() const { return m_name; };

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade cannot be higher than 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade cannot be lower than 150";
}

void Bureaucrat::increaseGrade() {
	check_grade(m_grade - 1);
	m_grade--;
}

void Bureaucrat::dereaseGrade() {
	check_grade(m_grade + 1);
	m_grade++;
}

std::ostream& operator<<(std::ostream &o, const Bureaucrat &b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << '\n';
	return o;
}
