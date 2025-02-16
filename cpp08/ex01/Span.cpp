#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ostream>

Span::Span(unsigned int n)
    : m_capacity(n), m_length(0), m_numbers(std::list<int>()) {
    return;
}

Span::Span(const Span& s)
    : m_capacity(s.m_capacity), m_length(0), m_numbers(s.m_numbers) {
    return;
}

Span& Span::operator=(const Span& s) {
    if (this == &s)
        return *this;
    m_capacity = s.m_capacity;
    m_length = s.m_length;
    m_numbers = s.m_numbers;
    return *this;
}

Span::~Span() { return; }

const char* Span::CapacityExceededException::what() const throw() {
    return "The capacity of the Span instance was exceeded";
}

void Span::addNumber(int nbr) {
    if ((m_length + 1) > m_capacity)
        throw CapacityExceededException();
    m_length++;
    std::list<int>::iterator target =
        std::lower_bound(m_numbers.begin(), m_numbers.end(), nbr);
    m_numbers.insert(target, nbr);
}

int Span::shortestSpan() const {
    std::list<int> diffs_list(m_numbers);
    std::adjacent_difference(m_numbers.begin(), m_numbers.end(),
                             diffs_list.begin());
    std::list<int>::iterator shortest =
        std::min_element(++diffs_list.begin(), diffs_list.end());
    return *shortest;
}

int Span::longestSpan() const {
    int smallest = m_numbers.front();
    int biggest = m_numbers.back();
    return biggest - smallest;
}

std::list<int>::const_iterator Span::begin() const { return m_numbers.begin(); }

std::list<int>::const_iterator Span::end() const { return m_numbers.end(); }

std::ostream& operator<<(std::ostream& o, const Span& s) {
    o << "[ ";
    for (std::list<int>::const_iterator it = s.begin(); it != s.end(); it++) {
        o << *it << " ";
    }
    o << "]";
    return o;
};
