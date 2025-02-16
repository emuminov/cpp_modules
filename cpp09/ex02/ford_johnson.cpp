#include "ford_johnson.hpp"
#include <cmath>
#include <list>
#include <algorithm>

// 2 0 3 8 1 9 5 4 7
// === 1 === swap pairs of numbers
// (2 0) (3 8) (1 9) (5 4) 7
// b1 a1 b2 a2 b3 a3 b4 a4
// (0 2) (3 8) (1 9) (4 5) 7

// === 2 === swap pairs of pairs of numbers
// ((0 2) (3 8)) ((1 9) (4 5)) 7
//   b1    a1      b2    a2
// ((0 2) (3 8)) ((4 5) (1 9)) 7

// === 3 === swap pairs of pairs of pairs of numbers
// (((0 2) (3 8)) ((4 5) (1 9))) 7
//       b1            a1
// (((0 2) (3 8)) ((4 5) (1 9))) 7
// pair_level = 4
// size = 8 / 4
// we want to compare 3 and 7
// 8 9

// === 4 === swap pairs of pairs of pairs of pairs of numbers
// ((((0 2) (3 8) (4 5) (1 9)))) 7
//              a1
// pair_level = 8
// size = 8 / 8
// we want to compare 7
// 9
// RETURN

// === 3 === insert at the start of S the smallest number of the smallest pair (b1)
// (((0 2) (3 8)) ((4 5) (1 9))) 7
//       b1            a1
// (((0 2) (3 8)) ((4 5) (1 9))) 7
// we want to insert 4 elements starting from 0
// we want to insert 4 elements starting from 4
// main.insert(b1, a1);
// main: [0 2 3 8 4 5 1 9]

// === 3 === insert the remaing pend numbers to S
// (((0 2) (3 8)) ((4 5) (1 9))) 7
//       b1            a1
// (((0 2) (3 8)) ((4 5) (1 9))) 7
// main: [0 2 3 8 4 5 1 9]

// === 2 === insert at the start of S the smallest number of the smallest pair (b1)
// ((0 2) (3 8)) ((4 5) (1 9)) 7
//   b1    a1      b2    a2
// ((0 2) (3 8)) ((4 5) (1 9)) 7
// main.insert(b1, a1, a2);
// main: [0 2 3 8 1 9]

// === 2 === insert the remaing pend numbers to S
// ((0 2) (3 8)) ((4 5) (1 9)) 7
//   b1    a1      b2    a2
// ((0 2) (4 5)) ((3 8) (1 9)) 7
// main.insert(b2);
// main: [0 2 4 5 3 8 1 9]

// === 1 === insert at the start of S the smallest number of the smallest pair (b1)
// (0 2) (4 5) (3 8) (1 9) 7
// b1 a1 b2 a2 b3 a3 b4 a4
// main: [0 2 5 8 9]

// === 1 === insert the remaing pend numbers to S
// (0 2) (4 5) (3 8) (1 9) 7
// b1 a1 b2 a2 b3 a3 b4 a4
// main: [0 1 2 3 4 5 7 8 9]

typedef std::vector<int>::iterator Iterator;

// === 1 === insert the remaing pend numbers to S
// (0 2) (4 5) (3 8) (1 9) 7
// b1 a1 b2 a2 b3 a3 b4 a4
// [0 2 5 8 9]
// [0 2 5 8 9] insert b3 (3), area of search: 0..2
// we need to insert idx 4
// [0 2 3 5 8 9] insert b2 (4), area of search: 0..3
// we need to insert idx 2
// void insert_smallest_from_pair(const std::vector<int>& pend, std::vector<int>& main, Iterator pair_to_insert, int pair_level) {
// 	
// 	
// }

void swap_pair(Iterator it, int pair_level) {
	Iterator start = it - pair_level + 1;
	Iterator end = start + pair_level;
	while (start < end) {
		std::iter_swap(start, (start + pair_level));
		start++;
	}
}

bool comp(Iterator lv, Iterator rv) {
	return *lv < *rv;
}

/* Gives an index of the nth Jacobsthal number, starting from 1.
 * round((pow(2, n) + pow(-1, n - 1)) / 3) means that it starts from 0.*/
