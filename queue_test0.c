#include "queue.h"
#include <assert.h>

int main() {
    queue *q = queue_alloc(8);

    bool res = queue_dequeue(q);
    assert(res == false);
}
