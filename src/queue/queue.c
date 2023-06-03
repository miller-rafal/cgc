#include "queue.h"

static void CGC_Queue_Shift_Right(CGC_Queue *queue)
{
    int index = ((int) queue->count) - 1;

    for(int i = index; i >= 0; i--)
    {
        void *element = queue->tail + (((__uint32_t) i) * queue->element_size);
        void *next_element = element + queue->element_size;

        memcpy(next_element, element, queue->element_size);
    }

    if(index >= 0)
    {
        queue->head += queue->element_size;
    }
}

void CGC_Queue_Init(CGC_Queue *queue, __uint32_t capacity, size_t element_size)
{
    queue->capacity = capacity;
    queue->count = 0;

    queue->element_size = element_size;
    queue->tail = malloc(queue->capacity * queue->element_size);
    queue->head = queue->tail;
}

void CGC_Queue_Free(CGC_Queue *queue)
{
    queue->capacity = 0;
    queue->count = 0;

    free(queue->tail);
}

int CGC_Queue_Enqueue(CGC_Queue *queue, const void *element)
{
    if(queue->count == queue->capacity)
    {
        return 0;
    }

    if(queue->count > 0)
    {
        CGC_Queue_Shift_Right(queue);
    }

    memcpy(queue->tail, element, queue->element_size);
    queue->count++;

    return 1;
}

int CGC_Queue_Dequeue(CGC_Queue *queue, void *buffer)
{
    if(queue->count == 0)
    {
        return 0;
    }

    memcpy(buffer, queue->head, queue->element_size);
    queue->count--;

    if(queue->count > 0)
    {
        queue->head -= queue->element_size;
    }
    
    return 1;
}

void CGC_Queue_Clear(CGC_Queue *queue)
{
    queue->count = 0;
    queue->head = queue->tail;
}

int CGC_Queue_Peek(CGC_Queue *queue, void *buffer)
{
    if(queue->count == 0)
    {
        return 0;
    }

    memcpy(buffer, queue->head, queue->element_size);

    return 1;
}

int CGC_Queue_PeekAt(CGC_Queue *queue, void *buffer, __uint32_t index)
{
    if(queue->count == 0)
    {
        return 0;
    }

    if(index > queue->count - 1)
    {
        return 0;
    }

    void *element_address = queue->tail + (index * queue->element_size);
    memcpy(buffer, element_address, queue->element_size);

    return 1;
}

void *CGC_Queue_ElementAt(CGC_Queue *queue, __uint32_t index)
{
    if(queue->count == 0)
    {
        return NULL;
    }

    if(index > queue->count - 1)
    {
        return NULL;
    }

    return queue->tail + (index * queue->element_size);
}

int CGC_Queue_Contains(CGC_Queue *queue, void *element)
{
    if(queue->count == 0)
    {
        return 0;
    }

    int cmp_res;
    void *compared_element = queue->tail;
    for(__uint32_t i = 0; i < queue->count; i++)
    {
        cmp_res = memcmp(compared_element, element, queue->element_size);

        if(cmp_res == 0)
        {
            return 1;
        }

        compared_element += queue->element_size;
    }

    return 0;
}

int CGC_Queue_IndexOf(CGC_Queue *queue, void *element)
{
    if(queue->count == 0)
    {
        return -1;
    }

    int cmp_res;
    void *compared_element = queue->tail;
    for(__uint32_t i = 0; i < queue->count; i++)
    {
        cmp_res = memcmp(compared_element, element, queue->element_size);

        if(cmp_res == 0)
        {
            return (int) i;
        }

        compared_element += queue->element_size;
    }

    return -1;
}

int CGC_Queue_IsEmpty(CGC_Queue *queue)
{
    if(queue->count == 0)
    {
        return 1;
    }

    return 0;
}

int CGC_Queue_IsFull(CGC_Queue *queue)
{
    if(queue->count == queue->capacity)
    {
        return 1;
    }

    return 0;
}

__uint32_t CGC_Queue_Count(CGC_Queue *queue)
{
    return queue->count;
}

__uint32_t CGC_Queue_Capacity(CGC_Queue *queue)
{
    return queue->capacity;
}