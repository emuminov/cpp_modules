#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>
#include <cstdlib>
template <typename T>
class Array {
	public:
		Array() : m_data(NULL), m_size(0) { return; }

		Array(unsigned int n) : m_data(new T[n]()), m_size(n) { return; }

		Array(const Array& arr) : m_data(new T[arr.m_size]()), m_size(arr.m_size) {
			for (int i = 0; i < m_size; i++) {
				m_data[i] = arr.m_data[i];
			}
		}

		Array& operator=(const Array& arr) {
			if (&arr == this)
				return *this;
			m_size = arr.m_size;
			delete[] m_data;
			m_data = new T[m_size]();
			for (int i = 0; i < m_size; i++) {
				m_data[i] = arr.m_data[i];
			}
			return *this;
		}

		~Array() {
			delete[] m_data;
		}

		class OutOfBoundsException : public std::exception {
			virtual const char* what() const throw() {
				return "Index is out of bounds";
			}
		};

		class EmptyArrayException : public std::exception {
			virtual const char* what() const throw() {
				return "Array is empty";
			}
		};

		T& operator[](const int index) {
			if (m_size == 0)
				throw EmptyArrayException();
			else if (index < 0 || index >= m_size)
				throw OutOfBoundsException();
			return m_data[index];
		}

		int size() {
			return m_size;
		}

	private:
		T* m_data;
		int m_size;
};
#endif
