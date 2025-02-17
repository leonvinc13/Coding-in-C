#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
Srednjoškolski uèitelj Mirko zamolio vas je da mu napravite program pomoæu kojeg æe moæi napraviti 
statistiku zakljuèenih ocjena iz svog predmeta (Biologije) za više razlièitih razreda. 
Mirko bi htio za svaki razred unositi koliko je bilo uèenika s odreðenom ocjenom i da mu program 
u konaènici izraèuna prosjeènu ocjenu svih razreda,  te ispiše koliko je ukupno uèenika prošlo 
s kojom ocjenom.
U test caseovima vidjeti primjer izvoðenja programa.

Test case #1
Primjer ulaza: 
3
1 0 10 15 3
0 2 5 15 7
3 2 15 7 5

Primjer izlaza: 
Za 3 razred/razreda

bilo je:
4 nedovoljan, 4 dovoljan, 30 dobar, 37 vrlo dobar i 15 odlican

prosjecna ocjena je:
vrlo dobar
*/

int main() {
    int n; // Broj razreda
    int niz[100][5]; // Broj ocena za svaki razred (5 ocena: 1, 2, 3, 4, 5)
    int ukupno[5] = { 0 }; // Ukupni brojevi po ocenama za sve razrede
    int ukupno_ucenika = 0;
    int ukupno_ocjena = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &niz[i][j]);
            ukupno[j] += niz[i][j]; // Dodavanje u ukupni broj po ocenama
            ukupno_ucenika += niz[i][j]; // Ukupno uèenika
        }
    }
    for (int i = 0; i < 5; i++) {
        ukupno_ocjena += ukupno[i] * (i + 1); // i+1 je ocena (1, 2, 3, 4, 5)
    }
    float prosjek = (float)ukupno_ocjena / ukupno_ucenika;
    printf("Za %d razred/razreda\n\n", n);
    printf("bilo je:\n");
    printf("%d nedovoljan, %d dovoljan, %d dobar, %d vrlo dobar i %d odlican\n",ukupno[0], ukupno[1], ukupno[2], ukupno[3], ukupno[4]);
    printf("\nprosjecna ocjena je:\n");
    if (prosjek < 1.5) {
        printf("nedovoljan\n");
    }
    else if (prosjek < 2.5) {
        printf("dovoljan\n");
    }
    else if (prosjek < 3.5) {
        printf("dobar\n");
    }
    else if (prosjek < 4.5) {
        printf("vrlo dobar\n");
    }
    else {
        printf("odlican\n");
    }
    return 0;
}
