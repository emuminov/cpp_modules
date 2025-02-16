#include "ford_johnson.hpp"
#include <list>

class Range {
	public:
	Range(int start, int end) : m_start(start), m_end(end), m_length(end - start) {
		return;
	}

	const int& start() const { return m_start; }
	const int& end() const { return m_end; }
	const int& length() const { return m_length; }

	private:
	int m_start;
	int m_end;
	int m_length;
};

void swap_pair(std::vector<int>& vec, int i, int j, int pair_level) {
	int half = vec.size() / 2;
	int k = 0;
	std::swap(vec[i + k], vec[j + k]);
	while (--pair_level) {
		std::swap(vec[i + k - half], vec[j + k - half]);
	}
}

// 2 0 3 8 1 9 5 4 7
// === 1 === swap pairs of numbers
// (2 0) (3 8) (1 9) (5 4) 7
// (0 2) (3 8) (1 9) (4 5) 7
// pair_level = 1
// size = 8 / 1
// we want to compare 0 and 1, 2 and 3, 4 and 5, 6 and 7
// for (int i = pair_level - 1; i < vec.size(); i += 2 * pair_level) {
//   if (vec[i] < vec[i + pair_level]) {
//     swap(vec, i, pair_level);
//   }
// }
// we want to swap (0) and (1)
// we want to swap (0, 1) and (2, 3)
// we want to swap (0, 1, 2, 3) and (4, 5, 6, 7)
// void swap(vec, i, pair_level) {
//   int start = i - pair_level + 1;
//   while (start < pair_level) {
//     swap(vec[start], vec[start + pair_level];
//     start++;
//   }
// }


// === 2 === swap pairs of pairs of numbers
// ((0 2) (3 8)) ((1 9) (4 5)) 7
// ((0 2) (3 8)) ((4 5) (1 9)) 7
// pair_level = 2
// size = 8 / 2
// we want to compare 1 and 3, 5 and 7
// 2 8 9 5

// === 3 === swap pairs of pairs of pairs of numbers
// (((0 2) (3 8)) ((4 5) (1 9))) 7
// (((0 2) (3 8)) ((4 5) (1 9))) 7
// pair_level = 4
// size = 8 / 4
// we want to compare 3 and 7
// 8 9

// === 4 === swap pairs of pairs of pairs of pairs of numbers
// ((((0 2) (3 8) (4 5) (1 9)))) 7
// pair_level = 8
// size = 8 / 8
// we want to compare 7
// 9
// RETURN

// === 3 === insert at the start of S the smallest number of the smallest pair
// (((0 2) (3 8)) ((4 5) (1 9))) 7
// (((0 2) (3 8)) ((4 5) (1 9))) 7
// main: [8 9]
// main: [0 8 9]     <- insert smallest element into the main

// === 3 === insert the remaing pend numbers to S
// (((0 2) (3 8)) ((4 5) (1 9))) 7
// (((0 2) (3 8)) ((4 5) (1 9))) 7
// main: [0 8 9]     <- insert 0
// main: [0 2 8 9]   <- insert 2

void swap_pair(std::vector<int>& vec, int i, int pair_level) {
	int start = i - pair_level + 1;
	int end = start + pair_level;
	while (start < end) {
		std::swap(vec[start], vec[start + pair_level]);
		start++;
	}
}

void _merge_insertion_sort(std::vector<int>& vec, int pair_level) {
	int pairs_nbr = vec.size() / pair_level;
	if (pairs_nbr < 2)
		return;

	bool has_stagger = pairs_nbr % 2 == 1;

	int start = pair_level - 1;
	int jump = 2 * pair_level;
	int end = vec.size() - has_stagger;
	for (int i = start; i < end; i += jump) {
		if (vec[i] > vec[i + pair_level]) {
			swap_pair(vec, i, pair_level);
		}
	}

	_merge_insertion_sort(vec, pair_level * 2);

	// === 2 === insert at the start of S the smallest number of the smallest pair
	// ((0 2) (3 8)) ((4 5) (1 9)) 7
	// ((0 2) (3 8)) ((4 5) (1 9)) 7
	// main: [8 9]
	// main: [2 8 9]     <- insert smallest element into the main
	
	std::vector<int> pend;
	std::vector<int> main;

	
}

void sort(std::vector<int>& vec) {
	_merge_insertion_sort(vec, 1);
}
