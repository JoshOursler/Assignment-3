#pragma once

// create a template class Queue
template <typename Item_Type>
class Queue {
public:
	// Declare member functions
	// Constructor
	Queue() : data(new Item_Type[DEFAULT_CAPACITY]), front_index(0), rear_index(-1), num_items(0), capacity(10) {};

	// Push an item to the back of the queue
	void push(const Item_Type& item);

	// Pop an item from the front of the queue
	void pop();

	// Get the front item of the queue
	Item_Type front() const;

	// Return the size of the queue
	size_t size() const;

	// Check if the queue is empty
	bool empty() const;

	// Reallocate the queue with a new capacity
	void reallocate();

	// Move the front item to the rear of the queue
	void move_to_rear();

	// Destructor
	~Queue() {
		delete data;
	};
private:
	// Data fields
	static const size_t DEFAULT_CAPACITY = 10;
	size_t front_index;
	size_t rear_index;
	size_t num_items;
	size_t capacity;
	Item_Type* data;
};