long jacobsthal_number(long n) {
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

void _merge_insertion_sort(std::vector<int>& vec, int pair_level) {
	int pair_units_nbr = vec.size() / pair_level;
	if (pair_units_nbr < 2)
		return;

	bool is_odd = pair_units_nbr % 2 == 1;
	(void)is_odd;

	Iterator start = vec.begin() + (pair_level - 1);
	Iterator end = vec.end() - is_odd;
	int jump = 2 * pair_level;
	for (Iterator it = start; it < end; it += jump) {
		Iterator next_pair = it + pair_level;
		if (*it > *next_pair) {
			swap_pair(it, pair_level);
		}
	}

	_merge_insertion_sort(vec, pair_level * 2);

	// 1 insert iterators of vec into the main
	// 2 insert iterators of vec into the pend
	// 3 perform binary search of pend elements on main
	// 4 insert pend elements into the main
	// 5 copy main elemnents into a vector of ints
	// 6 rewrite an original vector with the new vector
	std::list<Iterator> main;
	std::list<Iterator> pend;
	
	main.insert(main.end(), vec.begin() + pair_level - 1);
	main.insert(main.end(), vec.begin() + pair_level * 2 - 1);
	
	for (int i = 4; i <= pair_units_nbr; i += 2) {
		//     1     3             7            11
		// ((0 2) (3 8)) ((4 5) (1 9)) ((2 3) (8 3)) 7
		//   b1    a1      b2    a2      b3    a3
		// pair_level = 2
		// insert 1
		// insert 3

		// insert 7
		// insert 11
		// insert 15

		//            3             7                            15                            23
		// (((0 2) (3 8)) ((4 5) (1 9))) (((0 2) (3 8)) ((4 5) (1 9))) (((0 2) (3 8)) ((4 5) (1 9))) 7
		//       b1            a1              b2            a2              b3            a3
		// pair_level = 4
		// insert 3
		// insert 7

		// insert 15
		// insert 23
		// insert 31
		pend.insert(pend.end(), vec.begin() + pair_level * (i - 1) - 1);
		main.insert(main.end(), vec.begin() + pair_level * i - 1);
	}

	if (is_odd) {
		pend.insert(pend.end(), --vec.end());
	}

	std::list<Iterator>::iterator curr_pend = pend.begin();
	std::list<Iterator>::iterator curr_bound = main.begin();
	std::advance(curr_bound, 2);
	int prev_jacobsthal = jacobsthal_number(1);
	for (int k = 2; ; k++) {
		int curr_jacobsthal = jacobsthal_number(k);
		int nbr_of_times = curr_jacobsthal - prev_jacobsthal;
		(void)nbr_of_times;
		if (curr_jacobsthal > pair_units_nbr)
			break;
		// insert b3 b2
		// while (nbr_of_times) {
		// 	std::advance(curr_bound, 1);
		// 	std::list<Iterator>::iterator idx = std::upper_bound(main.begin(), curr_bound, curr_pend);
		// 	main.insert(idx, curr_pend);
		// 	(void)idx;
		// 	nbr_of_times--;
		//    // insert_smallest_from_pair(pend, main, curr_jacobsthal, pair_level);
		// }
		prev_jacobsthal = curr_jacobsthal;
	}

	while (!pend.empty()) {
		std::list<Iterator>::iterator idx = std::upper_bound(main.begin(), curr_bound, *curr_pend, comp);
		main.insert(idx, *curr_pend);
		pend.erase(curr_pend);
		curr_pend = pend.begin();
		std::advance(curr_bound, 1);
	}

	std::vector<int> copy;
	copy.reserve(vec.size());
	for (std::list<Iterator>::iterator it = main.begin(); it != main.end(); it++) {
		int* end = it->base();
		int* begin = (end - pair_level + 1);
		copy.insert(copy.end(), begin, ++end);
	}

	Iterator vec_it = vec.begin();
	Iterator copy_it = copy.begin();
	while (copy_it != copy.end()) {
		*vec_it = *copy_it;
		vec_it++;
		copy_it++;
	}
}

void sort(std::vector<int>& vec) {
	_merge_insertion_sort(vec, 1);
}
