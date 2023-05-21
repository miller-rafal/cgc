#include "stack.h"

void CGC_Stack_Init(CGC_Stack *stack, __uint32_t capacity, size_t element_size)
{
    stack->capacity = capacity;
    stack->count = 0;

    stack->element_size = element_size;
    stack->start = malloc(stack->capacity * stack->element_size);
    stack->next = stack->start;
    stack->top = stack->start;
}

void CGC_Stack_Free(CGC_Stack *stack)
{
    stack->capacity = 0;
    stack->count = 0;

    free(stack->start);
}

int CGC_Stack_Push(CGC_Stack* stack, const void *element)
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

int CGC_Stack_Peek(CGC_Stack *stack, void *element)
{
    if(stack->count == 0)
    {
        return 0;
    }

    memcpy(element, stack->top, stack->element_size);

    return 1;
}

int CGC_Stack_Pop(CGC_Stack *stack, void *element)
{
    if(stack->count == 0)
    {
        return 0;
    }

    memcpy(element, stack->top, stack->element_size);
    stack->count--;

    stack->top -= stack->element_size;
    
    if(stack->count == 0)
    {
        stack->next = stack->start;
    }
    else
    {
        stack->next -= stack->element_size;
    }

    return 1;
}

void CGC_Stack_Clear(CGC_Stack *stack)
{
    stack->count = 0;
    stack->next = stack->start;
    stack->top = stack->start;
}

int CGC_Stack_IsEmpty(CGC_Stack *stack)
{
    if(stack->count == 0)
    {
        return 1;
    }

    return 0;
}

int CGC_Stack_IsFull(CGC_Stack *stack)
{
    if(stack->count == stack->capacity)
    {
        return 1;
    }

    return 0;
}

int CGC_Stack_Contains(CGC_Stack *stack, void *element)
{
    int cmp_res;
    void *ptr = stack->start;

    for(int i = 0; i < stack->count; i++)
    {
        cmp_res = memcmp(ptr, element, stack->element_size);

        if(cmp_res == 0)
        {
            return 1;
        }

        ptr += stack->element_size;
    }

    return 0;
}

__uint32_t CGC_Stack_Count(CGC_Stack *stack)
{
    return stack->count;
}

__uint32_t CGC_Stack_Capacity(CGC_Stack *stack)
{
    return stack->capacity;
}