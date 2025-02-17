#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

/*
Uselili ste u novu kuću koja na 3 kata, s podrumom. Sve je pregledano i namješteno, jedino još 
nemate hrabrosti pregledati stari i dugo godina nekorišteni podrum. Došli ste na ideju da si pomognete 
na način da napravite sondu koja će sići u podrum i sa nekih specifičnih koordinata odaslati informacije 
o tlocrtu podruma.

Sonda funkcionira na način da stane na neku cjelobrojnu koordinatu (x, y) i pošalje informaciju o 
tome koliko je udaljen zid sjeverno, istočno, južno i zapadno od njene trenutne lokacije 
(cijeli brojevi brojevi s,i,j,z). Vaš zadatak je da na temelju podataka koje je sonda poslala, 
odredite tlocrt podruma.

Podrum se sastoji od nekoliko soba povezanih vratima a odvojenih zidovima debljine 1. 
Sonda nikad neće slati signale kraj vrata (signal neće prolaziti kroz vrata i na taj način dati 
lažnu informaciju). Svaka soba ima oblik pravokutnika

U prvoj liniji ulaznih podataka nalazi se broj N (N < 100) - broj očitanja sonde. U svakom sljedećem 
retku nalaze se brojevi x, y, s, i, j, z (x,y,s,i,j,z < 100), odvojeni razmacima. Neće biti nemogućih 
ulaznih podataka.

Test case #1
Primjer ulaza:
2
2 2 0 4 2 0
8 3 1 1 1 0

Primjer izlaza:
##########
#.....#..#
#.....#..#
#.....#..#
##########


Test case #2
Primjer ulaza:
9
2 2 0 0 0 0
2 4 0 0 0 0
2 6 0 0 0 0
4 2 0 3 0 0
4 4 0 3 0 0
4 6 0 3 0 0
7 2 0 0 0 3
6 4 0 1 0 2
5 6 0 2 0 1

Primjer izlaza:
########
#.#....#
########
#.#....#
########
#.#....#
########
*/

int main() {
    char podrum[MAX][MAX];
    int N, x, y, s, i, j, z;
    for (int k = 0; k < MAX; k++) {
        for (int l = 0; l < MAX; l++) {
            podrum[k][l] = '#';
        }
    }
    int A = 0;
    int B = 0;
    scanf("%d", &N);
    for (int k = 0; k < N; k++) {
        scanf("%d %d %d %d %d %d", &x, &y, &s, &i, &j, &z);
        if (A < x + i) A = x + i + 1;
        if (B < y + j) B = y + j + 1;
        for (int l = x - z - 1; l < x + i; l++) {
            for (int m = y - s - 1; m < y + j; m++) {
                podrum[l][m] = '.';
            }
        }
    }
    for (int k = 0; k < B; k++) {
        for (int l = 0; l < A; l++) {
            printf("%c", podrum[l][k]);
        }
        printf("\n");
    }
    return 0;
}
