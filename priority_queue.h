#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include <stdbool.h>

typedef struct {
    int *body;
    int capacity;
    int length;
} priority_queue;

/**
 * 새로운 우선순위 큐를 만들어서 반환한다.
 * 우선순위 큐 공간을 동적 할당하고 초기화를 해줘야함.
 * 실패시 NULL 반환
 */
priority_queue *pq_alloc(int capacity);

/**
 * 우선순위큐 소멸자.
 * 동적 할당한 공간들을 해재한다.
 */
void pq_free(priority_queue *this);

/**
 * 우선순위 큐의 맨 위 원소를 반환한다.
 */
int *pq_top(priority_queue *this);

/**
 * 우선순위큐에 원소를 삽입한다.
 * 성공시 true 반환, 실패시 false 반환
 */
bool pq_enqueue(priority_queue *this, int elem);

/**
 * 우선순위큐에서 맨 앞 원소를 제거한다.
 * 성공시 true 반환, 실패시 false 반환
 */
bool pq_dequeue(priority_queue *this);

/**
 * 우선순위 큐가 비어있는가?
 * 비어있으면 true반환, 아니면 false 반환
 */
bool pq_is_empty(priority_queue *this);

#endif /* PRIORITY_QUEUE_H */
