#include "priority_queue.h"

int main() {
    priority_queue *pq = pq_alloc(4);

    pq_enqueue(pq, 1);
    pq_enqueue(pq, 2);
    pq_enqueue(pq, 3);
    
    int should = 1;
    while (!pq_is_empty(pq)) {
        int elem = *pq_top(pq);
        assert(should == elem);
        should ++;
    }

    puts("test 1 pass");
    return 0;
}
