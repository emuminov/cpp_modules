#include "PmergeMe.hpp"
#include <cmath>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& pm) { (void)pm; }
PmergeMe& PmergeMe::operator=(const PmergeMe& pm) { 
	(void)pm;
	return *this;
}
PmergeMe::~PmergeMe() {}

/* Gives an index of the nth Jacobsthal number, starting from 1.
 * round((pow(2, n) + pow(-1, n - 1)) / 3) means that it starts from 0.*/
long _jacobsthal_number(long n) {
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

void PmergeMe::sort_vec(std::vector<int>& vec) {
	_merge_insertion_sort<std::vector<int> >(vec, 1);
}

void PmergeMe::sort_list(std::list<int>& lst) {
	_merge_insertion_sort<std::list<int> >(lst, 1);
}
