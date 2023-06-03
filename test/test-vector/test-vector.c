#include "../../src/cgc.h"

#include <assert.h>

typedef struct vector_item
{
    int number;
    char description[16];
} VectorItem;

void test_init(CGC_Vector *unit_under_test)
{
    fprintf(stdout, "running 'test_init()' test function...\n");

    // arrange
    __uint32_t expected_count = 0, expected_capacity = 10;
    size_t expected_element_size = sizeof(VectorItem);

    void *start, *back;
    __uint32_t count, capacity;
    size_t element_size;

    // act
    CGC_Vector_Init(unit_under_test, expected_capacity, expected_element_size);

    start = unit_under_test->start;
    back = unit_under_test->back;
    element_size = unit_under_test->element_size;

    count = CGC_Vector_Count(unit_under_test);
    capacity = CGC_Vector_Capacity(unit_under_test);

    // assert
    assert(start == back);
    assert(element_size == expected_element_size);
    assert(count == expected_count);
    assert(capacity == expected_capacity);

    // finalize
    CGC_Vector_Free(unit_under_test);
    fprintf(stdout, "'test_init()' test function passed!\n");
}

void test_free(CGC_Vector *unit_under_test)
{
    fprintf(stdout, "running 'test_free()' test function...\n");

    // arrange
    __uint32_t initial_count = 5, initial_capacity = 10;
    size_t initial_element_size = sizeof(VectorItem);

    __uint32_t expected_count = 0, expected_capacity = 0;
    size_t expected_element_size = 0;

    __uint32_t count, capacity;
    size_t element_size;

    CGC_Vector_Init(unit_under_test, initial_capacity, initial_element_size);

    for(__uint32_t i = 0; i < initial_count; i++)
    {
        VectorItem *item = malloc(sizeof(VectorItem));
        item->number = i;
        sprintf(item->description, "item %d", i);

        CGC_Vector_PushBack(unit_under_test, item);

        free(item); 
    }

    // act
    CGC_Vector_Free(unit_under_test);

    element_size = unit_under_test->element_size;

    count = CGC_Vector_Count(unit_under_test);
    capacity = CGC_Vector_Capacity(unit_under_test);

    // assert
    assert(element_size == expected_element_size);
    assert(count == expected_count);
    assert(capacity == expected_capacity);

    // finalize
    fprintf(stdout, "'test_free()' test function passed!\n");
}

// TODO:
void test_push_back(CGC_Vector *unit_under_test)
{
    //fprintf(stdout, "running '' test function...\n");

    //fprintf(stdout, "'' test function passed!\n");
}

// TODO:
void test_pop_back(CGC_Vector *unit_under_test)
{
    //fprintf(stdout, "running '' test function...\n");

    //fprintf(stdout, "'' test function passed!\n");
}

// TODO:
void test_peek_back(CGC_Vector *unit_under_test)
{
    //fprintf(stdout, "running '' test function...\n");

    //fprintf(stdout, "'' test function passed!\n");
}

// TODO:
void test_insert(CGC_Vector *unit_under_test)
{
    //fprintf(stdout, "running '' test function...\n");

    //fprintf(stdout, "'' test function passed!\n");
}

// TODO:
void test_replace(CGC_Vector *unit_under_test)
{
    //fprintf(stdout, "running 'test_replace()' test function...\n");

    // arrange

    // act

    // assert

    // finalize
    //fprintf(stdout, "'test_replace()' test function passed!\n");
}

// TODO:
void test_remove(CGC_Vector *unit_under_test)
{
    //fprintf(stdout, "running 'test_remove()' test function...\n");

    // arrange

    // act

    // assert

    // finalize
    //fprintf(stdout, "'test_remove()' test function passed!\n");
}

// TODO:
void test_peek(CGC_Vector *unit_under_test)
{
    //fprintf(stdout, "running '' test function...\n");

    //fprintf(stdout, "'' test function passed!\n");
}

// TODO:
void test_clear(CGC_Vector *unit_under_test)
{
    //fprintf(stdout, "running '' test function...\n");

    //fprintf(stdout, "'' test function passed!\n");
}

// TODO:
void test_is_empty(CGC_Vector *unit_under_test)
{
    //fprintf(stdout, "running '' test function...\n");

    //fprintf(stdout, "'' test function passed!\n");
}

// TODO:
void test_is_full(CGC_Vector *unit_under_test)
{
    //fprintf(stdout, "running '' test function...\n");

    //fprintf(stdout, "'' test function passed!\n");
}

// TODO:
void test_contains(CGC_Vector *unit_under_test)
{
    //fprintf(stdout, "running '' test function...\n");

    //fprintf(stdout, "'' test function passed!\n");
}

// TODO:
void test_index_of(CGC_Vector *unit_under_test)
{
    //fprintf(stdout, "running '' test function...\n");

    //fprintf(stdout, "'' test function passed!\n");
}

int main()
{
    fprintf(stdout, "********************* test-vector ********************\n");
    
    CGC_Vector *unit_under_test;
    unit_under_test = malloc(sizeof(CGC_Vector));

    test_init(unit_under_test);
    test_free(unit_under_test);
    test_push_back(unit_under_test);
    test_pop_back(unit_under_test);
    test_peek_back(unit_under_test);
    test_insert(unit_under_test);
    test_replace(unit_under_test);
    test_remove(unit_under_test);
    test_peek(unit_under_test);
    test_clear(unit_under_test);
    test_is_empty(unit_under_test);
    test_is_full(unit_under_test);
    test_contains(unit_under_test);
    test_index_of(unit_under_test);

    free(unit_under_test);

    fprintf(stdout, "*********** test-vector: all tests passed! ***********\n");
    return(0);
}