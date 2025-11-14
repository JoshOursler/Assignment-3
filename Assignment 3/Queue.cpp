#include "Queue.h"
#include <stdexcept>

// Define member functions
// Push an item to the back of the queue
template <typename Item_Type>
void Queue<Item_Type>::push(const Item_Type& item) {
	// Check if the queue is full and reallocate if necessary
	if (num_items == capacity) {
		reallocate();
	}

	// Add the new item to the rear of the queue
	num_items++;
	rear_index = (rear_index + 1) % capacity;
	data[rear_index] = item;
};

// Pop an item from the front of the queue
template <typename Item_Type>
void Queue<Item_Type>::pop() {
	// Check if the queue is empty
	if (empty()) {
		throw std::out_of_range("Queue is empty");
	}

	// Remove the front item from the queue
	front_index = (front_index + 1) % capacity;
	num_items--;
};

// Get the front item of the queue
template <typename Item_Type>
Item_Type Queue<Item_Type>::front() const {
	// Check if the queue is empty
	if (empty()) {
		throw std::out_of_range("Queue is empty");
	}

	// Return the front item of the queue
	return data[front_index];
};

// Return the size of the queue
template <typename Item_Type>
size_t Queue<Item_Type>::size() const {
	return num_items;
};

// Check if the queue is empty
template <typename Item_Type>
bool Queue<Item_Type>::empty() const {
	return num_items == 0;
};

// Reallocate the queue with a new capacity
template <typename Item_Type>
void Queue<Item_Type>::reallocate() {
	// Create a new temporary array with the new capacity
	size_t new_capacity = capacity * 2;
	Item_Type* tmp = new Item_Type[new_capacity];
	size_t j = front_index;

	// Copy the elements from the old data vector to the new temporary vector
	for (size_t i = 0; i < num_items; i++) {
		tmp[i] = data[j];
		j = (j + 1) % capacity;
	}

	// Set data to the new temporary vector and update indices and capacity
	std::swap(data, tmp);
	front_index = 0;
	rear_index = num_items - 1;
	capacity = new_capacity;

	delete[] tmp;
};

// Move the front item to the rear of the queue
template <typename Item_Type>
void Queue<Item_Type>::move_to_rear() {
	// Check if the queue is empty
	if (empty()) {
		throw std::out_of_range("Queue is empty");
	}

	// Move the front item to the rear of the queue
	Item_Type front_item = front();
	pop();
	push(front_item);
};

// Explicitly instantiate the template for int type
template class Queue<int>;