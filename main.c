#include "src/cgc.h"

void test_stack()
{
    CGC_Stack intstack;
    CGC_Stack_Init(&intstack, 5, sizeof(int));

    __uint32_t capacity = CGC_Stack_Capacity(&intstack);
    fprintf(stdout, "stack capacity: %d\n", capacity);

    for(int i = 1; i <= 5; i++)
    {
        CGC_Stack_Push(&intstack, &i);
    }

    __uint32_t count = CGC_Stack_Count(&intstack);

    fprintf(stdout, "stack count: %d\n", count);

    int popped;
    CGC_Stack_Pop(&intstack, &popped);
    fprintf(stdout, "popped value:%d\n", popped);

    CGC_Stack_Pop(&intstack, &popped);
    fprintf(stdout, "popped value:%d\n", popped);

    count = CGC_Stack_Count(&intstack);
    fprintf(stdout, "stack count: %d\n", count);

    int peeked;
    CGC_Stack_Peek(&intstack, &peeked);
    fprintf(stdout, "peeked value:%d\n", peeked);

    int num = 3;
    int contains2 = CGC_Stack_Contains(&intstack, &num);

    if(contains2)
    {
        fprintf(stdout, "stack contains %d\n", num);
    }
    else
    {
        fprintf(stdout, "stack does not contain %d\n", num);
    }

    count = CGC_Stack_Count(&intstack);
    fprintf(stdout, "stack count: %d\n", count);

    CGC_Stack_Clear(&intstack);

    count = CGC_Stack_Count(&intstack);
    fprintf(stdout, "stack count: %d\n", count);

    for(int i = 1; i <= 3; i++)
    {
        CGC_Stack_Push(&intstack, &i);
    }

    count = CGC_Stack_Count(&intstack);
    fprintf(stdout, "stack count: %d\n", count);

/*
for(int i = 1; i < 11; i++)
    {
        CGC_Stack_Pop(&intstack, &popped);
    }

    count = CGC_Stack_Count(&intstack);
    fprintf(stdout, "2 - stack count: %d\n", count);

    for(int i = 1; i < 11; i++)
    {
        CGC_Stack_Push(&intstack, &i);
    }

    count = CGC_Stack_Count(&intstack);
    fprintf(stdout, "3 - stack count: %d\n", count);

    for(int i = 1; i < 11; i++)
    {
        CGC_Stack_Pop(&intstack, &popped);
    }

    count = CGC_Stack_Count(&intstack);
    fprintf(stdout, "4 - stack count: %d\n", count);
*/
    

    CGC_Stack_Free(&intstack);

}

void test_list()
{
    CGC_List intlist;

    CGC_List_Init(&intlist, 5, sizeof(int));

/*
    int added = 3;
    CGC_List_Add(&intlist, &added);
    CGC_List_Add(&intlist, &added);

    fprintf(stdout, "List count=%d\n", intlist.count);

    for(int i = 1; i <= 10; i++)
    {
        CGC_List_Add(&intlist, &i);
    }

    fprintf(stdout, "List count=%d\n", intlist.count);

    int removed;
    CGC_List_Remove(&intlist, &removed);
    CGC_List_Remove(&intlist, &removed);
    fprintf(stdout, "List count=%d\n", intlist.count);

    for(int i = 0; i < 10; i++)
    {
        CGC_List_Remove(&intlist, &removed);
    }

    fprintf(stdout, "List count=%d\n", intlist.count);

*/
    
    CGC_List_Free(&intlist);
}

int main()
{
    test_stack();
    //test_list();

    return 0;
}