#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>
#include <cerrno>
#include <iomanip>
#include <iostream>
#include <sstream>
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

// because there is only one pair, I'll do it in one step
// === 4 === insert at the start of S the smallest number of the smallest pair (b1)
// === 4 === insert the rest of a's into the S
// === 4 === insert b's into S using jacobsthal numbers and binary search
// 6 15 8 16 2 11 0 17 1 8 3 10 9 18 14 19 5 12 4 20 7 13

// 6 15 8 16 2 11 0 17 1 8 3 10 9 18 14 19 5 12 4 20 7 13
// === 3 === insert at the start of S the smallest number of the smallest pair (b1)
// === 3 === insert the rest of a's into the S
// (((6 15) (8 16)) ((2 11) (0 17))) (((1 8) (3 10)) ((9 18) (14 19))) | (((5 12) (4 20))) 7 13
//    b1              a1                b2             a2                   b3
// pend: [10]    [20]
//        b2      b3
//        b1  a1  a2
// main: [16, 17, 19]

// === 3 === insert b's into S using jacobsthal numbers and binary search
//        b2  b1  a1  a2  b3
// main: [10, 16, 17, 19, 20]
//    b2              b1                a1             a2                   b3
// (((1 8) (3 10)) ((6 15) (8 16))) (((2 11) (0 17)) ((9 18) (14 19))) (((5 12) (4 20))) 7 13

// 1 8 3 10 6 15 8 16 2 11 0 17 9 18 14 19 5 12 4 20 7 13
// === 2 === insert at the start of S the smallest number of the smallest pair (b1)
// === 2 === insert the rest of a's into the S
//   b1     a1       b2     a2       b3     a3      b4      a4        b5     a5        b6
// ((1 8)  (3 10)) ((6 15) (8 16)) ((2 11) (0 17)) ((9 18) (14 19)) ((5 12) (4 20)) | (7 13)
// pend: [15, 11, 18, 12]    [13]
//        b2  b3  b4  b5      b6
//        b1  a1  a2  a3  a4  a5
// main: [ 8, 10, 16, 17, 19, 20]

// === 2 === insert b's into S using jacobsthal numbers and binary search
//        b1  a1  b3  b5  b6  b2, a2  a3  b4  a4  a5
// main: [ 8, 10, 11, 12, 13, 15, 16, 17, 18, 19, 20]
// 1 8 3 10 2 11 5 12 7 13 6 15 8 16 0 17 9 18 14 19 4 20

// 1 8 3 10 2 11 5 12 7 13 6 15 8 16 0 17 9 18 14 19 4 20
// === 1 === insert at the start of S the smallest number of the smallest pair (b1)
// === 1 === insert the rest of a's into the S
// (1 8) (3 10) (2 11) (5 12) (7 13) (6 15) (8 16) (0 17) (9 18) (14 19) (4  20)
// b1 a1 b2 a2  b3 a3  b4 a4  b5 a5  b6 a6  b7 a7  b8 a8  b9 a9  b10 a10 b11 a11
// pend: [3  2  5  7  6  8  0  9  14  4]
//        b2 b3 b4 b5 b6 b7 b8 b9 b10 b11
//        b1 a1 a2 a3 a4 a5 a6 a7 a8 a9 a10 a11
// main: [1  8  10 11 12 13 15 16 17 18 19  20]





// 35 36 34 37 39 41 43 44 45 48
// === 1 === sort pairs of numbers
// (35 36) (34 37) (39 41) (43 44) (45 48)
//
// (35 36) (34 37) (39 41) (43 44) (45 48)












static std::string validate_arg(std::string arg)
{
	if (arg[0] == '-')
		return "Negative numbers are not allowed";
	long nbr = strtol(arg.c_str(), NULL, 10);
	if (nbr == 0 && arg != "0")
		return "Non-number arguments not allowed";
	if (nbr > INT_MAX || errno == ERANGE)
		return "Too big arguments are not allowed";
	return "";
}

static std::string validate(int argc, char** argv)
{
	if (argc == 1)
		return "No arguments were provided";
	for (int i = 1; i < argc; i++)
	{
		std::string status = validate_arg(argv[i]);
		if (status != "")
			return status;
	}
	return "";
}

static std::vector<int> argv_to_vector(int argc, char** argv)
{
	std::vector<int> res;
	res.reserve(argc - 1);
	for (int i = 1; i < argc; i++)
	{
		res.push_back(atoi(argv[i]));
	}
	return res;
}

static std::deque<int> argv_to_deque(int argc, char** argv)
{
	std::deque<int> res;
	for (int i = 1; i < argc; i++)
	{
		res.push_back(atoi(argv[i]));
	}
	return res;
}

template <typename T>
static bool is_sorted(const T& container)
{
	if (container.size() == 0 || container.size() == 1)
		return true;
	typename T::const_iterator end = container.end();
	std::advance(end, -1);
	for (typename T::const_iterator it = container.begin(); it != end; it++)
	{
		typename T::const_iterator next = it;
		std::advance(next, 1);
		if (*it > *next)
			return false;
	}
	return true;
}

static std::string argv_to_str(int argc, char** argv)
{
	std::string res;
	res.reserve(argc + 1);
	res += "[";
	res += argv[1];
	for (int i = 2; i < argc; i++)
	{
		res += " ";
		res += argv[i];
	}
	res += "]";
	return res;
}

static std::string vec_to_str(std::vector<int>& vec)
{
	std::stringstream ss;
	ss << "[" << vec[0];
	for (size_t i = 1; i < vec.size(); i++)
	{
		ss << " " << vec[i];
	}
	ss << "]";
	return ss.str();
}

int main(int argc, char** argv) {
	PmergeMe pm;
	std::string status = validate(argc, argv);
	if (status != "")
	{
		std::cerr << "Error: " << status << "\n";
		return EXIT_FAILURE;
	}

	clock_t start_vec = clock();
	std::vector<int> vec = argv_to_vector(argc, argv);
	pm.sort_vec(vec);
	clock_t end_vec = clock();
	double time_elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

	clock_t start_deque = clock();
	std::deque<int> deque = argv_to_deque(argc, argv);
	pm.sort_deque(deque);
	clock_t end_deque = clock();
	double time_elapsed_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC;

	if (!is_sorted(vec))
		std::cout << "Vector was not sorted properly.\n";
	if (!is_sorted(deque))
		std::cout << "Deque was not sorted properly.\n";
	std::cout << "\033[31mBefore\033[00m: " << argv_to_str(argc, argv) << "\n";
	std::cout << "\033[32mAfter\033[00m:  " << vec_to_str(vec) << "\n";
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << std::fixed << std::setprecision(6) << time_elapsed_vec << "s\n";
	std::cout << "Time to process a range of " << vec.size() << " elements with std::deque:  " << std::fixed << std::setprecision(6) << time_elapsed_deque << "s\n";
}
