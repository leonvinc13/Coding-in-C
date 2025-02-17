#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

/*
Test case #1
Primjer ulaza:
5 7
.......
.......
..M....
.......
V.....V

Primjer izlaza:
Najblizi vitez je na loakciji [5,1], 4 koraka do pobjede.


Test case #2
Primjer ulaza:
3 3
VVV
VMV
VVV

Primjer izlaza:
Najblizi vitezi su na 1 koraka do pobjede: [1,2], [2,1], [2,3], [3,2].
*/

#define MAX 100

int main() {
    int n, m, sumM = 0, sumV = 0;
    int macI = -1, macJ = -1;  
    int minRaz = 1000;        
    int najRed[MAX], najStup[MAX]; // Polja za pohranu svih najbližih viteza
    int brojNajblizih = 0;    // Broj najbližih viteza
    char mat[MAX][MAX];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &mat[i][j]);

            if (mat[i][j] == 'M') {
                sumM++;
                macI = i;
                macJ = j;
            }
            if (mat[i][j] == 'V') {
                sumV++;
            }
        }
    }
    if (!sumM) {
        printf("Mac ne postoji. Svi su pobjednici.");
        return 0;
    }

    // Pronalazak najbližih viteza
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'V') {
                int udaljenost = abs(macI - i) + abs(macJ - j);

                if (udaljenost < minRaz) {
                    // Pronaðena manja udaljenost: ažuriraj minimalnu udaljenost
                    minRaz = udaljenost;
                    brojNajblizih = 1;  // Resetiramo broj najbližih
                    najRed[0] = i + 1;  // Spremamo koordinate viteza
                    najStup[0] = j + 1;
                }
                else if (udaljenost == minRaz) {
                    // Ako je udaljenost jednaka minimalnoj, dodajemo viteza
                    najRed[brojNajblizih] = i + 1;
                    najStup[brojNajblizih] = j + 1;
                    brojNajblizih++;
                }
            }
        }
    }

    // Ispis rezultata
    if (brojNajblizih == 1) {
        printf("Najblizi vitez je na lokaciji [%d,%d], %d koraka do pobjede.\n",
            najRed[0], najStup[0], minRaz);
    }
    else {
        printf("Najblizi vitezi su na %d koraka do pobjede: ", minRaz);
        for (int i = 0; i < brojNajblizih; i++) {
            printf("[%d,%d]", najRed[i], najStup[i]);
            if (i < brojNajblizih - 1) {
                printf(", ");
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}
