#include "Data.hpp"

Data::Data(int f1, int f2) : m_field1(f1), m_field2(f2) { return; }

Data::Data(const Data& sc) : m_field1(sc.m_field1), m_field2(sc.m_field2) { return; }

Data& Data::operator=(const Data& sc)
{
    if (&sc == this)
        return *this;
    m_field1 = sc.m_field1;
    m_field2 = sc.m_field2;
    return *this;
}

Data::~Data() { return; }
