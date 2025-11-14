#pragma once
#include <vector>
#include <list>

template <typename Item_Type>
class Sort {
public:
	// Wrapper for recursive linear search
	size_t linear_search(const std::vector<Item_Type>& data, const Item_Type& target);

	// Perform a linear search for target starting from pos_first
	size_t lin_search(const std::vector<Item_Type>& data, const Item_Type& target, size_t pos_last);
	
	// Perform an Insertion Sort on data
	void insertion_sort(std::list<Item_Type>& list);
};