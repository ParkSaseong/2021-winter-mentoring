#include "priority_queue.h"
#include <stdlib.h>

/**
 * 우선순위큐 확장
 */
static bool pq_expand(priority_queue *this) {
    this->body = realloc(this->body, this->capacity * 2 * sizeof(int));

    if (this->body == NULL)
        return false;
    
    this->capacity = this->capacity * 2;

    return true;
}

/**
 * 새로운 우선순위 큐를 만들어서 반환한다.
 * 우선순위 큐 공간을 동적 할당하고 초기화를 해줘야함.
 * 실패시 NULL 반환
 */
priority_queue *pq_alloc(int capacity) {
    priority_queue *this = malloc(sizeof(priority_queue));
    this->body = malloc(sizeof(int) * capacity);
    this->capacity = capacity;
    this->length = 0;

    return this;
}

/**
 * 우선순위큐 소멸자.
 * 동적 할당한 공간들을 해재한다.
 */
void pq_free(priority_queue *this) {
    free(this->body);
    free(this);
}

/**
 * 우선순위 큐의 맨 위 원소를 반환한다.
 */
int *pq_top(priority_queue *this) {
    if (pq_is_empty(this))
        return NULL;

    return &this->body[1];
}

/**
 * 우선순위큐에 원소를 삽입한다.
 * 성공시 true 반환, 실패시 false 반환
 */
bool pq_enqueue(priority_queue *this, int elem) {
    if (this->length + 1 == this->capacity) {
        bool success = pq_expand(this);
        if (success == false)
            return false;
    }

    int cur = ++this->length;

    while (cur != 1 && this->body[cur / 2] > elem) {
        this->body[cur] = this->body[cur / 2];
        cur /= 2;
    }
    this->body[cur] = elem;
    
    return true;
}

/**
 * 우선순위큐에서 맨 앞 원소를 제거한다.
 * 성공시 true 반환, 실패시 false 반환
 */
bool pq_dequeue(priority_queue *this) {
    if (pq_is_empty(this))
        return false;
    
    int last_elem = this->body[this->length--];

    int cur = 1;
    int child = 2;

    while (child <= this->length) {
        int left_child = this->body[child];
        int right_child = this->body[child + 1];
        if (child < this->length && left_child > right_child)
            child ++;
        if (last_elem <= this->body[child]) break;

        this->body[cur] = this->body[child];
        cur = child;
        child *= 2;
    }
    this->body[cur] = last_elem;

    return true;
}

/**
 * 우선순위 큐가 비어있는가?
 * 비어있으면 true반환, 아니면 false 반환
 */
bool pq_is_empty(priority_queue *this) {
    return this->length == 0;
}
