#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
Napišite program koji generira pomalo netipičnu šahovsku ploču.
Ploča je netipična po tome što korisnik sam može zatražiti koliko veliku ploču želi, a umjesto 
tradicionalnih šahovskih figura (kralj, kraljica, lovac, itd.) na njoj se nalaze sve identične figure 
s time što jedan igrač ima figure crne boje, a drugi bijele. Figure od svakog igrača zauzimaju uvijek 
puna dva reda odozgo (crne figure) i odozdo (bijele figure).
Prvo gornje lijevo mjesto na ploči je bijelo, pa slijedi crno, pa bijelo. Drugi red započinje crnim 
poljem, pa slijedi bijelo itd.

Oznake na ploči prilikom ispisa su: C - crne figure, B - bijele figure, O (slovo O kao Ogulin) - 
bijelo polje, X - crno polje

Za detalje pogledati test caseove.
Napomene prilikom izrade programa:
Memorija za pohranu ploče rezervira se dinamički ovisno o broju željenih redaka i stupaca.
Popunjavanje polja izvršava se u posebnoj funkciji naziva upisi.
Ispis polja vrši se u posebnoj funkciji naziva ispisi.

Test case #1
Ulaz: 5 5

Izlaz:
CCCCC
CCCCC
OXOXO
BBBBB
BBBBB

*/

#define MAX 100

void upisi(char** matrica, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < 2) {
                matrica[i][j] = 'C';
            }
            else if (i > n - 3) {
                matrica[i][j] = 'B';
            }
            else if (i % 2 == 0) {
                if (j % 2 == 0) {
                    matrica[i][j] = 'O';
                }
                else {
                    matrica[i][j] = 'X';
                }
            }
            else {
                if (j % 2 == 0) {
                    matrica[i][j] = 'X';
                }
                else {
                    matrica[i][j] = 'O';
                }
            }
        }
    }
}
void ispis(char** matrica, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", matrica[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char** mat = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++)
        mat[i] = (char*)malloc(m * sizeof(char));
    upisi(mat, n, m);
    ispis(mat, n, m);
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
    return 0;
}

