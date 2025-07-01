/**
 ********************************************************************************
 * @file sized-int-stack.h
 * @author Daniel Luchian
 * @date 01-07-2025
 * @brief Header file for a fixed size integer stack implementation
 ********************************************************************************
 */

#pragma once
/************************************
 * INCLUDES
 ************************************/
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

/************************************
 * MACROS AND DEFINES
 ************************************/
#define DS_SIZED_INT_STACK_SIZE 10

/************************************
 * TYPEDEFS
 ************************************/
/* Structure for an integer fixed size stack */
typedef struct
{
    size_t top_; // Index of top of stack
    int arr_[DS_SIZED_INT_STACK_SIZE]; // Array holding stack data
} SI_Stack;

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
/* Stack Functions */
void si_stack_init(SI_Stack* const s);
bool si_stack_push(SI_Stack* const s, const int val);
bool si_stack_pop(SI_Stack* const s, int* const return_val);
bool si_stack_top(const SI_Stack* const s, int* const return_val);
bool si_stack_empty(const SI_Stack* const s);
bool si_stack_full(const SI_Stack* const s);
void si_stack_print(const SI_Stack* const s);