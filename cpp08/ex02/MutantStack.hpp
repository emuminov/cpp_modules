#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP
#include <stack>
#include <deque>
template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
	public:
		typedef typename std::deque<T>::iterator iterator;

		MutantStack() : std::stack<T>() { return; }
		MutantStack(const MutantStack& ms) : std::stack<T>(ms.c) { return; }
		MutantStack& operator=(const MutantStack& ms) {
			if (this == &ms)
				return *this;
			this->c = ms.c;
			return *this;
		}
		~MutantStack() { return; }

		MutantStack<T>::iterator begin() {
			return this->c.begin();
		};

		MutantStack<T>::iterator end() {
			return this->c.end();
		};
};
#endif
