#include "MutantStack.hpp"
#include <iostream>
#include <list>

void tests() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
	std::cout << "===\n";
    std::stack<int> s(mstack);
    MutantStack<int>::iterator sit = mstack.begin();
    MutantStack<int>::iterator site = mstack.end();
    while (sit != site) {
        std::cout << *sit << std::endl;
        ++sit;
    }
	std::cout << "===\n";
    std::stack<int> s2 = std::stack<int>();
	s2 = s;
    MutantStack<int>::iterator s2it = mstack.begin();
    MutantStack<int>::iterator s2ite = mstack.end();
    while (s2it != s2ite) {
        std::cout << *s2it << std::endl;
        ++s2it;
    }
	std::cout << "===\n";
	std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
	std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    ++lit;
    --lit;
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }
}

int main(void) {
	tests();
    return 0;
}
