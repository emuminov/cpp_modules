#ifndef SPAN_HPP
#define SPAN_HPP
#include <list>
#include <exception>
#include <ostream>
class Span {
	public:
          Span(unsigned int n);
          Span(const Span &s);
          Span &operator=(const Span &s);
          ~Span();

          void addNumber(int nbr);
          int shortestSpan() const;
          int longestSpan() const;
		  std::list<int>::const_iterator begin() const;
		  std::list<int>::const_iterator end() const;

		  class OverCapacityException : public std::exception {
			  virtual const char* what() const throw();
		  };
	private:
		unsigned int m_capacity;
		unsigned int m_length;
		std::list<int> m_numbers;
};
std::ostream& operator<<(std::ostream& o, const Span& s);
#endif
