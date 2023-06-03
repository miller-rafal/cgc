#ifndef CGC_VECTOR_H
#define CGC_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CGC_Vector
{
    void *start;
    void *back;
    __uint32_t count;
    __uint32_t capacity;
    size_t element_size;
} CGC_Vector;

void CGC_Vector_Init(CGC_Vector*, __uint32_t, size_t);
void CGC_Vector_Free(CGC_Vector*);

int CGC_Vector_PushBack(CGC_Vector*, void*);
int CGC_Vector_PopBack(CGC_Vector*, void*);
int CGC_Vector_PeekBack(CGC_Vector*, void*);
int CGC_Vector_PeekAt(CGC_Vector*, void*, __uint32_t);

int CGC_Vector_Insert(CGC_Vector*, void*, __uint32_t);
int CGC_Vector_Replace(CGC_Vector*, void*, __uint32_t);
int CGC_Vector_Remove(CGC_Vector*, void*, __uint32_t);
void CGC_Vector_Clear(CGC_Vector*);

void CGC_Vector_Quicksort(CGC_Vector*, int (*)(const void *, const void *));

void *CGC_Vector_ElementAt(CGC_Vector*, __uint32_t);

int CGC_Vector_IsEmpty(CGC_Vector*);
int CGC_Vector_IsFull(CGC_Vector*);
int CGC_Vector_Contains(CGC_Vector*, void*);
int CGC_Vector_IndexOf(CGC_Vector*, void*);

__uint32_t CGC_Vector_Count(CGC_Vector*);
__uint32_t CGC_Vector_Capacity(CGC_Vector*);

#endif