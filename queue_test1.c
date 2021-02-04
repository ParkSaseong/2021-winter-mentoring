#include "queue.h"
#include <assert.h>

int main() {
    queue *q = queue_alloc(4);

    queue_enqueue(q, 10);
    queue_enqueue(q, 20);

    int *res = queue_front(q);
    assert(*res == 10);

    queue_dequeue(q);
    res = queue_front(q);
    assert(*res == 20);

    puts("queue test1 pass");
}
