#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

/*
Napišite program koji iz binarne datoteke filmovi.dat učitava podatke o filmovima, a iz tekstualne datoteke glumci.txt učitava podatke o glumcima. 
Nakon što korisnik unese naziv filma, program treba ispisati imena svih glumaca koji glume u tom filmu.
*/

typedef struct {
    int sifra;
    char naziv[54 + 1];
    char zanr[24 + 1];
} Film;

typedef struct {
    char ime[30 + 1];
    int sifra;
    char uloga[8 + 1];
}Glumac;

//A. Michael Hall#900#glavna

int main()
{
    Film film[1000];
    Glumac glumac[2000];
    char imeFilma[60 + 1];
    int m = 0;
    FILE* fbin = fopen("filmovi.dat", "rb");
    FILE* fin = fopen("glumci.txt", "r");
    scanf("%[^\n]", imeFilma);
    fseek(fbin, 0, SEEK_END);
    int size = ftell(fbin);
    int n = size / sizeof(Film);
    rewind(fbin);
    fread(film, sizeof(Film), n, fbin);
    while (fscanf(fin, " %[^#]#%d#%s", glumac[m].ime, &glumac[m].sifra, glumac[m].uloga) == 3) {
        m++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (strcmp(film[i].naziv, imeFilma) == 0) {
                if (film[i].sifra == glumac[j].sifra) {
                    printf("%s\n", glumac[j].ime);
                }
            }
        }
    }
    return 0;
}


