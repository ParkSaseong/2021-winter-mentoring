#include "hash_table.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    hash_table *table = hash_table_alloc();


    hash_table_insert(table, "abcde", "fghijk");
    hash_table_insert(table, "해쉬", "테이블");
    hash_table_insert(table, "대한민국", "만세");
    hash_table_insert(table, "대한", "민국");
    hash_table_insert(table, "고구려", "백제");
    hash_table_insert(table, "백제", "신라");
    

    char *result = hash_table_get(table, "abcde");
    assert(strcmp(result, "fghijk") == 0);

    result = hash_table_get(table, "해쉬");
    assert(strcmp(result, "테이블") == 0);

    result = hash_table_get(table, "대한민국");
    assert(strcmp(result, "만세") == 0);

    result = hash_table_get(table, "대한");
    assert(strcmp(result, "민국") == 0);

    result = hash_table_get(table, "고구려");
    assert(strcmp(result, "백제") == 0);

    result = hash_table_get(table, "백제");
    assert(strcmp(result, "신라") == 0);

    hash_table_free(table);
    puts("test 1 pass");
    return 0;
}
