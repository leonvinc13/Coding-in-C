#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
U datoteci naziva "knjizara.dat" nalaze se informacije o knjigama zapisane u obliku struktura: 

naziv knjige - string od 30+1 znak,
pisac - string od 30+1 znak,
broj stranica - cijeli broj
cijena - realni broj (float)
kolicina - cijeli broj.

Potrebno je napisati program koji će od korisnika traziti unos imena (ili dijela imena) pisca i unutar funkcije pretraga u novu formatiranu datoteku naziva "moj_pisac.txt" upisati samo one knjige koje odgovaraju pretrazi i to u sljedećem formatu:

Ime_knjige#cijena#broj_stranica

U slučaju da se upiše nepostojeći pisac, potrebno je ispisati poruku "Nije pronadjen zapis.". 

Test case #1
Ulaz:
George R.R. Martin

Izlaz:
Igra prijestolja#179.00#824
Gozba vrana#179.00#781
Oluja maceva#199.00#1108
Ples zmajeva - 1.dio#149.00#596
Ples zmajeva - 2.dio#149.00#584
Sraz kraljeva#179.00#892
*/

typedef struct {
    char naziv[30 + 1];
    char pisac[30 + 1];
    int broj_stranica;
    float cijena;
    int kolicina;
} Knjiga;

void pretraga(int n, char* string, Knjiga* knjiga, FILE* fout) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(knjiga[i].pisac, string) != NULL) {
            fprintf(fout, "%s#%.2f#%d\n", knjiga[i].naziv, knjiga[i].cijena, knjiga[i].broj_stranica);
            m++;
        }
    }
    if (m == 0) {
        fprintf(fout, "Nije pronadjen zapis.");
    }
}

int main()
{
    char string[30 + 1];
    Knjiga knjiga[100];
    int n;
    FILE* fbin = fopen("knjizara.dat", "rb");
    FILE* fout = fopen("moj_pisac.txt", "w");
    fseek(fbin, 0, SEEK_END);
    long file_size = ftell(fbin);
    rewind(fbin);
    n = file_size / sizeof(Knjiga);
    fread(knjiga, sizeof(Knjiga), n, fbin);
    fclose(fbin);
    scanf("%[^\n]", string);
    pretraga(n, string, knjiga, fout);
    fclose(fout);
    return 0;
}


