#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
U datoteci naziva "nogomet.txt" nalaze se rezultati utakmica 18 nogometnih klubova australske lige 
(nazivi klubova su točni, a rezultati su nasumično odabrani!).
Jedan zapis u datoteci je zapisan prema sljedećem:
naziv 1. kluba#naziv 2. kluba#broj golova 1.kluba:broj golova 2.kluba
kao na primjeru:
North Melbourne Kangaroos (Melbourne)#Adelaide Crows (Adelaide)#6:3
Nazivi klubova mogu se sastojati od više riječi.

Učitavanjem ulazne datoteke sastavite izlaznu datoteku s nazivom "prvi.txt" koja sadrži zapis kluba 
koji ima najviše bodova, u obliku strukture:
naziv kluba (do 40 znakova),
broj odigranih utakmica, cijeli broj,
broj pobjeda, cijeli broj,
broj neriješenih ishoda, cijeli broj,
broj poraza, cijeli broj,
ukupni broj bodova, cijeli broj.
Bodove računate prema uobičajenom kriteriju: za pobjedu 3, za neriješeno 1, za poraz 0.

Test case 1#
Ulaz: 
nogomet.txt

Izlaz: 
Melbourne Demons (Melbourne) 34 20 8 6 68
*/

typedef struct {
    char naziv[100 + 1];
    int odigrane_utakmice;
    int pobjeda;
    int nerijesenih;
    int poraza;
    int bodovi;
} Klub;

//Carlton Blues (Melbourne)#Geelong Cats (Geelong)#3:0
int main()
{
    FILE* fin = fopen("nogomet.txt", "r");
    FILE* fout = fopen("prvi.txt", "w");
    Klub klub[100] = { 0 };
    int brojKlubova = 0;
    char tim1[40 + 1], tim2[40 + 1];
    int golovi1, golovi2;
    int flag1, flag2;
    while (fscanf(fin, " %[^#]#%[^#]#%d:%d", tim1, tim2, &golovi1, &golovi2) == 4)
    {
        flag1 = 0;
        flag2 = 0;
        for (int i = 0; i < brojKlubova; i++) {
            if (strcmp(klub[i].naziv, tim1) == 0) {
                flag1++;
                klub[i].odigrane_utakmice++;
                if (golovi1 > golovi2) {
                    klub[i].bodovi += 3;
                    klub[i].pobjeda++;
                }
                else if (golovi1 == golovi2) {
                    klub[i].bodovi++;
                    klub[i].nerijesenih++;
                }
                else {
                    klub[i].poraza++;
                }
            }
            if (strcmp(klub[i].naziv, tim2) == 0) {
                flag2++;
                klub[i].odigrane_utakmice++;
                if (golovi1 < golovi2) {
                    klub[i].bodovi += 3;
                    klub[i].pobjeda++;
                }
                else if (golovi1 == golovi2) {
                    klub[i].bodovi++;
                    klub[i].nerijesenih++;
                }
                else {
                    klub[i].poraza++;
                }
            }
        }
        if (flag1 == 0) {
            strcpy(klub[brojKlubova].naziv, tim1);
            klub[brojKlubova].odigrane_utakmice++;
            if (golovi1 > golovi2) {
                klub[brojKlubova].bodovi += 3;
                klub[brojKlubova].pobjeda++;
            }
            else if (golovi1 == golovi2) {
                klub[brojKlubova].bodovi++;
                klub[brojKlubova].nerijesenih++;
            }
            else {
                klub[brojKlubova].poraza++;
            }
            brojKlubova++;
        }
        if (flag2 == 0) {
            strcpy(klub[brojKlubova].naziv, tim2);
            klub[brojKlubova].odigrane_utakmice++;
            if (golovi1 < golovi2) {
                klub[brojKlubova].bodovi += 3;
                klub[brojKlubova].pobjeda++;
            }
            else if (golovi1 == golovi2) {
                klub[brojKlubova].bodovi++;
                klub[brojKlubova].nerijesenih++;
            }
            else {
                klub[brojKlubova].poraza++;
            }
            brojKlubova++;
        }
    }
    int max = 0;
    int pozMax = 0;
    for (int i = 0; i < brojKlubova; i++) {
        if (klub[i].bodovi > max) {
            max = klub[i].bodovi;
            pozMax = i;
        }
    }
    fprintf(fout, "%s %d %d %d %d %d", klub[pozMax].naziv, klub[pozMax].odigrane_utakmice,
        klub[pozMax].pobjeda, klub[pozMax].nerijesenih, klub[pozMax].poraza, klub[pozMax].bodovi);
    fclose(fin);
    fclose(fout);
    return 0;
}


