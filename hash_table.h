#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>

typedef struct {
    char *key;
    char *val;
} element;

typedef struct {
    int capacity;
    element *body;
} hash_table;

/**
 * 새로운 해쉬 테이블을 만들고 주소를 반환한다.
 * 실패시 NULL반환
 */
hash_table *hash_table_alloc(void);

/**
 * 해쉬 테이블 동적메모리 해제
 */
void hash_table_free(hash_table *this);

/**
 * 해쉬 테이블에 key: value 삽입
 */
bool hash_table_insert(hash_table *this, char *key, char *val);

/**
 * 해쉬 테이블에서 키를 검색해서 value의 주소를 리턴한다.
 * 찾지 못했을 경우는 NULL 리턴
 */
char *hash_table_get(hash_table *this, char *key);

/**
 * 해쉬 테이블에서 키를 검색해서 해당 원소 삭제.
 * 실패시 (찾지 못할경우) false리턴
 */
bool hash_table_remove(hash_table *this, char *key);

#endif /* HASH_TABLE_H */
