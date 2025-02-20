#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Napišite program koji iz datoteke automobili.txt učitava podatke o automobilima. 
Program treba izdvojiti sve automobile čije je ubrzanje manje od 6 sekundi, a cijena veća od 1.000.000. 
Izdvojeni automobili se ispisuju u datoteku brzi.txt, zajedno s najbržim i najskupljim automobilom iz te skupine.

Ulaz: KOMPLETNA automobili.txt datoteka

Izlaz:
Mercedes SL 63 AMG kabriolet 6208 525 5 250 1456262
Porsche 911 Turbo Coupe coupe 3600 480 4 310 1403739
Mercedes CL 500 coupe 5461 388 5 250 1119382
Ferrari F430 coupe 4307 490 4 315 1074177
BMW M6 coupe 2V 4999 507 5 250 1170963
Mercedes SL 500 kabriolet 5461 388 5 250 1075319

najbrzi je 911 Turbo Coupe, ubrzanje 4
najskuplji je SL 63 AMG, cijena 1456262
*/
*/

typedef struct {
    char prizvodjac[40 + 1];
    char model[40 + 1];
    char karoserija[40 + 1];
    int volumen;
    int snagaKW;
    int ubrzanje;
    int brzina;
    int cijena;
} Auto;

int main()
{
    FILE* fin = fopen("automobili.txt", "r");
    FILE* fout = fopen("brzi.txt", "w");
    Auto automobil[1000];
    int n = 0; //broj auta
    while (fscanf(fin, " %[^#]#%[^#]#%[^#]#%d#%d#%d#%d#%d", automobil[n].prizvodjac, automobil[n].model, automobil[n].karoserija,
        &automobil[n].volumen, &automobil[n].snagaKW, &automobil[n].ubrzanje, &automobil[n].brzina, &automobil[n].cijena) == 8) {
        n++;
    }
    int najbrzi = 0;
    int najskuplji = 0;
    for (int i = 0; i < n; i++) {
        if (automobil[i].ubrzanje < 6 && automobil[i].cijena > 1000000) {
            fprintf(fout, "%s %s %s %d %d %d %d %d\n", automobil[i].prizvodjac, automobil[i].model, automobil[i].karoserija,
                automobil[i].volumen, automobil[i].snagaKW, automobil[i].ubrzanje, automobil[i].brzina, automobil[i].cijena);
            if (automobil[i].ubrzanje < automobil[najbrzi].ubrzanje) {
                najbrzi = i;
            }
            if (automobil[i].cijena > automobil[najskuplji].cijena) {
                najskuplji = i;
            }
        }
        
    }
    fprintf(fout, "najbrzi je %s, ubrzanje %d\n", automobil[najbrzi].model, automobil[najbrzi].ubrzanje);
    fprintf(fout, "najskuplji je %s, cijena %d", automobil[najskuplji].model, automobil[najskuplji].cijena);
    fclose(fin);
    fclose(fout);
    return 0;
}
