#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i = 80, d = 9, k = 0;
    int start, end;
    float avg = i/(float)d;
    printf("avg = %f\n", avg);
    for (k = 0; k < d; k++) {
        start = (int)(k * avg);
        end = (int)((k+1) * avg) - 1;
        printf("start at %d and end at %d\n", start, end);
    }
    return 0;
}
