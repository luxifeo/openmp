#include <stdio.h>
#include <omp.h>
#define N 100
int main(void)
{
    int a[N];
    int i;
    for (i = 0; i < N; i++) 
    {
        a[i] = i*i + 55 * i + 4;
    }
    int max = 0;
    for (i = 0; i < N; i++) 
    {
        if(a[i] > max) max = a[i];
    }
    printf("Max tuan tu la %d\n", max);
    int id, Thread = N;
    do {
        if(Thread % 2 == 1) {
            a[0] = a[0] > a[Thread - 1]?a[0]:a[Thread - 1];
        }
        Thread = Thread / 2;
        printf("New loop with %d Thread\n", Thread);
        omp_set_num_threads(Thread);
        #pragma omp parallel private(id) 
        {
            id = omp_get_thread_num();
            printf("So sanh a[%d] = %d voi a[%d] = %d\n",id,a[id], id+Thread, a[id+Thread]);
            a[id] = a[id] > a[id+Thread]?a[id]:a[id+Thread];
        }
    } while(Thread > 1);
    printf("Max la %d\n", a[0]);
    return 0;
}
