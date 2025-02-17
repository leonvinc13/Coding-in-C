#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
Program koji radi bubble sort brojeva
*/
int main()
{
    int niz[100];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &niz[i]);
    }
    int bilaZamjena;
    do {
        bilaZamjena = 0;
        for (int i = 0; i < n - 1; i++) {
            if (niz[i] > niz[i + 1]) {
                int temp = niz[i];
                niz[i] = niz[i + 1];
                niz[i + 1] = temp;
                bilaZamjena = 1;
            }
        }
    } while (bilaZamjena);
    for (int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }
    return 0;
}

