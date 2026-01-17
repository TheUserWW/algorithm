#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef struct stack_node {
    void* data;
    struct stack_node* next;
} stack_node;

typedef struct stack {
    size_t size;
    stack_node* top;
} stack;

stack* new_stack(void);
bool is_stack_empty(const stack* st);
bool stack_push(stack* st, void* element);
void* stack_top(stack* st);
void* stack_pop(stack* st);
void stack_pop_and_free(stack* st);
size_t stack_size(stack* st);
void stack_destroy(stack* st);
void stack_destroy_and_free(stack* st);
void stack_clear(stack* st);
void stack_clear_and_free(stack* st);
