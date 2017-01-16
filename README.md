# Expandable-Queue

The expandable queue is still based on a circular array implementation, but now it can grow when the number
of queue elements exceeds the capacity of the queue.
To implement such a queue, you will need to use a dynamic array to hold all queue elements.
Any time the capacity is doubled, a new, larger dynamic array is created and is used to replace
the current array. Make sure you implement the BIG FOUR methods for the queue class to
avoid memory errors. You should throw exceptions for any invalid access of your queue. We
assume all dynamic memory allocations are successful for the expandable queue, so you don’t
need to worry about queue-full exceptions. Here’s an example of what your private data might
look like in your modified class (TYPE is an int):


private:
    TYPE * _arr;     // pointer to dynamic integer array
	int _front;      // index to the front element of queue
    int _size;       // number of current elements in queue
    int _capacity;   // current capacity 

Keep in mind that the queue only expands when its capacity reaches the limit. 
