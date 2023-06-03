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

void CGC_Vector_Init(CGC_Vector *vector, __uint32_t capacity, size_t element_size);
void CGC_Vector_Free(CGC_Vector *vector);

int CGC_Vector_PushBack(CGC_Vector *vector, void *element);
int CGC_Vector_PopBack(CGC_Vector *vector, void *buffer);
int CGC_Vector_Insert(CGC_Vector *vector, void *element, __uint32_t index);
int CGC_Vector_Replace(CGC_Vector *vector, void *new_element, __uint32_t index);
int CGC_Vector_Remove(CGC_Vector *vector, void *buffer, __uint32_t index);
void CGC_Vector_Clear(CGC_Vector *vector);

int CGC_Vector_PeekBack(CGC_Vector *vector, void *buffer);
int CGC_Vector_PeekAt(CGC_Vector *vector, void *buffer, __uint32_t index);

void *CGC_Vector_ElementAt(CGC_Vector *vector, __uint32_t index);

int CGC_Vector_Contains(CGC_Vector *vector, void *element);
int CGC_Vector_IndexOf(CGC_Vector *vector, void *element);

void CGC_Vector_Quicksort(CGC_Vector *vector, int (*compare)(const void *element1, const void *element2));

int CGC_Vector_IsEmpty(CGC_Vector *vector);
int CGC_Vector_IsFull(CGC_Vector *vector);
__uint32_t CGC_Vector_Count(CGC_Vector *vector);
__uint32_t CGC_Vector_Capacity(CGC_Vector *vector);

#endif