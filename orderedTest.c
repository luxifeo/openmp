#include <stdio.h>
#include <omp.h>
#include <string.h>
void writeToFile(char filename[], int a);
int main(int argc, char const *argv[])
{
    char filename[11] = "ordered.txt";
    int i;
#pragma omp parallel for num_threads(4) ordered
    for (i = 0; i < 16; i++)
    {
#pragma omp ordered
        writeToFile(filename, omp_get_thread_num());
    }
    return 0;
}
void writeToFile(char filename[], int a)
{
    FILE *result = fopen(filename, "a");
    fprintf(result, "Hello from %d\n", a);
    fclose(result);
}
