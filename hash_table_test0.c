#include "hash_table.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    hash_table *table = hash_table_alloc();

    assert(table != NULL);
    hash_table_free(table);

    puts("test 0 pass");
    return 0;
}
