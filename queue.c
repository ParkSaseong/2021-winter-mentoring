#include "queue.h"

/**
 * 새로운 queue를 만들어서 반환한다.
 * 실패시 NULL 리턴
 */
queue *queue_alloc(int capacity) {
    queue *Q = malloc(sizeof(queue));
    Q->body = malloc(sizeof(int)*capacity);
    Q->capacity = capacity;
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

/*
    동적할당된 공간들을 해재해준다.
*/
void queue_free(queue *this) {
    free(this->body);
    free(this);
}

/*
    return: 큐가 비어있으면 true, 아니면 false
*/
bool queue_is_empty(queue *this) {
    return this->front == this->rear;
}

/*
    return: 큐가 capacity만큼 차있다면 true, 아니면 false
*/
bool queue_is_full(queue *this) {
    return (this->rear + 1) % this->capacity == this->front;
}

/*
    큐가 가득 차 있는경우 큐을 확장한다.
    힌트: realloc 함수 사용

    return: 성공시 true 반환, 실패시 false
*/
bool queue_expand(queue *this) {
    if (queue_is_full(this)) {
        int array[this->capacity];
        for (int i=0; i<this->capacity; i++) {
            array[i] = *queue_front(this);
            this->front = (++this->front%this->capacity);
        }
        for (int i=0; i<this->capacity; i++) {
            this->body[i] = array[i];
        }
        this->front = -1;
        this->rear = this->capacity-1;

        this->body = realloc(this->body, sizeof(int)*this->capacity*2);
        this->capacity = this->capacity * 2;
        return true;
    }
    return false;
}

/*
    큐에 원소를 삽입한다.
    만약에 큐에 공간이 부족하다면 확장을 먼저 하고 삽입해야한다.

    return: 성공시 true, 실패시 false
*/
bool queue_enqueue(queue *this, int elem) {
    if (queue_is_full(this)) {
        bool res = queue_expand(this);
        if (res == false)
            return false;
    }
    this->rear = (this->rear + 1) % this->capacity;
    this->body[this->rear] = elem;
    return true;
}

/*
    
    return: 큐의 맨 앞에있는 원소의 주소를 리턴한다. (값이 아닌 주소를 리턴하는것에 주의한다)
    실패시 NULL을 리턴한다.
*/
int *queue_front(queue *this) {
    return &(this->body[this->front]);
}

/*
    큐에서 원소 하나를 제거한다. (맨앞에 있는 원소)

    return: 성공시 true, 실패시 false
    만약에 이미 비어있어서 더이상 뺄것이 없다면 pop연산은 실패한것으로 간주하고 false 반환
*/
bool queue_dequeue(queue *this) {
    if (queue_is_empty(this)) {
        return false;
    }
    this->body[this->front++] = 0;
    return true;
}