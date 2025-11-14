#include "Sort.h"
#include <iterator>
#include <algorithm>

// Wrapper for recursive linear search
template <typename Item_Type>
size_t Sort<Item_Type>::linear_search(const std::vector<Item_Type>& data, const Item_Type& target) {
	return lin_search(data, target, data.size() - 1);
}

template <typename Item_Type>
size_t Sort<Item_Type>::lin_search(const std::vector<Item_Type>& data, const Item_Type& target, size_t pos_last) {
	if (pos_last == 0 && data[pos_last] != target) {
		return static_cast<size_t>(-1); // Return default value if starting position is out of bounds
	}

	if (target == data[pos_last]) {
		return pos_last; // Target found
	}
	else {
		return lin_search(data, target, pos_last - 1); // Recursive call
	}
}

// Perform an Insertion Sort on a linked list
template <typename Item_Type>
void Sort<Item_Type>::insertion_sort(std::list<Item_Type>& list) {
	if (list.size() < 2) return; // Nothing to sort

	// Iterate through each element starting from the second
	for (auto iter = std::next(list.begin()); iter != list.end(); ++iter) {
		Item_Type key = *iter;	// Current element to be positioned
		auto pos = std::prev(iter); // Position to compare with

		// Move elements backwards while key is less than *pos
		while (key < *pos) {
			std::iter_swap(std::next(pos), pos); // Swap elements

			// Stop if we reached the beginning of the list
			if (pos == list.begin()) break;
			--pos; // Move to the previous position
		}
	}
}

// Explicit template instantiation for int type
template class Sort<int>;