#include "priority_queue.h"
#include <stdio.h>
#include <assert.h>

int main() {
    priority_queue *pq = pq_alloc(4);

    pq_enqueue(pq, 1);
    pq_enqueue(pq, 2);
    pq_enqueue(pq, 3);
    pq_enqueue(pq, 4);
    pq_enqueue(pq, 5);
    pq_enqueue(pq, 6);
    pq_enqueue(pq, 7);
    pq_enqueue(pq, 8);
    pq_enqueue(pq, 9);
    pq_enqueue(pq, 10);
    
    
    int should = 10;
    while (!pq_is_empty(pq)) {
        int elem = *pq_top(pq);
        pq_dequeue(pq);
        assert(should == elem);
        should --;
    }

    puts("test 2 pass");
    return 0;
}
