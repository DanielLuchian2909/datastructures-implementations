

#include "sized-int-stack.h"
#include <stdio.h>

void
stack_init(
    Stack* const s)
{
    s->top_ = 0;
}

bool
stack_push(
    Stack* const s,
    const int val)
{
    if (stack_full(s))
    {
        return false;
    }

    s->arr_[(s->top_)++] = val;
    return true;
}


bool
stack_pop(
    Stack* const s,
    int* const return_val)
{
    if (stack_empty(s))
    {
        return false;
    }

    *return_val = s->arr_[--(s->top_)];
    return true;
}


bool
stack_top(
    const Stack* const s,
    int* const return_val)
{
    if (stack_empty(s))
    {
        return true;
    }

    *return_val = s->arr_[s->top_ - 1];
    return true;
}


bool
stack_empty(
    const Stack* const s)
{
    return (s->top_ == 0);
}


bool
stack_full(
    const Stack* const s)
{
    return (s->top_ == DS_SIZED_INT_STACK_SIZE);
}


void
stack_print(
    const Stack* const s)
{
    for (size_t i = s->top_; i > 0; i--)
    {
        printf("%d\n", s->arr_[i - 1]);
    }
}
