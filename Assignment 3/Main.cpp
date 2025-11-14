#include "Queue.h"
#include "Sort.h"
#include <iostream>

int main() {
	// Declare a Queue of integers
	Queue<int> numbers;

	// Push 10 integers to the queue
	numbers.push(83);
	numbers.push(23);
	numbers.push(14);
	numbers.push(60);
	numbers.push(80);
	numbers.push(36);
	numbers.push(22);
	numbers.push(31);
	numbers.push(56);
	numbers.push(7);

	// Chekc the move_to_rear function
	numbers.move_to_rear(); // Moves 83 to the rear

	// Pop and print each integer from the queue while pushing it back to the end
	for (size_t i = 0; i < numbers.size(); i++) {
		int printed_number = numbers.front();
		std::cout << printed_number << std::endl;
		numbers.pop();
		numbers.push(printed_number);
	}
	

	std::vector<int> data = { 4, 2, 3, 5, 1, 3, 5, 6, 4 };
	size_t index = Sort<int>().linear_search(data, 5);

	std::cout << "Index of 5: " << index << std::endl;

	std::list<int> list_data = { 4, 2, 3, 5, 1, 3, 5, 6, 4 };
	Sort<int>().insertion_sort(list_data);

	std::cout << "Sorted list: ";
	for (const auto& item : list_data) {
		std::cout << item << " ";
	}

	return 0;
};