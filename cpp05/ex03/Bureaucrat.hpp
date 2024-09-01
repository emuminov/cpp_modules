#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <exception>
class AForm;
class Bureaucrat {
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& b);
		Bureaucrat operator=(const Bureaucrat& b);
		~Bureaucrat();

		void signForm(AForm& f);
		void executeForm(const AForm& f);
		int getGrade() const;
		const std::string& getName() const;
		void increaseGrade();
		void dereaseGrade();

		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};

	private:
		static const int highest_grade = 1;
		static const int lowest_grade = 150;
		const std::string m_name;
		int m_grade;
		static void check_grade(int grade);
};
std::ostream& operator<<(std::ostream &o, const Bureaucrat &b);
#endif
