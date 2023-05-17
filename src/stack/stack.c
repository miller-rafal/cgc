#include "stack.h"

void CgcStack_Init(CgcStack *stack, __uint32_t capacity, size_t element_size)
{
    stack->capacity = capacity;
    stack->count = 0;

    stack->element_size = element_size;
    stack->start = malloc(stack->capacity * stack->element_size);
    stack->next = stack->start;
    stack->top = stack->start;
}

void CgcStack_Free(CgcStack *stack)
{
    stack->capacity = 0;
    stack->count = 0;

    free(stack->start);
}

int CgcStack_Push(CgcStack* stack, const void *element)
{
    if(stack->count == stack->capacity)
    {
        return 0;
    }

    memcpy(stack->next, element, stack->element_size);
    stack->count++;

    stack->top = stack->next;
    stack->next += stack->element_size;

    return 1;
}

int CgcStack_Pop(CgcStack *stack, void *element)
{
    if(stack->count == 0)
    {
        return 0;
    }

    memcpy(element, stack->top, stack->element_size);
    stack->count--;

    if(stack->count == 0)
    {
        stack->top = stack->start;
        stack->next = stack->start;
    }
    else
    {
        stack->top -= stack->element_size;
        stack->next -= stack->element_size;
    }

    return 1;
}

int CgcStack_IsEmpty(CgcStack *stack)
{
    if(stack->count == 0)
    {
        return 1;
    }

    return 0;
}

int CgcStack_IsFull(CgcStack *stack)
{
    if(stack->count == stack->capacity)
    {
        return 1;
    }

    return 0;
}

__uint32_t CgcStack_Count(CgcStack *stack)
{
    return stack->count;
}

__uint32_t CgcStack_Capacity(CgcStack *stack)
{
    return stack->capacity;
}