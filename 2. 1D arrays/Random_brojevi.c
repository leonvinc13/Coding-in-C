#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
// 1.
// Zelim brojeve izmedju <-7, 14]
// -6, -5, ... 0, 1, 2, .... 13, 14

// Random brojeve u tom intervalu
#define MAX1 21
#define MAX2 10
int main()
{
    int niz[MAX1];
    for (int i = 0; i < MAX1; i++) {
        niz[i] = -6 + i;
        printf("%d ", niz[i]);
    }
    printf("\n");
    int niz2[MAX2] = {0};
    srand(time(NULL));
    for (int i = 0; i < MAX2; i++) {
        int r = rand() % 21 - 6;
        niz[i] = r;
        //printf("%d ", niz[i]);
    }

    for (int i = 0; i < MAX2; i++) {
        printf("%d ", niz[i]);
    }
    return 0;
}

