#pragma once
#pragma once
#include <stddef.h>
#include <stdbool.h>

typedef struct deque_node {
    void* data;
    struct deque_node* prev;
    struct deque_node* next;
} deque_node;

typedef struct deque {
    size_t size;
    deque_node* front;
    deque_node* rear;
} deque;


deque* new_deque(void);
bool is_deque_empty(const deque* dq);
size_t deque_size(const deque* dq);
bool deque_push_front(deque* dq, void* element);
void* deque_pop_front(deque* dq);
void deque_pop_front_and_free(deque* dq);
void* deque_front(const deque* dq);
bool deque_push_back(deque* dq, void* element);
void* deque_pop_back(deque* dq);
void deque_pop_back_and_free(deque* dq);
void* deque_back(const deque* dq);
void deque_clear(deque* dq);
void deque_clear_and_free(deque* dq);
void deque_destroy(deque* dq);
void deque_destroy_and_free(deque* dq);