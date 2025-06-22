#pragma once

#include <stdlib.h>
#include <stdbool.h>

#define DS_SIZED_INT_QUEUE_SIZE 8



typedef struct
{
    size_t front_;
    size_t rear_;
    int arr_[DS_SIZED_INT_QUEUE_SIZE];
} Queue;

void queue_init(Queue* const q);
bool queue_enqueue(Queue* const q, const int val);
bool queue_dequeue(Queue* const q, int* const return_val);
bool queue_top(const Queue* const q, int* const return_val);
bool queue_empty(const Queue* const q);
bool queue_full(const Queue* const q);
void queue_print(const Queue* const q);