/* This test driver tests queue interface methods using C asserts */

#include "queueexp.h"
#include <cassert>

int main(){
    queue q1;
	
	for(int i=1; i<=1050; i++)
		q1.enqueue(i);

    assert(q1.size()==1050);
	assert(q1.capacity()==2048);
	assert(q1.front()==1);
	
	queue q2;
    assert(q2.size()==0);
	assert(q2.capacity()==8);

    // assignment operator 
    q2 = q1;
    assert(q2.size()==1050);
	assert(q2.capacity()==2048);
	assert(q2.front()==1);
	
	
	for(int i=1; i<1050; i++)
		q2.dequeue();
    assert(q2.size()==1);
	assert(q2.capacity()==2048);
	assert(q2.front()==1050);

    assert(q1.size()==1050);
	assert(q1.capacity()==2048);
	assert(q1.front()==1);

	for(int i=1; i<=1050; i++)
		q2.enqueue(i);
    assert(q2.size()==1051);
	assert(q2.capacity()==2048);
	assert(q2.front()==1050);
}

