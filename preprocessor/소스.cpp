#include <stdio.h>

#define MUL1(x,y) x*y
#define MUL2(x,y) (x)*(y)

int mul(int x, int y);

int main()
{
    int a, b;

    a = 10;
    b = 11;

    printf("매크로 함수1 : %d * %d = %d\n", a + 1, b + 1, MUL1(a + 1, b + 1));
    printf("매크로 함수2 : %d * %d = %d\n", a + 1, b + 1, MUL2(a + 1, b + 1));
    printf("일반 함수 : %d * %d = %d\n", a + 1, b + 1, mul(a + 1, b + 1));

    return 0;
}

int mul(int x, int y)
{
    return x * y;
}