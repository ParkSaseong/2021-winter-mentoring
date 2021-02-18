#include "hash_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#define TEST

static unsigned int hash(char *string) {
    unsigned int ret = 0;
    for (int i = 0; i<strlen(string); i++) {
        ret += string[i];
    }
    return (ret%1024);
}
/**
 * 새로운 해쉬 테이블을 만들고 주소를 반환한다.
 * 실패시 NULL반환
 */
hash_table *hash_table_alloc(void){
    hash_table *hst = malloc(sizeof(hash_table));
    hst->capacity = 1024;
    hst->body = malloc(sizeof(element)*hst->capacity);
    for (int i=0; i<hst->capacity; i++) {
        hst->body[i].key = NULL;
        hst->body[i].val = NULL;
    }
    return hst;
}

/**
 * 해쉬 테이블 동적메모리 해제
 */
void hash_table_free(hash_table *this) {
    free(this->body);
    free(this);
}

/**
 * 해쉬 테이블에 key: value 삽입
 */
bool hash_table_insert(hash_table *this, char *key, char *val) {
    unsigned int hs = hash(key);
    int i = hs;
    while (1) {
        if(this->body[hs].key == NULL) {
            this->body[hs].key = key;
            this->body[hs].val = val;
            return true;
        }
        else {
            hs = (hs+1)%1024;
            if (hs == i) {
                return false;
            }
        }
    }
}

/**
 * 해쉬 테이블에서 키를 검색해서 value의 주소를 리턴한다.
 * 찾지 못했을 경우는 NULL 리턴
 */
char *hash_table_get(hash_table *this, char *key) {
    unsigned int hs = hash(key);
    unsigned int i = hs;
    char *string = strdup(key);
    while (1) {
        if (this->body[hs].key == NULL)
            return NULL;
        if (strcmp(this->body[hs].key, string) == 0) {
            return this->body[hs].val;
        }
        else {
            hs = (hs+1)%1024;
            if(hs == i) {
                return NULL;
            }
        }
    }
}

/**
 * 해쉬 테이블에서 키를 검색해서 해당 원소 삭제.
 * 실패시 (찾지 못할경우) false리턴
 */
bool hash_table_remove(hash_table *this, char *key) {
    unsigned int hs = hash(key);
    int i = hs;
    char *string = strdup(key);
    while (1) {
        if (this->body[hs].key == NULL)
            return false;
        if (strcmp(this->body[hs].key, string) == 0) {
            this->body[hs].key = NULL;
            this->body[hs].val = NULL;
        }
        else {
            hs = (hs+1)%1024;
            if(hs == i) {
                return false;
            }
        }
    }
}

#ifdef TEST

int main() {
    hash_table *hst = hash_table_alloc();
    hash_table_insert(hst, "박사성", "10");
    char *s = hash_table_get(hst, "박사성");
    printf("%s", s);
    // printf("%s %s", hst->body[hash("박사성")].key, hst->body[hash("박사성")].val);
}
#endif /* TEST */
