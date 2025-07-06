/**
 ********************************************************************************
 * @file sized-int-queue.h
 * @author Daniel Luchian
 * @date 01-07-2025
 * @brief Header file for a fixed size integer queue implementation
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
#define DS_SIZED_INT_QUEUE_SIZE 8 // Size of queue

/* Macro for handling wrap arounds based on size */
// If size of queue is power of two use mask for wrap around handling
#if ( (DS_SIZED_INT_QUEUE_SIZE != 0) \
    && ( (DS_SIZED_INT_QUEUE_SIZE & (DS_SIZED_INT_QUEUE_SIZE - 1) ) ) == 0 )
    
    #define WRAP_AROUND(x) ( ((x) + 1) & (DS_SIZED_INT_QUEUE_SIZE - 1) )

// Otherwise use modulo 
#else 

    #define WRAP_AROUND(x) ( ((x) + 1) % DS_SIZED_INT_QUEUE_SIZE )

#endif

/************************************
 * TYPEDEFS
 ************************************/
/* Fixed Size Integer Queue */
typedef struct IC_Queue
{
    size_t front_; // Index of front of queue (dequeue)
    size_t rear_;  // Index of back of queue (enqueue)
    int arr_[DS_SIZED_INT_QUEUE_SIZE]; // Array holding data of queue
} IC_Queue;

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
/* Queue Functions */
void ic_queue_init(IC_Queue* const q);
bool ic_queue_enqueue(IC_Queue* const q, const int val);
bool ic_queue_dequeue(IC_Queue* const q, int* const return_val);
bool ic_queue_top(const IC_Queue* const q, int* const return_val);
bool ic_queue_empty(const IC_Queue* const q);
bool ic_queue_full(const IC_Queue* const q);
void ic_queue_print(const IC_Queue* const q);