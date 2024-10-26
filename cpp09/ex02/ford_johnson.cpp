#include "ford_johnson.hpp"
#include <cmath>
#include <algorithm>
#include <list>

typedef std::vector<int>::iterator Iterator;

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

	/* If there is an odd pair, we ignore it during swapping.
	It will go to the pend as the last pair. */
	bool is_odd = pair_units_nbr % 2 == 1;

	/* It's important to caluclate the end position until we iterate.
	We can have a set of values like:
	((1 2) (3 4)) ((3 8) (2 6)) | 0
	where the are numbers (0 in this case) which can't even form a pair.
	Those values should be ignored. */
	Iterator start = vec.begin();
	Iterator last = vec.begin() + pair_level * (pair_units_nbr);
	Iterator end = last - (is_odd * pair_level);

	/* Swap pairs of numbers, pairs, pairs of pairs etc by the biggest pair
	number. After each swap we recurse. */
	int jump = 2 * pair_level;
	for (Iterator it = start; it != end; it += jump) {
		Iterator this_pair = it + pair_level - 1;
		Iterator next_pair = it + pair_level * 2 - 1;
		if (*this_pair > *next_pair) {
			swap_pair(this_pair, pair_level);
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

	/* Insert the pend into the main in the order determined by the
	Jacobsthal numbers. For example: 3 2 -> 5 4 -> 11 10 9 8 7 6 -> etc.
	During insertion, main numbers serve as an upper bound for inserting numbers,
	in order to save number of comparisons, as we know already that, for example,
	b5 is lesser than a5, we binary search only until a5, not until the end
	of the container. */
	std::list<Iterator>::iterator curr_bound = main.begin();
	std::vector<Iterator>::iterator curr_pend = pend.begin();
	/* Bound to insert elements start with a2, since pend starts with b2. */
	std::advance(curr_bound, 2);
	int prev_jacobsthal = jacobsthal_number(1);
	for (int k = 2; ; k++) {
		int curr_jacobsthal = jacobsthal_number(k);
		int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		if (jacobsthal_diff > static_cast<int>(pend.size()))
			break;
		int nbr_of_times = jacobsthal_diff;
		std::list<Iterator>::iterator bound_it = curr_bound;
		std::vector<Iterator>::iterator pend_it = curr_pend;
		std::advance(bound_it, jacobsthal_diff - 1);
		std::advance(pend_it, jacobsthal_diff - 1);
		while (nbr_of_times)
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
			// ...
			std::list<Iterator>::iterator idx = std::upper_bound(main.begin(), bound_it, *pend_it, comp);
			main.insert(idx, *pend_it);
			nbr_of_times--;
			pend_it = pend.erase(pend_it);
			std::advance(pend_it, -1);
			std::advance(bound_it, -1);
		}
		std::advance(curr_bound, jacobsthal_diff);
		prev_jacobsthal = curr_jacobsthal;
	}

	/* Insert the remaining elements in the sequential order. */
	while (!pend.empty()) {
		std::list<Iterator>::iterator idx = std::upper_bound(main.begin(), curr_bound, *curr_pend, comp);
		main.insert(idx, *curr_pend);
		pend.erase(curr_pend);
		curr_pend = pend.begin();
		std::advance(curr_bound, 1);
	}

	/* Insert an odd number to the main. */
	if (is_odd) {
		std::vector<int>::iterator odd_pair = end + pair_level - 1;
		std::list<Iterator>::iterator idx = std::upper_bound(main.begin(), main.end(), odd_pair, comp);
		main.insert(idx, odd_pair);
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

	/* Replace values in the original container. */
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
