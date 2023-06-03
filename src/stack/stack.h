#ifndef CGC_STACK_H
#define CGC_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CGC_Stack
{
    void *start;
    void *top;
    __uint32_t capacity;
    __uint32_t count;
    size_t element_size;
} CGC_Stack;

void CGC_Stack_Init(CGC_Stack*, __uint32_t, size_t);
void CGC_Stack_Free(CGC_Stack*);

int CGC_Stack_Push(CGC_Stack*, const void*);
int CGC_Stack_Peek(CGC_Stack*, void*);
int CGC_Stack_PeekAt(CGC_Stack*, void*, __uint32_t);
int CGC_Stack_Pop(CGC_Stack*, void*);
void CGC_Stack_Clear(CGC_Stack*);

void *CGC_Stack_ElementAt(CGC_Stack*, __uint32_t);

int CGC_Stack_IsEmpty(CGC_Stack*);
int CGC_Stack_IsFull(CGC_Stack*);
int CGC_Stack_Contains(CGC_Stack*, void*);
int CGC_Stack_IndexOf(CGC_Stack*, void*);

__uint32_t CGC_Stack_Count(CGC_Stack*);
__uint32_t CGC_Stack_Capacity(CGC_Stack*);

#endif