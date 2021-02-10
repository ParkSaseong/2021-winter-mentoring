#include "priority_queue.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    priority_queue *pq = pq_alloc(8);

    bool is_pq_empty = pq_is_empty(pq);
    assert(is_pq_empty == true);

    assert(pq->body != NULL);
    assert(pq->capacity == 8);
    assert(pq->length == 0);

    puts("test 0 pass");
    return 0;
}
