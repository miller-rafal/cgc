#ifndef CGC_LIST_H
#define CGC_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CGC_List
{
    void *start;
    void *next;
    __uint32_t capacity;
    __uint32_t count;
    size_t element_size;
} CGC_List;

void CGC_List_Init(CGC_List*, __uint32_t, size_t);
void CGC_List_Free(CGC_List*);

int CGC_List_Add(CGC_List*, void*);
int CGC_List_Remove(CGC_List*, void*);
int CGC_List_RemoveAt(CGC_List*, void*, __uint32_t);
int CGC_List_IsEmpty(CGC_List*);
int CGC_List_IsFull(CGC_List*);
void CGC_List_Clear(CGC_List*);

__uint32_t CGC_List_Count(CGC_List*);
__uint32_t CGC_List_Capacity(CGC_List*);

#endif