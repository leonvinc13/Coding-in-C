#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Napišite program koji iz datoteke Gradovi.txt učitava podatke o gradovima. 
Korisnik unosi ime države, a program u datoteku rezultat.txt ispisuje ukupni broj stanovnika te države, kao i broj stanovnika svakog grada te države. 
Ako nema gradova u toj državi, ispisuje se poruka "Nema rezultata".

Test case #1
Ulaz: Hrvatska

Izlaz:
Hrvatska ima ukupno: 1204791 stanovnika.
Zagreb ima 790017 stanovnika.
Split ima 178102 stanovnika.
Rijeka ima 128624 stanovnika.
Osijek ima 108048 stanovnika.
*/

typedef struct {
    char drzava[20 + 1];
    char grad[20 + 1];
    long broj_stanovnika;
    float povrsina;
    int glavni;
}Grad;

int main()
{
    char drzava[20 + 1];
    long stanovnika = 0;
    Grad grad[50];
    int n = 0;
    int dobrih = 0;
    FILE* fin = fopen("Gradovi.txt", "r");
    FILE* fout = fopen("rezultat.txt", "w");
    while (fscanf(fin, "%s %s %ld %f %d", grad[n].drzava, grad[n].grad, &grad[n].broj_stanovnika, &grad[n].povrsina, &grad[n].glavni) == 5) {
        n++;
    }
    scanf("%s", drzava);
    for (int i = 0; i < n; i++) {
        if (strcmp(grad[i].drzava, drzava) == 0) {
            //fprintf(fout, "%s ima %ld stanovnika.", grad[i].grad, grad[i].broj_stanovnika);
            stanovnika += grad[i].broj_stanovnika;
            dobrih++;
        }
    }
    if (dobrih == 0) {
        fprintf(fout, "Nema rezultata.");
    }
    fprintf(fout, "%s ima ukupno: %ld stanovnika.\n", drzava, stanovnika);
    for (int i = 0; i < n; i++) {
        if (strcmp(grad[i].drzava, drzava) == 0) {
            fprintf(fout, "%s ima %ld stanovnika.\n", grad[i].grad, grad[i].broj_stanovnika);
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

