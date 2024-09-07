#include "Data.hpp"
#include "Serializer.hpp"
#include <stdint.h>
#include <iostream>

int main(void) {
	Data d(1, 2);
	std::cout << d.m_field1 << " " << d.m_field2 << "\n";
	uintptr_t uintptr = Serializer::serialize(&d);
	Data* d_ptr = Serializer::deserialize(uintptr);
	std::cout << d_ptr->m_field1 << " " << d_ptr->m_field2 << "\n";
	if (&d == d_ptr)
		std::cout << "Serialization successeful!" << "\n";
	else
		std::cout << "We are doomed" << "\n";
	return 0;
}
