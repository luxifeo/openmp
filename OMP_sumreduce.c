#include <stdio.h>
#include <omp.h>
int main(int argc, char const *argv[])
{
    int A[100];
    for (int i = 0; i < 100; i++)
        printf("a[%d] = %d \n", i,  A[i]);
    return 0;
}
