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
    
    char *result = hash_table_get(table, "abcd");
    assert(result == NULL);
    
    result = hash_table_get(table, "해");
    assert(result == NULL);
    
    result = hash_table_get(table, "대한민국1");
    assert(result == NULL);
    
    result = hash_table_get(table, "대한asdf");
    assert(result == NULL);
    
    hash_table_free(table);
    puts("test 2 pass");
    return 0;
}
