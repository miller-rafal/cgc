#include "vector.h"

static void CGC_Vector_Shift_Right(CGC_Vector *vector, __uint32_t index)
{
    for(__uint32_t i = vector->count - 1; i >= index; i--)
    {
        void *this = vector->start + (i * vector->element_size);
        void *next = this + vector->element_size;

        memcpy(next, this, vector->element_size);
    }
}

static void CGC_Vector_Shift_Left(CGC_Vector *vector, __uint32_t index)
{
    for(__uint32_t i = index; i < vector->count - 1; i++)
    {
        void *this = vector->start + (i * vector->element_size);
        void *next = this + vector->element_size;

        memcpy(this, next, vector->element_size);
    }
}

void CGC_Vector_Init(CGC_Vector *vector, __uint32_t capacity, size_t element_size)
{
    vector->capacity = capacity;
    vector->count = 0;

    vector->element_size = element_size;
    vector->start = malloc(vector->capacity * vector->element_size);
    vector->back = vector->start;
}

void CGC_Vector_Free(CGC_Vector *vector)
{
    vector->capacity = 0;
    vector->count = 0;

    vector->element_size = 0;

    free(vector->start);
}

int CGC_Vector_PushBack(CGC_Vector *vector, void *element)
{
    if(vector->count == vector->capacity)
    {
        return 0;
    }

    if(vector->count > 0)
    {
        vector->back += vector->element_size;
    }

    memcpy(vector->back, element, vector->element_size);
    vector->count++;

    return 1;
}

int CGC_Vector_PopBack(CGC_Vector *vector, void *buffer)
{
    if(vector->count == 0)
    {
        return 0;
    }

    memcpy(buffer, vector->back, vector->element_size);
    vector->count--;

    if(vector->count > 0)
    {
        vector->back -= vector->element_size;
    }

    return 1;
}

int CGC_Vector_PeekBack(CGC_Vector *vector, void *buffer)
{
    if(vector->count == 0)
    {
        return 0;
    }

    memcpy(buffer, vector->back, vector->element_size);

    return 1;
}

int CGC_Vector_Insert(CGC_Vector *vector, void *element, __uint32_t index)
{
    if(vector->count == vector->capacity)
    {
        return 0;
    }

    if(index > vector->count - 1)
    {
        return 0;
    }

    CGC_Vector_Shift_Right(vector, index);
    
    void *element_address = vector->start + (index * vector->element_size);
    memcpy(element_address, element, vector->element_size);
    
    vector->count++;

    if(vector->count > 1)
    {
        vector->back += vector->element_size;
    }
    
    return 1;
}

int CGC_Vector_Replace(CGC_Vector *vector, void *new_element, __uint32_t index)
{
    if(vector->count == 0)
    {
        return 0;
    }

    if(index > vector->count - 1)
    {
        return 0;
    }

    void *element_address = vector->start + (index * vector->element_size);
    memcpy(element_address, new_element, vector->element_size);

    return 1;
}

int CGC_Vector_Remove(CGC_Vector *vector, void *buffer, __uint32_t index)
{
    if(vector->count == 0)
    {
        return 0;
    }

    if(index > vector->count - 1)
    {
        return 0;
    }

    void *element_address = vector->start + (index * vector->element_size);
    memcpy(buffer, element_address, vector->element_size);

    CGC_Vector_Shift_Left(vector, index);

    vector->count--;

    if(vector->count > 0)
    {
        vector->back -= vector->element_size;
    }
    
    return 1;
}

int CGC_Vector_PeekAt(CGC_Vector *vector, void *buffer, __uint32_t index)
{
    if(vector->count == 0)
    {
        return 0;
    }

    if(index > vector->count - 1)
    {
        return 0;
    }

    void *element_address = vector->start + (index * vector->element_size);
    memcpy(buffer, element_address, vector->element_size);

    return 1;
}

void *CGC_Vector_ElementAt(CGC_Vector *vector, __uint32_t index)
{
    if(vector->count == 0)
    {
        return NULL;
    }

    if(index > vector->count - 1)
    {
        return NULL;
    }

    return vector->start + (index * vector->element_size);
}

void CGC_Vector_Clear(CGC_Vector *vector)
{
    vector->count = 0;
    vector->back = vector->start;
}

int CGC_Vector_IsEmpty(CGC_Vector *vector)
{
    if(vector->count == 0)
    {
        return 1;
    }

    return 0; 
}

int CGC_Vector_IsFull(CGC_Vector *vector)
{
    if(vector->count == vector->capacity)
    {
        return 1;
    }

    return 0;
}

int CGC_Vector_Contains(CGC_Vector *vector, void *element)
{
    if(vector->count == 0)
    {
        return 0;
    }

    int cmp_result;
    void *compared_element = vector->start;
    for(__uint32_t i = 0; i < vector->count; i++)
    {
        cmp_result = memcmp(compared_element, element, vector->element_size);

        if(cmp_result == 0)
        {
            return 1;
        }

        compared_element += vector->element_size;
    }

    return 0;
}

int CGC_Vector_IndexOf(CGC_Vector *vector, void *element)
{
    if(vector->count == 0)
    {
        return -1;
    }

    int cmp_result;
    void *compared_element = vector->start;
    for(__uint32_t i = 0; i < vector->count; i++)
    {
        cmp_result = memcmp(compared_element, element, vector->element_size);

        if(cmp_result == 0)
        {
            return (int) i;
        }

        compared_element += vector->element_size;
    }

    return -1;
}

__uint32_t CGC_Vector_Count(CGC_Vector *vector)
{
    return vector->count;
}

__uint32_t CGC_Vector_Capacity(CGC_Vector *vector)
{
    return vector->capacity;
}