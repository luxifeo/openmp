/*********************************************************************
 * FILE matmul.c
 * DESCRIPTION:
 * OpenMP - Matrix Multiply
 * Threads share row iteration
 * AUTHOR: Bui Duc Hoa
 * Last revised : 03/10/18
 ********************************************************************/

#include <stdio.h>
#include <omp.h>
#define NRA 40 // A's number of rows
#define NCA 20 // A's number of columns which is also B's number of rows
#define NCB 10 // B's number of columns

int main(void)
{
    int a[NRA][NCA], b[NCA][NCB]; //
    double  c[NRA][NCB]; 
    int i, j, k, start, end; // iterator
    int id, nthread;
    float avg; // average loops a thread executes
    for (i = 0; i < NRA; i++)
    {
        for (j = 0; j < NCA; j++)
        {
            a[i][j] = i + j;
        }
    }
    for (i = 0; i < NCA; i++)
    {
        for (j = 0; j < NCB; j++)
        {
            b[i][j] = i * j;
        }
    }
    for (i = 0; i < NRA; i++)
    {
        for (j = 0; j < NCB; j++)
        {
            c[i][j] = 0;
        }
    }
#pragma omp parallel shared(a, b, c, nthread) private(id, start, end, i, j, k) num_threads(6)
    {
        nthread = omp_get_num_threads();
        avg = NRA / (float)nthread;
        id = omp_get_thread_num();
        start = (int)(id * avg);
        end = (int)((id + 1) * avg) - 1;
        printf("Thread %d calculates from row %d to %d\n", id, start, end);
        for (i = start; i <= end; i++)
        {
            for (j = 0; j < NCB; j++)
            {
                for (k = 0; k <= NCA; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
    printf("******************************************************\n");
    printf("Result Matrix:\n");
    for (i = 0; i < NRA; i++)
    {
        for (j = 0; j < NCB; j++)
            printf("%6.f   ", c[i][j]);
        printf("\n");
    }
    printf("******************************************************\n");
    printf("Done.\n");
    return 0;
}