#include "ford_johnson.hpp"
#include <iostream>

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
// pair_level = 8
// size = 8 / 8
// we want to compare 7
// 9
// RETURN

// === 3 === insert at the start of S the smallest number of the smallest pair (b1)
// (((0 2) (3 8)) ((4 5) (1 9))) 7
//       b1            a1
// (((0 2) (3 8)) ((4 5) (1 9))) 7
// main: [0, 2, 3, 8 4 5 1 9]

// === 3 === insert the remaing pend numbers to S
// (((0 2) (3 8)) ((4 5) (1 9))) 7
//       b1            a1
// (((0 2) (3 8)) ((4 5) (1 9))) 7
// main: [0 2 3 8 4 5 1 9]

// === 2 === insert at the start of S the smallest number of the smallest pair (b1)
// ((0 2) (3 8)) ((4 5) (1 9)) 7
//   b1    a1      b2    a2
// ((0 2) (3 8)) ((4 5) (1 9)) 7
// [0 2 3 8 1 9]

// === 2 === insert the remaing pend numbers to S
// ((0 2) (3 8)) ((4 5) (1 9)) 7
//   b1    a1      b2    a2
// ((0 2) (4 5)) ((3 8) (1 9)) 7
// [0 2 4 5 3 8 1 9]

// === 1 === insert at the start of S the smallest number of the smallest pair (b1)
// (0 2) (4 5) (3 8) (1 9) 7
// b1 a1 b2 a2 b3 a3 b4 a4
//
// [0 2 5 8 9]

// === 1 === insert the remaing pend numbers to S
// (0 2) (4 5) (3 8) (1 9) 7
// b1 a1 b2 a2 b3 a3 b4 a4
// [0 1 2 3 4 5 7 8 9]

int main(void) {
	int arr[] = {2, 0, 3, 8, 1, 9, 5, 4, 7};
	int len = sizeof(arr) / sizeof(int); 
	std::vector<int> vec;
	vec.insert(vec.begin(), arr, arr + len);

	sort(vec);

	for (int i = 0; i < len; i++) {
		std::cout << vec[i] << "\n";
	}
}
