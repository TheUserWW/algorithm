#include "../include/stack.h"
#include <stdlib.h>

stack* new_stack(void) {
    stack* st = (stack*)malloc(sizeof(stack));
    if (!st) {
        return NULL;
    }
    st->size = 0;
    st->top = NULL;
    return st;
}

bool is_stack_empty(const stack* st) {
    return st->top == NULL;
}

void* stack_top(stack* st) {
    if (is_stack_empty(st)) {
        return NULL;
    }
    return st->top->data;
}

bool stack_push(stack* st, void* element) {
    stack_node* new_node = (stack_node*)malloc(sizeof(stack_node));
    if (!new_node) {
        return false;
    }
    new_node->next = st->top;
    new_node->data = element;
    st->top = new_node;
    st->size++;
    return true;
}

void* stack_pop(stack* st) {
    if (!is_stack_empty(st)) {
        stack_node* temp = st->top;
        void* ret = temp->data;
        st->top = st->top->next;
        free(temp);

        return ret;
    }
    else {
        return NULL;
    }
}

size_t stack_size(stack* st) {
    return st->size;
}

void stack_destroy(stack* st) {
    if (!st) return;


    while (!is_stack_empty(st)) {
        stack_pop(st);
    }

    free(st);
}

void stack_clear(stack* st) {
    if (!st) return;


    while (!is_stack_empty(st)) {
        stack_pop(st);
    }
    st->size = 0;
}


void stack_pop_and_free(stack* st) {
    if (!is_stack_empty(st)) {
        stack_node* temp = st->top;

        if (temp->data != NULL) {
            free(temp->data);
        }

        st->top = st->top->next;
        free(temp);
        st->size--;
    }
}

void stack_destroy_and_free(stack* st) {
    if (!st) return;
    while (!is_stack_empty(st)) {
        stack_pop_and_free(st);
    }

    free(st);
}

void stack_clear_and_free(stack* st) {
    if (!st) return;
    while (!is_stack_empty(st)) {
        stack_pop_and_free(st);
    }
    st->size = 0;
}