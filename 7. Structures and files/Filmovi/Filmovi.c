#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
U datoteci naziva "filmovi.txt" nalaze se informacije o filmovima: naziv filma, redatelj, godina izdanja, ocjena iz baze IMDb, žanr (jedan film može imati definiranu pripadnost u najviše tri žanra, ali i manje). Jedan zapis u datoteci je zapisan kao:
A Clockwork Orange#Stanley Kubrick#1971#8.4#Crime|Drama|Sci-Fi
Napisati program koji će u novu datoteku naziva "lista.txt" upisati samo one filmove čija je IMDb ocjena veća od 5.0. Filmovi u novoj datoteci moraju biti sortirani od najveće prema najmanjoj ocjeni. Proces sortiranja potrebno je realizirati u zasebnoj funkciji naziva sortiraj_po_ocjeni.
Učitane podatke iz datoteke "filmovi.txt" potrebno je pohraniti koristeći strukture i kao takve ih zapisati u novu datoteku "lista.txt".
Podaci se u novu datoteku zapisuju u istom obliku kao što su zapisani u originalnog datoteci.

Test case #1
Ulaz: 
A Clockwork Orange#Stanley Kubrick#1971#8.4#Crime|Drama|Sci-Fi
The Wolf of Wall Street#Martin Scorsese#2013#8.7#Biography|Comedy|Crime
MacGruber#Jorma Taccone#2010#5.4#Action|Comedy

Izlaz:
The Wolf of Wall Street#Martin Scorsese#2013#8.7#Biography|Comedy|Crime
A Clockwork Orange#Stanley Kubrick#1971#8.4#Crime|Drama|Sci-Fi
MacGruber#Jorma Taccone#2010#5.4#Action|Comedy
*/

typedef struct {
    char naziv[40 + 1];
    char redatelj[50 + 1];
    int godina;
    float ocjena;
    char zanr[100 + 1];
} Film;

void sortiraj_po_ocjeni(int m, Film *film5) {
    int bilaZamjena = 0;
    do {
        bilaZamjena = 0;
        for (int i = 0; i < m - 1; i++) {
            if (film5[i].ocjena < film5[i + 1].ocjena) {
                Film t = film5[i];
                film5[i] = film5[i + 1];
                film5[i + 1] = t;
                bilaZamjena = 1;
            }
        }
    } while (bilaZamjena);
}

int main()
{
    FILE* fin = fopen("filmovi.txt", "r");
    FILE* fout = fopen("lista.txt", "w");
    Film film[100];
    Film film5[100];
    int n = 0, m = 0;
    while (fscanf(fin, " %[^#]#%[^#]#%d#%f#%[^\n]\n", film[n].naziv, film[n].redatelj, &film[n].godina, &film[n].ocjena, film[n].zanr) == 5) {
        //getchar();
        if (film[n].ocjena >= 5) {
            film5[m++] = film[n];
        }
        n++;
    }
    sortiraj_po_ocjeni(m, film5);
    for (int i = 0; i < m; i++) {
        fprintf(fout, "%s#%s#%d#%.1f#%s\n", film5[i].naziv, film5[i].redatelj, film5[i].godina, film5[i].ocjena, film5[i].zanr);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
