#include <stdio.h>
#include <omp.h>
#define N 100
int main(int argc, char const *argv[])
{
    int a[N];
    int i;
    for (i = 0; i < N; i++) 
    {
        a[i] = i*i + 55 * i + 4;
    }
    int sum = 0;
    for (i = 0; i < N; i++) 
    {
        sum = sum + a[i];
    }
    printf("Tong tuan tu la %d\n", sum);
    int id, Thread = 100;
    do {
        // Error: Index skipping when Thread is odd
        if (Thread % 2 == 1) 
        {
            a[Thread - 2] = a[Thread - 2] + a[Thread - 1];
            Thread = Thread / 2;
        }
        else
        Thread = Thread / 2;
        omp_set_num_threads(Thread);
        #pragma omp parallel private(id) 
        {
            id = omp_get_thread_num();
            a[id] = a[id] + a[id+Thread];
        }
    } while(Thread > 1);
    printf("Tong la %d\n", a[0]);
    return 0;
}
