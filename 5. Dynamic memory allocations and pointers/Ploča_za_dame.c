#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
Napišite program koji generira pomalo netipičnu ploču za igru dame (šahovska ploča).
Ploča je netipična po tome što korisnik sam može zatražiti koliko veliku ploču želi. 
Figure od svakog igrača zauzimaju uvijek dva reda odozgo (crne figure) i odozdo (bijele figure) 
na način da se figure pozicioniraju samo na crna polja na ploči.

Prvo gornje lijevo mjesto na ploči je bijelo, pa slijedi crno, pa bijelo. 
Drugi red započinje crnim poljem, pa slijedi bijelo itd.

Oznake na ploči prilikom ispisa su: C - crne figure, B - bijele figure, 
O (slovo O kao Ogulin) - bijelo polje, X - crno polje

Za detalje pogledati test caseove.
Napomene prilikom izrade programa:
Memorija za pohranu ploče rezervira se dinamički ovisno o broju željenih redaka i stupaca.
Popunjavanje polja izvršava se u posebnoj funkciji naziva upisi.
Ispis polja vrši se u posebnoj funkciji naziva ispisi.

Test case #1
Ulaz: 5 10

Izlaz:
OCOCOCOCOC
COCOCOCOCO
OXOXOXOXOX
BOBOBOBOBO
OBOBOBOBOB

*/
void upisi(char** mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < 2) {
                if (i % 2 == 0) {
                    if (j % 2 == 0) {
                        mat[i][j] = 'O';
                    }
                    else {
                        mat[i][j] = 'C';
                    }
                }
                else {
                    if (j % 2 == 0) {
                        mat[i][j] = 'C';
                    }
                    else {
                        mat[i][j] = 'O';
                    }
                }
            }
            else if (i > n - 3) {
                if (i % 2 == 0) {
                    if (j % 2 == 0) {
                        mat[i][j] = 'O';
                    }
                    else {
                        mat[i][j] = 'B';
                    }
                }
                else {
                    if (j % 2 == 0) {
                        mat[i][j] = 'B';
                    }
                    else {
                        mat[i][j] = 'O';
                    }
                }
            }
            else if (i % 2 == 0) {
                if (j % 2 == 0) {
                    mat[i][j] = 'O';
                }
                else {
                    mat[i][j] = 'X';
                }
            }
            else {
                if (j % 2 == 0) {
                    mat[i][j] = 'X';
                }
                else {
                    mat[i][j] = 'O';
                }
            }
        }
    }
}

void ispisi(char** mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, m;
    char** mat;
    scanf("%d %d", &n, &m);
    mat = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        mat[i] = (char*)malloc(m * sizeof(char));
    }
    upisi(mat, n, m);
    ispisi(mat, n, m);
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
    return 0;
}


