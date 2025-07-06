/**
 ********************************************************************************
 * @file generic-LL-queue.c
 * @author Daniel Luchian
 * @date 25-07-2025
 * @brief Implementation for a linked list approach to a generic queue
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
#include "generic-ll-queue.h"

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
gl_queue_init( // Function to init a linked list queue of a generic type
    GL_Queue* const q,    // Ptr to generic linked list queue to init
    size_t element_size)  // Size of each element in bytes  
{
    // Set default vals
    q->head_ = q->tail_ = NULL;
    q->element_size_ = element_size;
    q->num_elements_ = 0;
}

//-----------------------------------------------------------------------
bool 
gl_queue_enqueue(
    GL_Queue* const q,
    const unsigned char* const data_src,
    size_t len)
{
    // If len of the data is not the same as the queue element size, return false
    if (q->element_size_ != len)
    {
        return false;
    }

    // Create a node and put the data in
    GenList_Node* newNode = (GenList_Node*)malloc(sizeof(GenList_Node) + q->element_size_);
    if (newNode == NULL)
    {
        return false;
    }
    memcpy(newNode->data_, data_src, len);
    newNode->next_ = NULL;

    // Put the node in the queue, update queue and return
    if (gl_queue_empty(q))
    {
        q->tail_ = q->head_ = newNode;
    }
    else
    {
        q->tail_->next_ = newNode;
        q->tail_ = newNode;
    }
    q->num_elements_++;

    return true;
}

//-----------------------------------------------------------------------
bool 
gl_queue_dequeue(
    GL_Queue* const q, 
    unsigned char* const return_val_dst,
    size_t len)
{
    // If return buffer is not at least of element size return or queue is empty false, otherwise continue
    if ( (len < q->element_size_) || (gl_queue_empty(q)) )
    {
        return false;
    }

    // Get the node being de-alloc
    memcpy(return_val_dst, q->head_->data_, q->element_size_);

    // De-alloc data and update queue
    if (q->head_ == q->tail_)
    {
        free(q->head_);
        q->head_ = q->tail_ = NULL;
    }
    else 
    {
        GenList_Node* temp = q->head_->next_;
        free(q->head_);
        q->head_ = temp;
    }
    q->num_elements_--;

    return true;
}

//-----------------------------------------------------------------------
bool // True if top found 
gl_queue_top( // Function that returns top of the queue
    const GL_Queue* const q, // Ptr to a queue
    unsigned char* const return_val_dst, // Ptr to dst buffer for top
    size_t len) // Size of dst buffer
{
    // If return buffer is not at least of element size return or queue is empty false, otherwise continue
    if (len < q->element_size_ || (gl_queue_empty(q)))
    {
        return false;
    }

    // Copy over top node
    memcpy(return_val_dst, q->head_->data_, q->element_size_);
    return true;
}

//-----------------------------------------------------------------------
bool  // True if queue empty
gl_queue_empty( // Returns if queue is empty
    const GL_Queue* const q) // Ptr to a queue
{
    return (q->num_elements_ == 0);
}

//-----------------------------------------------------------------------
size_t // Size of the queue
gl_queue_size( // Function to get size of the queue
    const GL_Queue* const q) // Ptr to a generic LL queue
{
    return q->num_elements_;
}

//-----------------------------------------------------------------------
void 
gl_queue_deinit( // Function that de-allocs a queue
    GL_Queue* q) // Ptr to a queue
{
    GenList_Node* iterator = q->head_;

    // De-alloc nodes
    while (iterator)
    {
        GenList_Node* temp = iterator->next_;
        free(iterator);
        iterator = temp;
    }

    // Reset queue info
    q->head_ = q->tail_ = NULL;
    q->num_elements_ = 0;
}