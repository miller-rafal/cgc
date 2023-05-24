#include "src/cgc.h"

void test_stack()
{
    CGC_Stack intstack;
    CGC_Stack_Init(&intstack, 5, sizeof(int));

    __uint32_t capacity = CGC_Stack_Capacity(&intstack);
    fprintf(stdout, "stack capacity: %d\n", capacity);

    for(int i = 1; i <= 10; i++)
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

    count = CGC_Stack_Count(&intstack);
    fprintf(stdout, "stack count: %d\n", count);

    for(int i = 1; i <= 5; i++)
    {
        int contains = CGC_Stack_Contains(&intstack, &i);

        if(contains)
        {
            fprintf(stdout, "stack contains %d\n", i);
        }
        else
        {
            fprintf(stdout, "stack does not contain %d\n", i);
        }
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

void test_queue()
{
    CGC_Queue queue;
    CGC_Queue_Init(&queue, 5, sizeof(int));

    __uint32_t capacity = CGC_Queue_Capacity(&queue);
    fprintf(stdout, "queue capacity=%d\n", capacity);

    __uint32_t count = CGC_Queue_Count(&queue);
    fprintf(stdout, "queue count=%d\n", count);

    for(int i = 1; i <= 10; i++)
    {
        CGC_Queue_Enqueue(&queue, &i);
    }
    
    count = CGC_Queue_Count(&queue);
    fprintf(stdout, "queue count=%d\n", count);

    int peeked;
    CGC_Queue_Peek(&queue, &peeked);
    fprintf(stdout, "peeked value=%d\n", peeked);

    int number = 7;
    int contains = CGC_Queue_Contains(&queue, &number);
    if(contains)
    {
        fprintf(stdout, "queue contains %d\n", number);
    }
    else
    {
        fprintf(stdout, "queue does not contain %d\n", number);
    }

    count = CGC_Queue_Count(&queue);
    fprintf(stdout, "queue count=%d\n", count);

    for(int i = 0; i < 10; i++)
    {
        int dequeued;
        int res = CGC_Queue_Dequeue(&queue, &dequeued);
        if(res)
        {
            fprintf(stdout, "dequeued=%d\n", dequeued);
        }
    }

    count = CGC_Queue_Count(&queue);
    fprintf(stdout, "queue count=%d\n", count);

    CGC_Queue_Free(&queue);
}

int main()
{
    //test_stack();
    //test_queue();

    return 0;
}