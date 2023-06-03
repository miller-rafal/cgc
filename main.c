#include "src/cgc.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct vector_item
{
    int number;
    char description[16];
} vector_item;

void print_vector(CGC_Vector *vector)
{
    fprintf(stdout, "vector capacity: %d\n", CGC_Vector_Capacity(vector));
    fprintf(stdout, "vector count: %d\n", CGC_Vector_Count(vector));

    vector_item *vector_item = malloc(sizeof(vector_item));

    for(__uint32_t i = 0; i < vector->count; i++)
    {
        CGC_Vector_PeekAt(vector, vector_item, i);
        fprintf(stdout, "%d - %s\n", vector_item->number, vector_item->description);
    }

    free(vector_item);
}

void fill_vector(CGC_Vector *vector, int number_of_items)
{
    vector_item *item = malloc(sizeof(vector_item));
    for(int i = 0; i < number_of_items; i++)
    {
        item->number = i + 1;
        sprintf(item->description, "item %d", item->number);

        CGC_Vector_PushBack(vector, item);
    }
    free(item);
}

void search_item(CGC_Vector *vector, int item_number)
{
    vector_item *searched_item = malloc(sizeof(vector_item));
    searched_item->number = item_number;
    sprintf(searched_item->description, "item %d", searched_item->number);

    int contains = CGC_Vector_Contains(vector, searched_item);
    if(contains)
    {
        fprintf(stdout, "item found by CGC_Vector_Contains()\n");
    }
    else
    {
        fprintf(stdout, "item not found by CGC_Vector_Contains()\n");
    }

    int index_of = CGC_Vector_IndexOf(vector, searched_item);
    if(index_of > -1)
    {
        fprintf(stdout, "CGC_Vector_IndexOf() returned %d\n", index_of);
    }
    else
    {
        fprintf(stdout, "item not found by CGC_Vector_IndexOf()\n");
    }

    free(searched_item);
}

int compare(const void *vector1, const void *vector2)
{
    vector_item *ptr1 = (vector_item*) vector1;
    vector_item *ptr2 = (vector_item*) vector2;

    if(ptr1->number < ptr2->number)
    {
        return -1;
    }
    else if(ptr1->number > ptr2->number)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int capacity = 15;

    CGC_Vector *vector = malloc(sizeof(CGC_Vector));
    CGC_Vector_Init(vector, capacity, sizeof(vector_item));

    printf("filling vector\n");
    fill_vector(vector, capacity);

    print_vector(vector);

    //search_item(vector, 5);

    printf("replacing item\n");
    vector_item *new_item = malloc(sizeof(vector_item));
    new_item->number = -1;
    sprintf(new_item->description, "replaced item %d", new_item->number);
    CGC_Vector_Replace(vector, new_item, 9);
    free(new_item);

    print_vector(vector);

    printf("removing item\n");
    vector_item *removed_item = malloc(sizeof(vector_item));
    CGC_Vector_Remove(vector, removed_item, 9);
    printf("removed item: '%d - %s'\n", removed_item->number, removed_item->description);
    free(removed_item);

    print_vector(vector);

    for(int i = 0; i < 5; i++)
    {
        vector_item *popped_item = malloc(sizeof(vector_item));

        int pop_result = CGC_Vector_PopBack(vector, popped_item);
        if(pop_result)
        {
            printf("popped item: %d - %s\n", popped_item->number, popped_item->description);
        }

        free(popped_item);
    }

    print_vector(vector);

    printf("inserting item\n");
    vector_item *inserted_item = malloc(sizeof(vector_item));
    inserted_item->number = -5;
    sprintf(inserted_item->description, "inserted item %d", inserted_item->number);
    CGC_Vector_Insert(vector, inserted_item, 5);
    inserted_item->number = -6;
    sprintf(inserted_item->description, "inserted item %d", inserted_item->number);
    CGC_Vector_Insert(vector, inserted_item, 5);
    free(inserted_item);

    print_vector(vector);

    /*
    
        TODO - test CGC_Vector_Peek()
    
    */

    vector_item *referenced_item = CGC_Vector_ElementAt(vector, 1);
    if(referenced_item != NULL)
    {
        printf("referenced item: '%d - %s'\n", referenced_item->number, referenced_item->description);
    }

    print_vector(vector);

    printf("sorting vector\n");

    CGC_Vector_Quicksort(vector, &compare);

    print_vector(vector);

    CGC_Vector_Free(vector);
    return 0;
}