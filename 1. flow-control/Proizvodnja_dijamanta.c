#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
/*Dobili ste posao u startupu koji je izmislio tehonologiju proizvodnje dijamanta po narudžbi.
Zadatak Vam je proizvesti "savršene" dijamante sa specificiranim brojem karata
kako bi zadovoljili toèno odreðene potrebe tržišta.
Svima je poznato kako "savršeni" dijamanti imaju neparan broj karata. 
Potrebno je isprogramirati funkciju koja pronalazi dijamant od znakova '*'
na naèin da kao ulazni parametar uzmete naruèeni broj karata dijamanta.
Ukoliko iz skladišta naruèe dijamant sa pogrešnim brojem karata potrebno je ispisati poruku:
"Pogreska: Zadani dijamant nije savrsen!"

Test case #1
Primjer ulaza: 
5
Primjer izlaza:
  *
 ***
*****
 ***
  *

*/
int main()
{
    int karata;
    scanf("%d", &karata);
    // Provjera je li broj karata neparan
    if (karata % 2 == 0) {
        printf("Pogreska: Zadani dijamant nije savrsen!\n");
        return 0;
    }
    printf("\n");
    int sredina = karata / 2;
    // Gornji dio dijamanta
    for (int i = 0; i <= sredina; i++) {
        for (int j = 0; j < sredina - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    // Donji dio dijamanta
    for (int i = sredina - 1; i >= 0; i--) {
        for (int j = 0; j < sredina - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

