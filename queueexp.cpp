#include "queueexp.h"

// circular dynamic array implementation of queue ADT

// consturctor create a new stack of given capacity
// parameter:
//    capacity: the initial capacity of the stack, default to INITCAP
queue::queue(int capacity): _capacity(capacity), _size(0){
    _arr = new TYPE[_capacity];
    for(int i=0; i < _capacity; i++)
        _arr[i] = 0;
    _front = 0;  // front points to queue front
}

// copy constructor create a new queue whick is a deep copy
// of the rhs stack. 
// parameter:
//    rhs: the queue object to copy from
// returns: n/a 
queue::queue(const queue& rhs){
    _size = rhs._size;
	_front = 0;
    _capacity = rhs._capacity;
    _arr = new TYPE[_capacity];
    for(int i=0; i < _size; i++)
        _arr[i] = rhs._arr[((rhs._front)+i) % _capacity];
}

// assignment operator
// parameter:
//    rhs: the stack object to be assigned from 
// returns: a deep copy of the rhs stack object
queue& queue::operator=(const queue& rhs) {
    if (this != &rhs){
        _capacity = rhs._capacity;
        _size = rhs._size;
		_front = 0;
        delete [] _arr;
        _arr = new TYPE[_capacity];
        for ( int i=0; i<_size; i++ )
           _arr[i] = rhs._arr[((rhs._front)+i) % _capacity];
    }
    return *this;
}

queue::~queue(){ delete [] _arr; }

void queue::enqueue(TYPE data){
    if(_size == _capacity){
        int * temp = new TYPE[_capacity*2];  // double the size
        for ( int i=0; i<_size; i++ )
            temp[i] = _arr[_front++ % _capacity];
        delete [] _arr;
        _arr = temp;
		_front=0;
		_capacity *= 2;
    }
    int pos = (_front+_size) % _capacity;
    _arr[pos] = data;
    _size++;  
}

// precondition: queue is not empty
TYPE queue::dequeue(){
    if(_size == 0)
        throw EmptyQueueException();
	
    int pos = _front; 
    _front = (_front+1) % _capacity;
    _size--; 
	
    return _arr[pos];
}

TYPE& queue::front(){
    if(_size == 0)
        throw EmptyQueueException();
	
    return _arr[_front];
}

int queue::size(){
    return _size;
}

bool queue::empty(){
    return (_size == 0) ? true : false;
}

// return the capacity of the queue
int queue::capacity(){
    return _capacity;
}

void queue::dump(ostream &os){
    for(int i=0; i<_size; i++)
        os << _arr[(_front+i)%_capacity] << " ";
	os << endl;
}



