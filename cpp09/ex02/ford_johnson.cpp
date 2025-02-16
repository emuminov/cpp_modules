#include "ford_johnson.hpp"
#include <cmath>

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

void insert_pair_to_vec(const std::vector<int>& vec, std::vector<int>& main, int pair_level, int pair_idx) {
	main.insert(main.end(), &vec[pair_idx * pair_level], &vec[pair_idx * pair_level + pair_level]);
}

void swap_pair(std::vector<int>& vec, int i, int pair_level) {
	int start = i - pair_level + 1;
	int end = start + pair_level;
	while (start < end) {
		std::swap(vec[start], vec[start + pair_level]);
		start++;
	}
}

/* Gives an index of the nth Jacobsthal number, starting from 1.
 * round((pow(2, n) + pow(-1, n - 1)) / 3) means that it starts from 0.*/
long jacobsthal_number(long n) {
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

void _merge_insertion_sort(std::vector<int>& vec, int pair_level) {
	int pairs_nbr = vec.size() / pair_level;
	if (pairs_nbr < 2)
		return;

	bool is_odd = pairs_nbr % 2 == 1;

	int start = pair_level - 1;
	int jump = 2 * pair_level;
	int end = vec.size() - is_odd;
	for (int i = start; i < end; i += jump) {
		if (vec[i] > vec[i + pair_level]) {
			swap_pair(vec, i, pair_level);
		}
	}

	_merge_insertion_sort(vec, pair_level * 2);
	
	std::vector<int> main;
	std::vector<int> pend;

	main.reserve(vec.size());
	pend.reserve(vec.size());
	
	// insert b1, a1, a2...aN
	// if pair_level = 1, insert 0
	// insert b1
	insert_pair_to_vec(vec, main, pair_level, 0);
	// if pair_level = 1, insert 1
	// insert a1
	insert_pair_to_vec(vec, main, pair_level, 1);
	// if pair_level = 1, insert 3
	// if pair_level = 1, insert 5
	// insert the rest of a's, starting from the a2
	// (2 0) (3 8) (1 9) (5 4) 7
	// b1 a1 b2 a2 b3 a3 b4 a4
	// (0 2) (3 8) (1 9) (4 5) 7
	for (int pair_idx = 3; pair_idx < pairs_nbr; pair_idx += 2) {
		insert_pair_to_vec(vec, main, pair_level, pair_idx);
	}

	// insert the rest of b's into the pend
	// b2, b3, ... bn
	// if pair_level = 1, insert 2
	// if pair_level = 1, insert 4
	for (int pair_idx = 2; pair_idx < pairs_nbr; pair_idx += 2) {
		insert_pair_to_vec(vec, pend, pair_level, pair_idx);
	}
	if (is_odd) {
		pend.insert(pend.end(), vec.back());
	}

	
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
	for (int pair_idx = 0; pair_idx < pairs_nbr; pair_idx += 2) {
		
	}
}

void sort(std::vector<int>& vec) {
	_merge_insertion_sort(vec, 1);
}
