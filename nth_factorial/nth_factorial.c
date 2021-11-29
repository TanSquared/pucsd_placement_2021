#include <stdio.h>
#include <stdlib.h>

long unsigned int *position;
long unsigned int *value;
long unsigned int size = 2, top = 0;

long unsigned int fibonacci(long unsigned int num)
{
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;
    for (long unsigned int i = 0; i < top; i++)
    {
        if (position[i] == num)
        {
            //memoisation
            return value[i];
        }
    }
    long unsigned int ans = fibonacci(num - 1) + fibonacci(num - 2);
    position[top] = num;
    value[top] = ans;
    top++;
    if (top == size)
    {
        position = (long unsigned int *)realloc(position, size * 2 * sizeof(long unsigned int));
        value = (long unsigned int *)realloc(value, 2 * size * sizeof(long unsigned int));
        size = size * 2;
    }
    return ans;
}

long unsigned int main(long unsigned int argc, char **argv)
{
    position = (long unsigned int *)calloc(2, sizeof(long unsigned int));
    value = (long unsigned int *)calloc(2, sizeof(long unsigned int));
    if (argc != 2)
        return 0;
    long unsigned int n = atoi(argv[1]);
    printf("%lu\n", fibonacci(n));

    //This next bit is for even fibonaacci. I noticed that only at the indexes multiples of 3 we have even numbers. Thus, doing the bonus bit isn't much of an issue

    printf("Even fibonacci: %lu\n", fibonacci(n * 3));
    //As I am printing the even fibonacci value for each number
    //There might be errors due to the value of ans becoming too high
    //and going out of range. In order to minimize the chances
    //I took long unsigned int instead of int, but error still
    //remains, for example the even fibonacci of 61 and 85 look fishy
    return 0;
}