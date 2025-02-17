#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
/*Dobili ste posao u startupu koji je izmislio tehonologiju proizvodnje dijamanta po narud�bi.
Zadatak Vam je proizvesti "savr�ene" dijamante sa specificiranim brojem karata
kako bi zadovoljili to�no odre�ene potrebe tr�i�ta.
Svima je poznato kako "savr�eni" dijamanti imaju neparan broj karata. 
Potrebno je isprogramirati funkciju koja pronalazi dijamant od znakova '*'
na na�in da kao ulazni parametar uzmete naru�eni broj karata dijamanta.
Ukoliko iz skladi�ta naru�e dijamant sa pogre�nim brojem karata potrebno je ispisati poruku:
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

