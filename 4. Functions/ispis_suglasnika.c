#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
Napiši program u programskom jeziku C koji omogućuje korisniku da unese dva znaka x i y 
(pri čemu je x < y) te niz znakova. 
Program treba:
Filtrirati suglasnike između znakova x i y (uključujući x i y) i spremiti ih u drugi niz.
Izračunati ukupan broj takvih suglasnika i ispisati ga na ekran.
Ispisati filtrirane suglasnike tako da se svaki drugi suglasnik ispisuje u novom redu.

Test case #1
Ulaz: 
b g
10
a c d e f g b h i j

Izlaz:
Ukupno malih suglasnika: 3
d f 
g 
*/

#define MAX 100

int brsuglasnici(char x, char y, int n, char niz[MAX]) {
    int br = 0;
    for (int i = 0; i < n; i++) {
        if (niz[i] >= x && niz[i] <= y) {
            if (niz[i] != 'a' && niz[i] != 'e' && niz[i] != 'i' && niz[i] != 'o' && niz[i] != 'u' &&
                niz[i] != 'A' && niz[i] != 'E' && niz[i] != 'I' && niz[i] != 'O' && niz[i] != 'U') {
                br++;
            }
        }
    }
    return br;
}

void suglasnici(char x, char y, int n, char niz[MAX], char niz2[MAX]) {
    int br = 0;
    for (int i = 0; i < n; i++) {
        if (niz[i] >= x && niz[i] <= y) {
            if (niz[i] != 'a' && niz[i] != 'e' && niz[i] != 'i' && niz[i] != 'o' && niz[i] != 'u' &&
                niz[i] != 'A' && niz[i] != 'E' && niz[i] != 'I' && niz[i] != 'O' && niz[i] != 'U') {
                niz2[br++] = niz[i];
            }
        }
    }
    niz2[br] = '\0'; // Osiguravamo da niz2 bude ispravno završeno
}

int main() {
    char x, y;
    int n;
    char niz[MAX], niz2[MAX];

    do {
        printf("Unesite dva znaka (x i y) gdje x < y: ");
        scanf(" %c %c", &x, &y);
        if (x >= y) {
            printf("Neispravan unos! x mora biti manje od y.\n");
        }
    } while (x >= y);

    printf("Unesite broj znakova: ");
    scanf("%d", &n);
    getchar(); // Čišćenje bafera

    printf("Unesite niz od %d znakova:\n", n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &niz[i]);
    }

    int brojSuglasnika = brsuglasnici(x, y, n, niz);
    suglasnici(x, y, n, niz, niz2);

    printf("Ukupno malih suglasnika: %d", brojSuglasnika);
    for (int i = 0; i < brojSuglasnika; i++) {
        if (i % 2 == 0) printf("\n");
        printf("%c ", niz2[i]);
    }

    return 0;
}
