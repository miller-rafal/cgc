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

void CGC_Queue_Init(CGC_Queue*, __uint32_t, size_t);
void CGC_Queue_Free(CGC_Queue*);

int CGC_Queue_Enqueue(CGC_Queue*, void*);
int CGC_Queue_Peek(CGC_Queue*, void*);
int CGC_Queue_Dequeue(CGC_Queue*, void*);
void CGC_Queue_Clear(CGC_Queue*);

int CGC_Queue_IsEmpty(CGC_Queue*);
int CGC_Queue_IsFull(CGC_Queue*);
int CGC_Queue_Contains(CGC_Queue*, void*);

__uint32_t CGC_Queue_Count(CGC_Queue*);
__uint32_t CGC_Queue_Capacity(CGC_Queue*);

#endif
