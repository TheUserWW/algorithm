#include "../include/queue.h"
#include <stdlib.h>

queue* new_queue() {
	queue* q = (queue*)malloc(sizeof(queue));
	if (!q) {
		return NULL;
	}
	q->size = 0;
	q->front = NULL;
	q->end = NULL;

	return q;
}

bool is_queue_empty(queue* q) {
	return q->front == NULL && q->end == NULL;
}

bool queue_push(queue* q, void* element) {
	queue_node* new_node = (queue_node*)malloc(sizeof(queue_node));
	if (!new_node) {
		return false;
	}
	
	new_node->data = element;
	new_node->next = NULL;
	
	if (is_queue_empty(q)) {
		q->front = new_node;
		q->end = new_node;
	} else {
		q->end->next = new_node;
		q->end = new_node;
	}
	
	q->size++;
	return true;
}

void* queue_front(queue* q) {
	if (is_queue_empty(q)) {
		return NULL;
	}

	return q->front->data;
}

void* queue_end(queue* q) {
	if (is_queue_empty(q)) {
		return NULL;
	}
	
	return q->end->data;
}

void* queue_pop(queue* q) {
	if (is_queue_empty(q)) {
		return NULL;
	}
	
	queue_node* temp = q->front;
	void* data = temp->data;
	
	q->front = q->front->next;
	if (q->front == NULL) {
		q->end = NULL;
	}
	
	free(temp);
	q->size--;
	return data;
}

size_t queue_size(queue* q) {
	return q->size;
}

void queue_destroy(queue* q) {
	if (!q) return;
	
	// 释放所有节点
	while (!is_queue_empty(q)) {
		queue_pop(q);
	}
	
	// 释放队列结构体
	free(q);
}

void queue_clear(queue* q) {
	if (!q) return;
	
	// 释放所有节点但保留队列结构体
	while (!is_queue_empty(q)) {
		queue_pop(q);
	}
	
	q->size = 0;
}

void queue_pop_and_free(queue* q) {
	if (is_queue_empty(q)) {
		return;
	}
	
	queue_node* temp = q->front;
	
	// 释放数据内存
	if (temp->data != NULL) {
		free(temp->data);
	}
	
	q->front = q->front->next;
	if (q->front == NULL) {
		q->end = NULL;
	}
	
	free(temp);
	q->size--;
}

void queue_destroy_and_free(queue* q) {
	if (!q) return;
	
	// 释放所有节点和数据
	while (!is_queue_empty(q)) {
		queue_pop_and_free(q);
	}
	
	// 释放队列结构体
	free(q);
}

void queue_clear_and_free(queue* q) {
	if (!q) return;
	
	// 释放所有节点和数据但保留队列结构体
	while (!is_queue_empty(q)) {
		queue_pop_and_free(q);
	}
	
	q->size = 0;
}

