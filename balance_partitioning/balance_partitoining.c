#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;

    //I have heavily used the formula for arithmetic progression

    int n = atoi(argv[1]);
    int *arr = (int *)malloc(n * sizeof(int));
    int a, b, t, ans1, ans2, top = 0;
    for (int i = 0; i < n; i++)
    {
        a = 4;
        t = i - 1;
        ans1 = t * a + t * (t - 1);
        b = 2 * i + 4;
        t = n - i;
        ans2 = t * b + t * (t - 1);
        t = abs(ans1 - ans2);
        arr[top] = t;
        if (i != 0)
        {
            if (arr[top] > arr[top - 1])
            {
                //because the difference once becomes minimum then starts rising again
                //We don't want to calculate for the remaining is
                printf("%d\n", i - 1);
                return 0;
            }
        }
        top++;
        //arr = (int *)realloc(arr, top * sizeof(int));
    }
    return 0;
}