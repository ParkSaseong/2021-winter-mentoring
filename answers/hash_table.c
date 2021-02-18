#include "hash_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int hash_func(char *string, int max) {
    int len = strlen(string);
    unsigned long long hash = 0;

    for (int i = 0; i < len; i++) {
        hash = (((hash << 5) + hash) + string[i]) % max;
    }

    return hash % max;
}

/**
 * 새로운 해쉬 테이블을 만들고 주소를 반환한다.
 * 실패시 NULL반환
 */
hash_table *hash_table_alloc(void) {
    hash_table *this = malloc(sizeof(hash_table));
    this->body = malloc(sizeof(element) * 12345);
    this->capacity = 12345;

    for (int i = 0; i < this->capacity; i++) {
        this->body[i].key = NULL;
        this->body[i].val = NULL;
    }

    return this;
}

/**
 * 해쉬 테이블 동적메모리 해제
 */
void hash_table_free(hash_table *this) {
    for (int i = 0; i < this->capacity; i++) {
        if (this->body[i].key != NULL) {
            free(this->body[i].key);
            free(this->body[i].val);
        }
    }
    free(this->body);
    free(this);
}

/**
 * 해쉬 테이블에 key: value 삽입
 */
bool hash_table_insert(hash_table *this, char *key, char *val) {
    int hash = hash_func(key, this->capacity);

    for (int i = hash; ; i = (i + 1) % this->capacity) {
        if (this->body[i].key != NULL)
            continue;
        this->body[i].key = strdup(key);
        this->body[i].val = strdup(val);
        return true;
    }

    return false;
}

/**
 * 해쉬 테이블에서 키를 검색해서 value의 주소를 리턴한다.
 * 찾지 못했을 경우는 NULL 리턴
 */
char *hash_table_get(hash_table *this, char *key) {
    int hash = hash_func(key, this->capacity);

    for (int i = hash; ; i = (i + 1) % this->capacity) {    
        if (this->body[i].key == NULL)
            return NULL;
        
        if (strcmp(this->body[i].key, key) == 0)
            return this->body[i].val;
        
    }

    return NULL;
}

/**
 * 해쉬 테이블에서 키를 검색해서 해당 원소 삭제.
 * 실패시 (찾지 못할경우) false리턴
 */
bool hash_table_remove(hash_table *this, char *key) {
    int hash = hash_func(key, this->capacity);

    for (int i = hash; ; i = (i + 1) % this->capacity) {
        if (this->body[i].key == NULL)
            return false;
        
        if (strcmp(this->body[i].key, key) == 0) {
            free(this->body[i].key);
            free(this->body[i].val);
            this->body[i].key = NULL;
            this->body[i].val = NULL;
            return true;
        }
    }
    return false;
}
