#include "list.h"

static void CGC_Shift_Elements_Left(CGC_List *list, __uint32_t index)
{
    void *element = list->start + (index * list->element_size);

    for(__uint32_t i = index; i < (list->capacity - 1); i++)
    {
        void *next_element = element + list->element_size;

        memcpy(element, next_element, list->element_size);

        element += list->element_size;
    }
}

void CGC_List_Init(CGC_List *list, __uint32_t capacity, size_t element_size)
{
    list->capacity = capacity;
    list->count = 0;

    list->element_size = element_size;
    list->start = malloc(list->capacity * list->element_size);
    list->next = list->start;

    fprintf(stdout, "list initialized, capacity=%d\n", list->capacity);
}

void CGC_List_Free(CGC_List *list)
{
    list->capacity = 0;
    list->count = 0;

    free(list->start);

    fprintf(stdout, "list freed\n");
}

int CGC_List_Add(CGC_List *list, void *element)
{
    if(list->count == list->capacity)
    {
        fprintf(stderr, "cannot add to list - list full\n");
        return 0;
    }

    memcpy(list->next, element, list->element_size);
    list->count++;

    list->next += list->element_size;

    fprintf(stdout, "added to list\n");
    return 1;
}

/*
    TODO:
    This should actually perform a linear search in order to find the first object in list which is equal to the 'element' parameter (in terms of memory content - memcmp())
    The found object should be removed from the list, instead of just popping the last one like from a stack.
*/

int CGC_List_Remove(CGC_List *list, void *element)
{
    if(list->count == 0)
    {
        fprintf(stderr, "cannot remove from list - list empty\n");
        return 0;
    }

    void *ptr = list->start;
    ptr += (list->element_size * (list->count - 1));

    memcpy(element, ptr, list->element_size);
    list->count--;

    list->next -= list->element_size;

    fprintf(stdout, "removed from list\n");
    return 1;
}

/*
    TODO:
    These methods should not copy the removed element to some external buffer, only remove it from the list
*/

int CGC_List_RemoveAt(CGC_List *list, void *element, __uint32_t index)
{
    if(list->count == 0)
    {
        return 0;
    }

    if(index > list->count - 1)
    {
        return 0;
    }

    void *ptr = list->start;
    ptr += (list->element_size * index);

    memcpy(element, ptr, list->element_size);
    list->count--;

    CGC_Shift_Elements_Left(list, index);

    list->next -= list->element_size;

    return 1;
}

// TODO:
int CGC_List_RemoveRange(CGC_List *list, __uint32_t lower, __uint32_t upper)
{

    return 0;
}

int CGC_List_IsEmpty(CGC_List *list)
{
    if(list->count == 0)
    {
        return 1;
    }

    return 0;
}

int CGC_List_IsFull(CGC_List *list)
{
    if(list->count == list->capacity)
    {
        return 1;
    }

    return 0;
}

void CGC_List_Clear(CGC_List *list)
{
    list->count = 0;
    list->next = list->start;
}

__uint32_t CGC_List_Count(CGC_List *list)
{
    return list->count;
}

__uint32_t CGC_List_Capacity(CGC_List *list)
{
    return list->capacity;
}