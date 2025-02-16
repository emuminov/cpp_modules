#include "ford_johnson.hpp"
#include <iostream>

// 11 2 17 0 16 8 6 15 10 3 8 1 18 9 14 19 12 5 4 20 13 7
// === 1 === swap pairs of numbers
// (11 2) (17 0) (16 8) (6 15) (10 3) (8  1) (18 9) (14 19) (12 5) (4   20) (13  7)
//  b1 a1  b2 a2  b3 a3  b4 a4  b5 a5  b6 a6  b7 a7  b8 a8   b9 a9  b10 a10  b11 a11
// (2 11) (0 17) (8 16) (6 15) (3 10) (1  8) (9 18) (14 19) (5 12) (4   20) (7  13)

// === 2 === swap pairs of pairs of numbers
// ((2 11) (0 17)) ((8 16) (6 15)) ((3 10) (1 8)) ((9 18) (14 19)) ((5 12) (4 20)) | (7 13)
//   b1     a1       b2     a2       b3     a3      b4     a4       b5      a5        b6
// ((2 11) (0 17)) ((6 15) (8 16)) ((1 8) (3 10)) ((9 18) (14 19)) ((5 12) (4 20)) | (7 13)

// === 3 === swap pairs of pairs of pairs of numbers
// (((2 11) (0 17)) ((6 15) (8 16))) (((1 8) (3 10)) ((9 18) (14 19))) | (((5 12) (4 20))) 7 13
//    b1              a1                b2             a2                   b3
// (((6 15) (8 16)) ((2 11) (0 17))) (((1 8) (3 10)) ((9 18) (14 19))) | (((5 12) (4 20))) 7 13

// === 4 === swap pairs of pairs of paris of pairs numbers
// ((((6 15) (8 16)) ((2 11) (0 17))) (((1 8) (3 10)) ((9 18) (14 19)))) | 5 12 4 20 7 13
//     b1                                a1
// ((((6 15) (8 16)) ((2 11) (0 17))) (((1 8) (3 10)) ((9 18) (14 19)))) | 5 12 4 20 7 13

// === 4 === swap pairs of pairs of paris of pairs numbers
// ((((6 15) (8 16)) ((2 11) (0 17))) (((1 8) (3 10)) ((9 18) (14 19)))) | 5 12 4 20 7 13
//     b1                                a1
// ((((6 15) (8 16)) ((2 11) (0 17))) (((1 8) (3 10)) ((9 18) (14 19)))) | 5 12 4 20 7 13

// === 4 === insert at the start of S the smallest number of the smallest pair (b1)
// 


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
	int arr[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 8, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	int len = sizeof(arr) / sizeof(int); 
	std::vector<int> vec;
	vec.insert(vec.begin(), arr, arr + len);

	sort(vec);

	for (int i = 0; i < len; i++) {
		std::cout << vec[i] << "\n";
	}
}
