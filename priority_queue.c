#include "priority_queue.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * 새로운 우선순위 큐를 만들어서 반환한다.
 * 우선순위 큐 공간을 동적 할당하고 초기화를 해줘야함.
 * 실패시 NULL 반환
 */
priority_queue *pq_alloc(int capacity) {
    priority_queue *PQ = malloc(sizeof(priority_queue));
    PQ->body = malloc(sizeof(int)*capacity);
    PQ->capacity = capacity;
    PQ->length = 0;
    return PQ;
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
    return &(this->body[1]);
}

/**
 * 우선순위큐에 원소를 삽입한다.
 * 성공시 true 반환, 실패시 false 반환
 */
bool pq_enqueue(priority_queue *this, int elem) {
    if (this->length+1 == this->capacity) {
        bool res = pq_expand(this);
        if (res == false) return false;
    }
    this->body[++this->length] = elem;
    int n = this->length;
    while(n != 1) {
        if (this->body[n] > this->body[n/2]) {
            int tmp = this->body[n/2];
            this->body[n/2] = this->body[n];
            this->body[n] = tmp;
            n = n/2;
        }
        else {
            break;
        }
    }
    return true;
}

/**
 * 우선순위큐에서 맨 앞 원소를 제거한다.
 * 성공시 true 반환, 실패시 false 반환
 */
bool pq_dequeue(priority_queue *this) {
    this->body[1] = this->body[this->length--];
    this->body[this->length+1] = 0;
    int n = 1;
    while (1) {
        if (n*2 >= this->length) {
            if (n*2 == this->length) {
                if (this->body[n] <this->body[n*2]) {
                    int tmp = this->body[n];
                    this->body[n] = this->body[n*2];
                    this->body[n*2] = tmp;
                    break;
                }
                else
                    break;
            }
            else
                break;
        }
        else {
            if (this->body[n*2] >= this->body[n*2+1]) {
                n = n*2;
            }
            else {
                n = n*2+1;
            }
            if (this->body[n] > this->body[n/2]) {
                int tmp = this->body[n];
                this->body[n] = this->body[n/2];
                this->body[n/2] = tmp;
            }
            else
                break;
        }
    }
    return this->body[this->length+1] == 0;
}
/**
 * 우선순위 큐가 비어있는가?
 * 비어있으면 true반환, 아니면 false 반환
 */
bool pq_is_empty(priority_queue *this) {
    return this->length == 0;
}


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
