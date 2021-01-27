#include <stdio.h>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    int a = 10;
    int b = 20;
    int c = add(a, b);
    printf("a = %d, b = %d, c = %d", a, b, c);
    return 0;
}