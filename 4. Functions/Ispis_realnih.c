#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
/*
Upisati pocetnu i krajnju granicu, zatim unesti broj N, te niz od N brojeva.
Prebrojiti koliko brojeva unesenih u nizu je između početne i krajnje granice, te ispisati rezultat.

TEST CASE #1
Ulaz:
30.0
12.0
12.0
30.0
5
4.0 15.1 30.0 2.5 17.6
Izlaz:
Neispravan unos granica!
U polju postoji 3 brojeva koji
zadovoljavaju uvjet.

TEST CASE #2
Ulaz:
12.0
30.0
150
5
4.0 15.1 30.0 2.5 17.6
Izlaz:
Broj N je neispravno zadan!
U polju postoji 3 brojeva koji
zadovoljavaju uvjet.

TEST CASE #3
Ulaz:
12.5
30.4
4
2.3 3.4 15.5 22.4
Izlaz:
U polju postoji 2 brojeva koji
zadovoljavaju uvjet.
*/
#define MAX 200

int provjera(float a, float b, int n, float niz[MAX]) {
    int br = 0;
    for (int i = 0; i < n; i++) {
        if (niz[i] >= a && niz[i] <= b) {
            br++;
        }
    }
    return br;
}

int main()
{
    int n;
    float a, b, niz[MAX];
    do {
        scanf("%f", &a);
        scanf("%f", &b);
        if (a > b) {
            printf("Neispravan unos granica!");
        }
    } while (a > b);
    do {
        scanf("%d", &n);
        if (n > 100) {
            printf("Broj N je neispravno zadan!");
        }
    } while (n > 100);
    for (int i = 0; i < n; i++) {
        scanf("%f", &niz[i]);
    }
    printf("U polju postoji %d brojeva koji zadovoljavaju uvjet.", provjera(a, b, n, niz));
}

