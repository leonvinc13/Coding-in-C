#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//pronaci sve brojeve u intervalu [a, b] koji su djeljivi s 5 i 7 ali nisu sa 11

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (i % 5 == 0 && i % 7 == 0 && i % 11 != 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}

