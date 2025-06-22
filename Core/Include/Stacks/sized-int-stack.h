

#pragma once

#include <stdbool.h>
#include <stdlib.h>

#define DS_SIZED_INT_STACK_SIZE 10

typedef struct
{
    size_t top_;
    int arr_[DS_SIZED_INT_STACK_SIZE];
} Stack;

void stack_init(Stack* const s);
bool stack_push(Stack* const s, const int val);
bool stack_pop(Stack* const s, int* const return_val);
bool stack_top(const Stack* const s, int* const return_val);
bool stack_empty(const Stack* const s);
bool stack_full(const Stack* const s);
void stack_print(const Stack* const s);