#pragma once
#include <stddef.h>
#include <stdbool.h>

typedef struct queue_node {
	void* data;
	struct queue_node* next;
}queue_node;

typedef struct queue{
	size_t size;
	queue_node* front;
	queue_node* end;
}queue;


queue* new_queue();
bool is_queue_empty(queue* q);
bool queue_push(queue* q, void* element);
void* queue_front(queue* q);
void* queue_end(queue* q);
void* queue_pop(queue* q);
void queue_pop_and_free(queue* q);
size_t queue_size(queue* q);
void queue_destroy(queue* q);
void queue_destroy_and_free(queue* q);
void queue_clear(queue* q);
void queue_clear_and_free(queue* q);


