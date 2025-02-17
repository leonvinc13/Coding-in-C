#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
Zbrojiti brojeve u svim redovima zasebno te ispisati sume svih redova i najvece brojeve u svakom redu
*/
#define MAX 100
int main()
{
    int n, m;
    int mat[MAX][MAX];
    int sumRed[MAX] = { 0 }, sumStup[MAX] = { 0 };
    int maxR[MAX] = { 0 }, maxS[MAX] = { 0 };
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sumRed[i] += mat[i][j];
            if (mat[i][j] > maxR[i]) {
                maxR[i] = mat[i][j];
            }
        }
        printf("Suma %d retka: %d\n", i, sumRed[i]);
        printf("Max retka je %d\n", maxR[i]);
    }
    printf("\n");
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            sumStup[j] += mat[i][j];
            if (mat[i][j] > maxS[j]) {
                maxS[j] = mat[i][j];
            }
        }
        printf("Suma %d stupca: %d\n", j, sumStup[j]);
        printf("Max stupca je: %d\n", maxS[j]);
    }
    return 0;
}


