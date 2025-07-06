/**
 ********************************************************************************
 * @file generic-LL-queue.h
 * @author Daniel Luchian
 * @date 05-07-2025
 * @brief Header file for a generic linked list queue
 ********************************************************************************
 */

#pragma once

/************************************
 * INCLUDES
 ************************************/
#include "common.h"
#include "generic-node.h"

/************************************
 * MACROS AND DEFINES
 ************************************/

/************************************
 * TYPEDEFS
 ************************************/
/* Generic Typed Linked List Queue */
typedef struct GL_Queue
{
    GenList_Node* head_;   // Front of the queue (dequeue)
    GenList_Node* tail_;   // Back of the queue (enqueue)
    size_t num_elements_; // Number of elements in the queue
    size_t element_size_; // Size of each element
} GL_Queue;

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
/* Queue Funtions */
void gl_queue_init(GL_Queue* const q, size_t element_size);
bool gl_queue_enqueue(GL_Queue* const q, const unsigned char* const data_src, size_t len);
bool gl_queue_dequeue(GL_Queue* const q, unsigned char* const return_val_dst, size_t len);
bool gl_queue_top(const GL_Queue* const q, unsigned char* const return_val_dst, size_t len);
bool gl_queue_empty(const GL_Queue* const q);
size_t gl_queue_size(const GL_Queue* const q);
void gl_queue_deinit(GL_Queue* q);