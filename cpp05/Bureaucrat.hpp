#ifndef BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <exception>
class Bureaucrat {
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat operator=(const Bureaucrat &b);
		~Bureaucrat();

		int getGrade() const;
		const std::string& getName() const;
		void increaseGrade();
		void dereaseGrade();

		class GradeTooHighException : public std::exception {
			
		};

		class GradeTooLowException : public std::exception{
			
		};

	private:
		static const int highest_grade = 1;
		static const int lowest_grade = 150;
		const std::string m_name;
		int m_grade;
};
std::ostream operator<<(std::ostream &o, const Bureaucrat &b);
#endif
