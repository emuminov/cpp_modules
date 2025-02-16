#include "ford_johnson.hpp"
#include <cmath>
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

	std::list<int> main;
	std::list<int> pend;
	
	// insert b1, a1, a2...aN
	// if pair_level = 1, insert 0
	// insert b1
	main.insert(main.end(), vec.begin(), vec.begin() + pair_level);
	// if pair_level = 1, insert 1
	// insert a1
	main.insert(main.end(), vec.begin() + pair_level, vec.begin() + pair_level * 2);
	// if pair_level = 1, insert 3
	// if pair_level = 1, insert 5
	// insert the rest of a's, starting from the a2
	// === 2 === insert at the start of S the smallest number of the smallest pair (b1)
	// ((0 2) (3 8)) ((4 5) (1 9)) 7
	//   b1    a1      b2    a2
	// ((0 2) (3 8)) ((4 5) (1 9)) 7
	// [0 2 3 8 1 9]
	for (int i = 3; i < pair_units_nbr; i += 2) {
		// (0 2) (4 5) (3 8) (1 9) 7
		// b1 a1 b2 a2 b3 a3 b4 a4
		// insert a2, a3, a4 ... a(n/2)
		main.insert(main.end(), vec.begin() + pair_level * 3,  vec.begin() + pair_level * 3 + pair_level);
		// [0 2 5 8 9]
		// insert b2, b3, b4 ... b(n/2)
		// [4 3 1]
	}

	// insert the rest of b's into the pend
	// b2, b3, ... bn
	// if pair_level = 1, insert 2
	// if pair_level = 1, insert 4
	// for (int pair_idx = 2; pair_idx < pair_units_nbr; pair_idx += 2) {
	// 	insert_pair_to_vec(vec, pend, pair_level, pair_idx);
	// }
	// if (is_odd) {
	// 	pend.insert(pend.end(), vec.back());
	// }

	
	// === 3 === insert the remaing pend numbers to S
	// (((0 2) (3 8)) ((4 5) (1 9))) 7
	//       b1            a1
	// (((0 2) (3 8)) ((4 5) (1 9))) 7
	// main: [0 2 3 8 4 5 1 9]

	// === 2 === insert the remaing pend numbers to S
	// ((0 2) (3 8)) ((4 5) (1 9)) 7
	//   b1    a1      b2    a2
	// ((0 2) (4 5)) ((3 8) (1 9)) 7
	// [0 2 4 5 3 8 1 9]

	// === 1 === insert at the start of S the smallest number of the smallest pair (b1)
	// (0 2) (4 5) (3 8) (1 9) 7
	// b1 a1 b2 a2 b3 a3 b4 a4
	// [0 2 5 8 9]

	// === 1 === insert the remaing pend numbers to S
	// (0 2) (4 5) (3 8) (1 9) 7
	// b1 a1 b2 a2 b3 a3 b4 a4
	// [0 2 5 8 9]
	// [0 2 5 8 9] insert b3 (3), area of search: 0..2
	// [0 2 3 5 8 9] insert b2 (4), area of search: 0..3
	// [0 2 3 5 8 9] insert b5, no b5: insert in order
	// [0 2 3 4 5 8 9] insert b4 (1), area of search: 0..6
	// [0 1 2 3 4 5 8 9] insert odd element (7), area of search: [entire main]
	// [0 1 2 3 4 5 7 8 9]
	// for (int k = 2; ; k++) {
	// 	int idx_to_insert = jacobsthal_number(k);
	// 	int nbr_of_times = idx_to_insert - jacobsthal_number(k - 1);
	// 	if (idx_to_insert > pair_units_nbr)
	// 		break;
	// 	// insert b3 b2
	// 	while (nbr_of_times--) {
	// 	   insert_smallest_from_pair(pend, main, idx_to_insert, pair_level);
	// 	   idx_to_insert--;
	// 	}
	// }
	//
	// while (!pend.empty()) {
	//
	// }
}

void sort(std::vector<int>& vec) {
	_merge_insertion_sort(vec, 1);
}
