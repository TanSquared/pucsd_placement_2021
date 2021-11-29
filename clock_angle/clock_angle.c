#include <stdio.h>
#include <stdlib.h>

double mod(double x)
{
    if (x > 0)
        return x;
    return 0 - x;
}

double minangle(double x)
{
    double y = 360.00 - x;
    if (x > y)
        return y;
    return x;
}

int main(int argc, char **argv)
{
    if (argc < 3 || argc > 4)
        return 0;
    int hour = atoi(argv[1]);
    int min = atoi(argv[2]);
    int sec;
    if (argc == 3)
    {
        double x = (double)hour + (double)min / 60;
        if (min == 0)
            min = 60;
        //This looks confusing, but isn't that much.
        //First I find the difference in positions of hour and min hand
        //Then find their mod and then the minimum angle
        double angle = minangle(mod(((double)min / 5 - x) * 30));
        printf("%.2f\n", angle);
    }
    if (argc == 4)
    {
        //I am assuming the minute hand does not move between seconds passing
        sec = atoi(argv[3]);
        if (min == 0)
            min = 60;
        int angle = abs(min - sec) * 6;
        angle = (int)minangle((double)angle);
        printf("%d\n", angle);
    }
    return 0;
}