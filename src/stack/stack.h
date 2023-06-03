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

void CGC_Stack_Init(CGC_Stack *stack, __uint32_t capacity, size_t element_size);
void CGC_Stack_Free(CGC_Stack *stack);

int CGC_Stack_Push(CGC_Stack *stack, const void *element);
int CGC_Stack_Pop(CGC_Stack *stack, void *buffer);
void CGC_Stack_Clear(CGC_Stack *stack);

int CGC_Stack_Peek(CGC_Stack *stack, void *buffer);
int CGC_Stack_PeekAt(CGC_Stack *stack, void *buffer, __uint32_t index);

void *CGC_Stack_ElementAt(CGC_Stack *stack, __uint32_t index);

int CGC_Stack_Contains(CGC_Stack *stack, void *element);
int CGC_Stack_IndexOf(CGC_Stack *stack, void *element);

int CGC_Stack_IsEmpty(CGC_Stack *stack);
int CGC_Stack_IsFull(CGC_Stack *stack);
__uint32_t CGC_Stack_Count(CGC_Stack *stack);
__uint32_t CGC_Stack_Capacity(CGC_Stack *stack);

#endif