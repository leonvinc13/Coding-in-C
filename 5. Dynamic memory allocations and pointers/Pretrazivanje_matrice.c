#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Zadatak: Pronalaženje stupca s najmanjim zbrojem
Napišite program koji pronalazi stupac u matrici čiji elementi imaju najmanji zbroj.

Ulaz: Dva broja n i m (2 ≤ n, m ≤ 100) koji predstavljaju broj redaka i stupaca matrice.
n × m cijelih brojeva koji čine elemente matrice.
Izlaz: Redni broj stupca s najmanjim zbrojem elemenata.
Vrijednost tog zbroja.

Test caase #1
Ulaz:
3 4  
4 2 3 1  
8 6 7 5  
9 1 2 4  
Izlaz:

Izlaz:
Zbroj elemenata je najmanji u 3. stupcu i iznosi 12.
*/

int najmanji(int n, int m, int** matrica) {
    int najI;
    int min = 1000;
    int sumS[100] = { 0 };
    for (int j = 0; j < m; j++) {
        //sumR[i] = 0 ;
        for (int i = 0; i < n; i++) {
            sumS[j] += matrica[i][j];
        }
        if (sumS[j] < min) {
            min = sumS[j];
            najI = j;
        }
    }
    return najI;
}

int main()
{
    int n, m;
    int** matrica;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n >= 2 && n <= 100 && m >= 2 && m <= 100) {
            break;
        }
        printf("Krivi unos");
    }
    matrica = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        matrica[i] = (int*)malloc(sizeof(int) * m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrica[i][j]);
        }
    }
    int min = najmanji(n, m, matrica);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrica[i][min];
    }
    printf("Zbroj elemenata je najmnaji u %d. stupcu i iznosi %d.", min + 1, sum);
    return 0;
}


