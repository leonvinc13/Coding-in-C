#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*Potrebno je uèitati prirodni broj N i broj K, te u iduæoj liniji N cijelih brojeva.
Kao rješenje potrebno je ispisati niz:
Bez izbaèenih najveæih K brojeva
Bez izbaèenih najmanjih K brojeva*/

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int niz[100], maxK[100], minK[100];
    for (int i = 0; i < N; i++) {
        scanf("%d", &niz[i]);
    }
    // Pronaði najveæih K brojeva
    for (int i = 0; i < K; i++) {
        maxK[i] = -1001; // Postavljamo na najmanju moguæu vrednost
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (niz[i] > maxK[j]) {
                // Pomeri sve manje brojeve naniže
                for (int k = K - 1; k > j; k--) {
                    maxK[k] = maxK[k - 1];
                }
                maxK[j] = niz[i];
                break;
            }
        }
    }
    // Pronaði najmanjih K brojeva
    for (int i = 0; i < K; i++) {
        minK[i] = 1001; // Postavljamo na najveæu moguæu vrednost
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (niz[i] < minK[j]) {
                // Pomeri sve veæe brojeve naniže
                for (int k = K - 1; k > j; k--) {
                    minK[k] = minK[k - 1];
                }
                minK[j] = niz[i];
                break;
            }
        }
    }
    // Ispis bez najveæih K brojeva
    for (int i = 0; i < N; i++) {
        int izbacen = 0;
        for (int j = 0; j < K; j++) {
            if (niz[i] == maxK[j]) {
                izbacen = 1;
                maxK[j] = 1001; // Spreèavanje višestrukog izbacivanja istog broja
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
                minK[j] = -1001; // Spreèavanje višestrukog izbacivanja istog broja
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