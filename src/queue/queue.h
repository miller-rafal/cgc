#ifndef CGC_QUEUE_H
#define CGC_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CGC_Queue
{
    void *tail;
    void *head;
    __uint32_t count;
    __uint32_t capacity;
    size_t element_size;
} CGC_Queue;

void CGC_Queue_Init(CGC_Queue *queue, __uint32_t capacity, size_t element_size);
void CGC_Queue_Free(CGC_Queue *queue);

int CGC_Queue_Enqueue(CGC_Queue *queue, const void *element);
int CGC_Queue_Dequeue(CGC_Queue *queue, void *buffer);
void CGC_Queue_Clear(CGC_Queue *queue);

int CGC_Queue_Peek(CGC_Queue *queue, void *buffer);
int CGC_Queue_PeekAt(CGC_Queue *queue, void *buffer, __uint32_t index);

void *CGC_Queue_ElementAt(CGC_Queue *queue, __uint32_t index);

int CGC_Queue_Contains(CGC_Queue *queue, void *element);
int CGC_Queue_IndexOf(CGC_Queue *queue, void *element);

int CGC_Queue_IsEmpty(CGC_Queue *queue);
int CGC_Queue_IsFull(CGC_Queue *queue);
__uint32_t CGC_Queue_Count(CGC_Queue *queue);
__uint32_t CGC_Queue_Capacity(CGC_Queue *queue);

#endif
