/**
 ********************************************************************************
 * @file sized-int-queue.c
 * @author Daniel Luchian
 * @date 01-07-2025
 * @brief Source file of a fixed size integer queue implementation
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "int-circ-queue.h"

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
ic_queue_init(         // Function to init a fixed size int queue
    IC_Queue* const q) // Ptr to a queue to init
{
    q->front_ = q->rear_ = 0;
}

//-----------------------------------------------------------------------
bool                   // True if enqueued successfully, false otherwise
ic_queue_enqueue(      // Function to enqueue
    IC_Queue* const q, // Ptr to a queue 
    const int val)     // Val to enqueue
{
    // If queue is full return false, otherwise enqueue
    if (ic_queue_full(q))
    {
        return false;
    }

    // Add value to the rear, handle wrap around, and return true
    q->arr_[q->rear_] = val;
    q->rear_ = WRAP_AROUND(q->rear_);
    return true;
}

//-----------------------------------------------------------------------
bool
ic_queue_dequeue(          // Function to dequeue
    IC_Queue* const q,     // Ptr to a queue
    int* const return_val) // Pointer to variable to store dequeued value
{
    // If queue empty return false, otherwise dequeue
    if (ic_queue_empty(q))
    {
        return false;
    }

    // Remove value from front, handle wrap around, and return true
    *return_val = q->arr_[q->front_];
    q->front_ = WRAP_AROUND(q->front_);
    return true;
}

//-----------------------------------------------------------------------
bool           // True if a valid element was returned
ic_queue_top(  // Function to return top element
    const IC_Queue* const q, // Ptr to a queue 
    int* const return_val)   // Ptr to return buffer
{
    // If queue is empty return false, otherwise put value and return true
    if (ic_queue_empty(q))
    {
        return false;
    }
    *return_val = q->arr_[q->front_];
    return true;
}

//-----------------------------------------------------------------------
bool             // True if queue empty, false otherwise
ic_queue_empty(  // Function to return if queue is empty
    const IC_Queue* const q) // Ptr to a queue
{
    return (q->front_ == q->rear_);
}

//-----------------------------------------------------------------------
bool            // True if queue full, false otherwise
ic_queue_full(  // Function to retunr if queue is full
    const IC_Queue* const q) // Ptr to a queue
{
    return (WRAP_AROUND(q->rear_) == q->front_);
}

//-----------------------------------------------------------------------
void
ic_queue_print( // Function to print queue elements
    const IC_Queue* const q) // Ptr to a queue
{
    size_t temp = q->front_;

    while (temp != q->rear_)
    {
        printf("%d \n", q->arr_[temp]);
        temp = (temp + 1) % DS_SIZED_INT_QUEUE_SIZE;
    }
}
