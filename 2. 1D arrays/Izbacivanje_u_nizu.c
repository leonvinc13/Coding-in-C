#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*Potrebno je u�itati prirodni broj N i broj K, te u idu�oj liniji N cijelih brojeva.
Kao rje�enje potrebno je ispisati niz:
Bez izba�enih najve�ih K brojeva
Bez izba�enih najmanjih K brojeva*/

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int niz[100], maxK[100], minK[100];
    for (int i = 0; i < N; i++) {
        scanf("%d", &niz[i]);
    }
    // Prona�i najve�ih K brojeva
    for (int i = 0; i < K; i++) {
        maxK[i] = -1001; // Postavljamo na najmanju mogu�u vrednost
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (niz[i] > maxK[j]) {
                // Pomeri sve manje brojeve nani�e
                for (int k = K - 1; k > j; k--) {
                    maxK[k] = maxK[k - 1];
                }
                maxK[j] = niz[i];
                break;
            }
        }
    }
    // Prona�i najmanjih K brojeva
    for (int i = 0; i < K; i++) {
        minK[i] = 1001; // Postavljamo na najve�u mogu�u vrednost
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (niz[i] < minK[j]) {
                // Pomeri sve ve�e brojeve nani�e
                for (int k = K - 1; k > j; k--) {
                    minK[k] = minK[k - 1];
                }
                minK[j] = niz[i];
                break;
            }
        }
    }
    // Ispis bez najve�ih K brojeva
    for (int i = 0; i < N; i++) {
        int izbacen = 0;
        for (int j = 0; j < K; j++) {
            if (niz[i] == maxK[j]) {
                izbacen = 1;
                maxK[j] = 1001; // Spre�avanje vi�estrukog izbacivanja istog broja
                break;
            }
        }
        if (!izbacen) {
            printf("%d ", niz[i]);
        }
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        int izbacen = 0;
        for (int j = 0; j < K; j++) {
            if (niz[i] == minK[j]) {
                izbacen = 1;
                minK[j] = -1001; // Spre�avanje vi�estrukog izbacivanja istog broja
                break;
            }
        }
        if (!izbacen) {
            printf("%d ", niz[i]);
        }
    }
    printf("\n");
    return 0;
}