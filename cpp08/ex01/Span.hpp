#ifndef SPAN_HPP
#define SPAN_HPP
#include <exception>
#include <list>
#include <ostream>
class Span {
  public:
    Span(unsigned int n);
    Span(const Span& s);
    Span& operator=(const Span& s);
    ~Span();

    void addNumber(int nbr);

    template <typename Iterator> void insert(Iterator begin, Iterator end) {
        for (Iterator it = begin; it != end; it++)
            addNumber(*it);
    }

    int shortestSpan() const;
    int longestSpan() const;
    std::list<int>::const_iterator begin() const;
    std::list<int>::const_iterator end() const;

    class CapacityExceededException : public std::exception {
        virtual const char* what() const throw();
    };

  private:
    unsigned int m_capacity;
    unsigned int m_length;
    std::list<int> m_numbers;
};
std::ostream& operator<<(std::ostream& o, const Span& s);
#endif
