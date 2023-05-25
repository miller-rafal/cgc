#include "../../src/stack/stack.h"

#include <stdio.h>
#include <assert.h>

void stack_initializes(CGC_Stack *unit_under_test)
{
    fprintf(stdout, "running stack_initializes() test function\n");

    // arrange
    __uint32_t capacity = 5;
    size_t size = sizeof(int);

    // act
    CGC_Stack_Init(unit_under_test, capacity, size);

    // assert
    assert(unit_under_test->capacity == capacity);
    assert(unit_under_test->count == 0);
    assert(unit_under_test->element_size == size);
    assert(unit_under_test->top == unit_under_test->start);

    // finalize
    CGC_Stack_Free(unit_under_test);
    fprintf(stdout, "stack_initializes() test function passed\n");
}

void when_stack_is_full_push_fails(CGC_Stack *unit_under_test, int test_vector[], int test_vector_size)
{
    fprintf(stdout, "running full_stack_fails_to_push() test function()\n");

    // arrange
    __uint32_t capacity = 5;
    size_t element_size = sizeof(int);

    CGC_Stack_Init(unit_under_test, capacity, element_size);

    // act
    int push_result = 0;
    for(int i = 0; i < test_vector_size; i++)
    {
        int result = CGC_Stack_Push(unit_under_test, &test_vector[i]);

        if(result != push_result)
        {
            push_result = result;
        }
    }

    // assert
    assert(push_result == 0);
    assert(unit_under_test->count == capacity);

    // finalize
    CGC_Stack_Free(unit_under_test);
    fprintf(stdout, "full_stack_fails_to_push() test function passed\n");
}

void when_stack_empty_pop_fails(CGC_Stack *unit_under_test)
{
    fprintf(stdout, "running when_stack_empty_pop_fails() test function()\n");

    // arrange
    __uint32_t capacity = 5;
    size_t element_size = sizeof(int);

    CGC_Stack_Init(unit_under_test, capacity, element_size);

    // act
    int pop_result = 0;
    int buffer = -1;
    for(int i = 0; i < 5; i++)
    {
        int result = CGC_Stack_Pop(unit_under_test, &buffer);

        if(result != pop_result)
        {
            pop_result = result;
        }
    }

    // assert
    assert(pop_result == 0);
    assert(buffer == -1);

    // finalize
    CGC_Stack_Free(unit_under_test);
    fprintf(stdout, "when_stack_empty_pop_fails() test function passed\n");
}

int main()
{
    int test_vector_size = 10;
    int test_vector[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    CGC_Stack unit_under_test;
    
    stack_initializes(&unit_under_test);
    when_stack_is_full_push_fails(&unit_under_test, test_vector, test_vector_size);
    when_stack_empty_pop_fails(&unit_under_test);

    return 0;
}