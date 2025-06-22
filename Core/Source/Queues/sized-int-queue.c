

#include "sized-int-queue.h"
#include <stdio.h>

void
queue_init(
    Queue* const q)
{
    q->front_ = 0;
    q->rear_ = 0;
}


bool
queue_enqueue(
    Queue* const q,
    const int val)
{
    if (queue_full(q))
    {
        return false;
    }

    q->arr_[q->rear_] = val;
    q->rear_ = (q->rear_ + 1) % DS_SIZED_INT_QUEUE_SIZE;
    return true;
}


bool
queue_dequeue(
    Queue* const q,
    int* const return_val)
{
    if (queue_empty(q))
    {
        return false;
    }

    *return_val = q->arr_[q->front_];
    q->front_ = (q->front_ + 1) % DS_SIZED_INT_QUEUE_SIZE;
    return true;
}


bool
queue_top(
    const Queue* const q,
    int* const return_val)
{
    if (queue_empty(q))
    {
        return false;
    }
    *return_val = q->arr_[q->front_];
    return true;
}


bool
queue_empty(
    const Queue* const q)
{
    return (q->front_ == q->rear_);
}


bool
queue_full(
    const Queue* const q)
{
    return ((q->rear_ + 1) % DS_SIZED_INT_QUEUE_SIZE == q->front_);
}


void
queue_print(
    const Queue* const q)
{
    size_t temp = q->front_;

    while (temp != q->rear_)
    {
        printf("%d \n", q->arr_[temp]);
        temp = (temp + 1) % DS_SIZED_INT_QUEUE_SIZE;
    }
}
