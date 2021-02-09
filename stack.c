#include "stack.h"

/**
 * 새로운 stack을 만들어서 반환한다.
 * 실패시 NULL 리턴
 */
stack *stack_alloc(int capacity) {
    stack *this = malloc(sizeof(stack));
    this->body = malloc(sizeof(element)*capacity);
    this->capacity = capacity;
    this->top = -1;
    return this;
}

/*
    동적할당된 공간들을 해재해준다.
*/
void stack_free(stack *this) {
    free(this->body);
    free(this);
}

/*
    return: 스택이 비어있으면 true, 아니면 false
*/
bool stack_is_empty(stack *this) {
    return this->top == -1;
}

/*
    return: 스택이 capacity만큼 차있다면 true, 아니면 false
*/
bool stack_is_full(stack *this) {
    return this->top+1 == this->capacity;
}

/*
    스택이 가득 차 있는경우 스택을 확장한다.
    힌트: realloc 함수 사용

    return: 성공시 true 반환, 실패시 false
*/
bool stack_expand(stack *this) {
    /*
    if (stack_is_full(this)) {
        this->body = realloc(this->body, sizeof(element)*this->capacity*2);
        this->capacity = this->capacity*2;
        return true;
    }
    return false;
    */
    this->body = realloc(this->body, this->capacity * 2 * sizeof(element));
    this->capacity = this->capacity * 2;

    return this->body != NULL;   
}

/*
    스택에 원소를 삽입한다.
    만약에 스택에 공간이 부족하다면 확장을 먼저 하고 삽입해야한다.

    return: 성공시 true, 실패시 false
*/
bool stack_push(stack *this, element elem) {
    if (stack_is_full(this)) {
        bool res = stack_expand(this);
        if (res == false)
            return false;
    }
    this->body[++this->top] = elem;
    return true;
}

/*
    
    return: 스택의 맨 위에있는 원소의 주소를 리턴한다. (값이 아닌 주소를 리턴하는것에 주의한다)
    실패시 NULL을 리턴한다.
*/
element *stack_top(stack *this) {
    if (stack_is_empty(this)) {
        return NULL;
    }
    return &(this->body[this->top]);
}

/*
    스택에서 원소 하나를 제거한다. (맨위에 있는 원소)

    return: 성공시 true, 실패시 false
    만약에 이미 비어있어서 더이상 뺄것이 없다면 pop연산은 실패한것으로 간주하고 false 반환
*/
bool stack_pop(stack *this) {
    if (stack_is_empty(this)) {
        return false;
    }
    this->body[this->top--] = (element) {
        .number = -1,
        .name = "deleted",
    };
    return true;
}