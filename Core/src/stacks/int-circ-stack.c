/**
 ********************************************************************************
 * @file sized-int-stack.c
 * @author Daniel Luchian
 * @date 01-07-2025
 * @brief Source file for fixed sized integer stack in c
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "int-circ-stack.h"
#include <stdio.h>

/************************************
 * EXTERN VARIABLES
 ************************************/

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/

/************************************
 * PRIVATE TYPEDEFS
 ************************************/

/************************************
 * STATIC VARIABLES
 ************************************/

/************************************
 * GLOBAL VARIABLES
 ************************************/

/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/

/************************************
 * STATIC FUNCTIONS
 ************************************/

/************************************
 * GLOBAL FUNCTIONS
 ************************************/
//-----------------------------------------------------------------------
void
ic_stack_init(          // Function to init a fixed size int stack
    IC_Stack* const s)  // Pointer to stack to init
{
    s->top_ = 0;
}

//-----------------------------------------------------------------------
bool                    // True if pushed successfully, false otherwise
ic_stack_push(          // Function to push to stack 
    IC_Stack* const s,  // Ptr to a stack
    const int val)      // Value to push
{
    // If stack is full return false, otherwise push value
    if (ic_stack_full(s))
    {
        return false;
    }
    s->arr_[(s->top_)++] = val;
    return true;
}

//-----------------------------------------------------------------------
bool           // True if popped successfully, false otherwise
ic_stack_pop(  // Function to pop from stack
    IC_Stack* const s,     // Ptr to a stack
    int* const return_val) // Ptr to buffer for popped val
{
    // If stack is empty return false, otherwise pop
    if (ic_stack_empty(s))
    {
        return false;
    }
    *return_val = s->arr_[--(s->top_)];
    return true;
}

//-----------------------------------------------------------------------
bool          // True if top returned successfully, false otherwise
ic_stack_top( // Function to return top val of stack
    const IC_Stack* const s, // Ptr to a stack
    int* const return_val)   // Ptr to buffer for top val
{
    // If stack not empty return the top of the stack
    if (ic_stack_empty(s))
    {
        return false;
    }
    *return_val = s->arr_[s->top_ - 1];
    return true;
}

//-----------------------------------------------------------------------
bool             // True if stack empty, false otherwise
ic_stack_empty(  // Function to check if stack empty
    const IC_Stack* const s) // Ptr to a stack
{
    return (s->top_ == 0);
}

//-----------------------------------------------------------------------
bool            // True if stack full, false otherwise
ic_stack_full(  // Function to check if stack full
    const IC_Stack* const s) // Ptr to a stack
{
    return (s->top_ == DS_SIZED_INT_STACK_SIZE);
}

//-----------------------------------------------------------------------
void
ic_stack_print( // Function to print stack elements
    const IC_Stack* const s) // Ptr to a stack
{
    for (size_t i = s->top_; i > 0; i--)
    {
        printf("%d\n", s->arr_[i - 1]);
    }
}
