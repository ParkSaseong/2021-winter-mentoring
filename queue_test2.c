#include "queue.h"
#include <assert.h>

int main() {
    queue *q = queue_alloc(2);
    int *res;

    queue_enqueue(q, 10);
    queue_enqueue(q, 20);
    queue_enqueue(q, 30);
    queue_enqueue(q, 40);
    queue_enqueue(q, 50);
    queue_enqueue(q, 60);

    res = queue_front(q);
    assert(*res == 10);

    queue_dequeue(q);
    res = queue_front(q);
    assert(*res == 20);

    queue_dequeue(q);
    res = queue_front(q);
    assert(*res == 30);

    queue_dequeue(q);
    res = queue_front(q);
    assert(*res == 40);

    queue_dequeue(q);
    res = queue_front(q);
    assert(*res == 50);

    queue_dequeue(q);
    res = queue_front(q);
    assert(*res == 60);

    puts("queue expand test pass");
}
