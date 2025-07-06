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
#include "common.h"

/************************************
 * MACROS AND DEFINES
 ************************************/
#define DS_SIZED_INT_STACK_SIZE 10

/************************************
 * TYPEDEFS
 ************************************/
/* Structure for an integer fixed size stack */
typedef struct IC_Stack
{
    size_t top_; // Index of top of stack
    int arr_[DS_SIZED_INT_STACK_SIZE]; // Array holding stack data
} IC_Stack;

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
/* Stack Functions */
void ic_stack_init(IC_Stack* const s);
bool ic_stack_push(IC_Stack* const s, const int val);
bool ic_stack_pop(IC_Stack* const s, int* const return_val);
bool ic_stack_top(const IC_Stack* const s, int* const return_val);
bool ic_stack_empty(const IC_Stack* const s);
bool ic_stack_full(const IC_Stack* const s);
void ic_stack_print(const IC_Stack* const s);
