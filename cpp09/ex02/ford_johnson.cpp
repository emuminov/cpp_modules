#include "ford_johnson.hpp"
#include <cmath>
#include <algorithm>
#include <list>

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


	/* Swap pairs of numbers, pairs, pairs of pairs etc by the biggest pair
	number. After each swap we recurse. */
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

	/* Main contains an already sorted sequence.
	Pend stores a yet to be sorted numbers.
	List data structure for quick random insertion and deletion.
	They contain iterators instead of the numbers themselves because
	iterators + pair_level contain all the information about the stored
	ranges of numbers. */
	std::list<Iterator> main;
	std::vector<Iterator> pend;
	
	/* Initialize the main chain with the {b1, a1}. */
	main.insert(main.end(), vec.begin() + pair_level - 1);
	main.insert(main.end(), vec.begin() + pair_level * 2 - 1);
	
	/* Insert the rest of a's into the main chain. */
	for (int i = 4; i <= pair_units_nbr; i += 2) {
		pend.insert(pend.end(), vec.begin() + pair_level * (i - 1) - 1);
		main.insert(main.end(), vec.begin() + pair_level * i - 1);
	}

	/* Insert an odd number to the pend */
	if (is_odd) {
		pend.insert(pend.end(), --vec.end());
	}

	/* Insert the pend into the main in the order determined by the
	Jacobsthal numbers. For example: 3 2 -> 5 4 -> 11 10 9 8 7 6 -> etc */
	std::list<Iterator>::iterator curr_bound = main.begin();
	std::vector<Iterator>::iterator curr_pend = pend.begin();
	int prev_jacobsthal = jacobsthal_number(1);
	for (int k = 2; ; k++) {
		int curr_jacobsthal = jacobsthal_number(k);
		int jacobstal_diff = curr_jacobsthal - prev_jacobsthal;
		if (curr_jacobsthal > static_cast<int>(pend.size()))
			break;
		std::list<Iterator>::iterator bound_it = curr_bound;
		std::vector<Iterator>::iterator pend_it = curr_pend;
		std::advance(bound_it, jacobstal_diff);
		std::advance(pend_it, jacobstal_diff - 1);
		while (jacobstal_diff)
		{
			// insert b3 b2; b5 b4; b11 b10 b9 b8 b7 b6;
			// until  a3 a2; a5 a4; a11 a10 a9 a8 a7 a6;
			// === 1 === insert the remaing pend numbers to S
			// (0 2) (4 5) (3 8) (1 9) 7
			// b1 a1 b2 a2 b3 a3 b4 a4
			// main: [b1 a1 a2 a3 a4 a5 a6 a7]
			// pend: [      b2 b3 b4 b5 b6 b7]
			// 1. we try to insert b3 to {b1, a1, a2}
			// 2. we try to insert b2 to {b1, a1, b3}
			// 3. we try to insert b5 to {b1, a1, b2, a2, b3, a3, a4}
			// 4. we try to insert b4 to {b1, a1, b2, a2, b3, a3, b5}
			jacobstal_diff--;
			std::advance(bound_it, -1);
			std::advance(pend_it, -1);
		}
		prev_jacobsthal = curr_jacobsthal;
	}

	// Insert the remaining elements in the sequential order.
	while (!pend.empty()) {
		std::list<Iterator>::iterator idx = std::upper_bound(main.begin(), curr_bound, *curr_pend, comp);
		main.insert(idx, *curr_pend);
		pend.erase(curr_pend);
		curr_pend = pend.begin();
		std::advance(curr_bound, 1);
	}

	/* Use copy vector to store all the numbers, in order not to overwrite the
	original iterators. */
	std::vector<int> copy;
	copy.reserve(vec.size());
	for (std::list<Iterator>::iterator it = main.begin(); it != main.end(); it++) {
		for (int i = 0; i < pair_level; i++) {
			Iterator pair_start = *it;
			std::advance(pair_start, -pair_level + i + 1);
			copy.insert(copy.end(), *pair_start);
		}
	}

	// Replace values in the original container
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
