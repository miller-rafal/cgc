#include "src/cgc.h"

int main()
{
    CgcStack intstack;
    CgcStack_Init(&intstack, 5, sizeof(int));

    __uint32_t capacity = CgcStack_Capacity(&intstack);
    fprintf(stdout, "stack capacity: %d\n", capacity);

    for(int i = 1; i < 11; i++)
    {
        CgcStack_Push(&intstack, &i);
    }

    __uint32_t count = CgcStack_Count(&intstack);
    fprintf(stdout, "1 - stack count: %d\n", count);

    int popped;
    for(int i = 1; i < 11; i++)
    {
        CgcStack_Pop(&intstack, &popped);
    }

    count = CgcStack_Count(&intstack);
    fprintf(stdout, "2 - stack count: %d\n", count);

    for(int i = 1; i < 11; i++)
    {
        CgcStack_Push(&intstack, &i);
    }

    count = CgcStack_Count(&intstack);
    fprintf(stdout, "3 - stack count: %d\n", count);

    for(int i = 1; i < 11; i++)
    {
        CgcStack_Pop(&intstack, &popped);
    }

    count = CgcStack_Count(&intstack);
    fprintf(stdout, "4 - stack count: %d\n", count);

    CgcStack_Free(&intstack);

    return 0;
}