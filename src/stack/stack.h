#ifndef CGC_STACK_H
#define CGC_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CgcStack
{
    void *start;
    void *next;
    void *top;
    __uint32_t capacity;
    __uint32_t count;
    size_t element_size;
} CgcStack;

void CgcStack_Init(CgcStack*, __uint32_t, size_t);
void CgcStack_Free(CgcStack*);

int CgcStack_Push(CgcStack*, const void*);
int CgcStack_Pop(CgcStack*, void*);
int CgcStack_IsEmpty(CgcStack*);
int CgcStack_IsFull(CgcStack*);

__uint32_t CgcStack_Count(CgcStack*);
__uint32_t CgcStack_Capacity(CgcStack*);

#endif