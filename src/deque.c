#include "../include/deque.h"
#include <stdlib.h>

deque* new_deque(void) {
    deque* dq = (deque*)malloc(sizeof(deque));
    if (!dq) {
        return NULL;
    }
    dq->size = 0;
    dq->front = NULL;
    dq->rear = NULL;
    return dq;
}

bool is_deque_empty(const deque* dq) {
    return dq->front == NULL && dq->rear == NULL;
}

size_t deque_size(const deque* dq) {
    return dq->size;
}

bool deque_push_front(deque* dq, void* element) {
    deque_node* new_node = (deque_node*)malloc(sizeof(deque_node));
    if (!new_node) {
        return false;
    }

    new_node->data = element;
    new_node->prev = NULL;
    new_node->next = dq->front;

    if (is_deque_empty(dq)) {
        dq->rear = new_node;
    }
    else {
        dq->front->prev = new_node;
    }

    dq->front = new_node;
    dq->size++;
    return true;
}

bool deque_push_back(deque* dq, void* element) {
    deque_node* new_node = (deque_node*)malloc(sizeof(deque_node));
    if (!new_node) {
        return false;
    }

    new_node->data = element;
    new_node->next = NULL;
    new_node->prev = dq->rear;

    if (is_deque_empty(dq)) {
        dq->front = new_node;
    }
    else {
        dq->rear->next = new_node;
    }

    dq->rear = new_node;
    dq->size++;
    return true;
}

void* deque_pop_front(deque* dq) {
    if (is_deque_empty(dq)) {
        return NULL;
    }

    deque_node* temp = dq->front;
    void* data = temp->data;

    dq->front = dq->front->next;
    if (dq->front == NULL) {
        dq->rear = NULL;
    }
    else {
        dq->front->prev = NULL;
    }

    free(temp);
    dq->size--;
    return data;
}

void* deque_pop_back(deque* dq) {
    if (is_deque_empty(dq)) {
        return NULL;
    }

    deque_node* temp = dq->rear;
    void* data = temp->data;

    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) {
        dq->front = NULL;
    }
    else {
        dq->rear->next = NULL;
    }

    free(temp);
    dq->size--;
    return data;
}

void deque_pop_front_and_free(deque* dq) {
    if (is_deque_empty(dq)) {
        return;
    }

    deque_node* temp = dq->front;

    // 释放数据内存
    if (temp->data != NULL) {
        free(temp->data);
    }

    dq->front = dq->front->next;
    if (dq->front == NULL) {
        dq->rear = NULL;
    }
    else {
        dq->front->prev = NULL;
    }

    free(temp);
    dq->size--;
}

void deque_pop_back_and_free(deque* dq) {
    if (is_deque_empty(dq)) {
        return;
    }

    deque_node* temp = dq->rear;

    // 释放数据内存
    if (temp->data != NULL) {
        free(temp->data);
    }

    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) {
        dq->front = NULL;
    }
    else {
        dq->rear->next = NULL;
    }

    free(temp);
    dq->size--;
}

void* deque_front(const deque* dq) {
    if (is_deque_empty(dq)) {
        return NULL;
    }
    return dq->front->data;
}

void* deque_back(const deque* dq) {
    if (is_deque_empty(dq)) {
        return NULL;
    }
    return dq->rear->data;
}

void deque_clear(deque* dq) {
    if (!dq) return;

    while (!is_deque_empty(dq)) {
        deque_pop_front(dq);
    }

    dq->size = 0;
}

void deque_clear_and_free(deque* dq) {
    if (!dq) return;

    while (!is_deque_empty(dq)) {
        deque_pop_front_and_free(dq);
    }

    dq->size = 0;
}

void deque_destroy(deque* dq) {
    if (!dq) return;

    deque_clear(dq);
    free(dq);
}

void deque_destroy_and_free(deque* dq) {
    if (!dq) return;

    deque_clear_and_free(dq);
    free(dq);
}