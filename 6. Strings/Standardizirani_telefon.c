#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
* Standardiziraj telefon
* 
* Test case #1
* Ulaz: 01/2323211
* Izlaz: +38512323211
* 
* Test case #2
* Ulaz: 098/123-456
* Izlaz: +38598123456
* 
* Test case #3
* Ulaz: +385-21-987-6543
* Izlaz: +385219876543
*/

char* telefonski(char* stari) {
    char vodeci[100 + 1], ostatak[100 + 1];
    char prvi[100 + 1], drugi[100 + 1];
    char pocetak[100 + 1] = "+385";
    if (stari[0] == '0') {
        sscanf(stari, "%[0]%s", vodeci, ostatak);
        while (strchr(ostatak, '/') || strchr(ostatak, '-')) {
            sscanf(ostatak, "%[^/-]%*c%s", prvi, drugi);
            strcat(prvi, drugi);
            strcpy(ostatak, prvi);
        }
        char* rezultat = (char*)malloc(strlen(pocetak) + strlen(ostatak));
        strcat(pocetak, prvi);
        strcpy(rezultat, pocetak);
        return rezultat;
    }
    else {
        strcpy(prvi, stari);
        while (strchr(prvi, '/') || strchr(prvi, '-')) {
            sscanf(prvi, "%[^/-]%*c%s", prvi, drugi);
            strcat(prvi, drugi);
        }
        char* rezultat = (char*)malloc(strlen(prvi));
        strcpy(rezultat, prvi);
        return rezultat;
    }
}

int main()
{
    char stari[100 + 1];
    scanf("%s", stari);
    printf("%s", telefonski(stari));
    return 0;
}