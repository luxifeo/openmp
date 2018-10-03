#include <stdio.h>
int main(int argc, char const *argv[])
{   
    char *str = "Hello" ", " "world";
    int x = 4, y = 5;
    int z = (x *= 2, y);
    printf("z = %d\n", z); 
    return 0;
}
