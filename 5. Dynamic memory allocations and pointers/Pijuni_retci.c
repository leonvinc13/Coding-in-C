#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
Zadatak: Matrica s pijunima

U ovom zadatku radimo s matricom dimenzija n × m, koja predstavlja ploču na kojoj se postavljaju 
pijuni ('P'). Cilj programa je:

Inicijalizirati matricu tako da su sva polja označena točkom (.), osim polja na kojima su postavljeni 
pijuni.
Unijeti koordinate pijuna, pri čemu korisnik unosi k parova koordinata, a na tim mjestima se 
postavljaju pijuni ('P').
Ispisati matricu nakon postavljanja pijuna.
Izračunati broj pijuna po retcima i ispisati taj broj za svaki redak.
Prilagoditi memoriju pomoću calloc i realloc kako bi brojanje bilo dinamički omogućeno.
*/
#define MAX 100

void ispis(char mat[][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}

void brojacRedaka(char mat[][MAX], int n, int m, int* brR) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'P') {
                brR[i]++;
            }
        }
    }
}

int main()
{
    int n, m, k, x, y;
    int r = 0;
    int* brR;
    char mat[MAX][MAX];
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = '.';
        }
    }
    for (int t = 0; t < k; t++) {
        scanf("%d %d", &x, &y);
        mat[x - 1][y - 1] = 'P';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 'P') {
                r++;
            }
        }
    }
    ispis(mat, n, m);
    brR = (int*)calloc(n, sizeof(int));
    brojacRedaka(mat, n, m, brR);
    printf("Broj pijuna po retcima: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", brR[i]);
    }
    brR = (int*)realloc(brR, (r + n) * sizeof(int*));
    return 0;
}


