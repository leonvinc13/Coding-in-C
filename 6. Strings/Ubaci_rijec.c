#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

/*
Zadatak: Ubacivanje podstringa u zadanim intervalima
Napišite program koji u zadani string (string1) ubacuje drugi string (string2) nakon svakih a znakova.
Ulaz:
string1 – osnovni string (maksimalno 100 znakova).
string2 – string koji se ubacuje (maksimalno 50 znakova).
a – broj znakova nakon kojih se string2 ubacuje.
Izlaz:
Broj puta koliko je string2 ubacen u string1.
Novi oblik string1 nakon umetanja.

Test case #1
Ulaz:
str1: programiranje  
str2: XX  
a=3  

Izlaz:
Ubaceno: 4  
proXXgraXXmirXXanjXXe  
*/

int ubaci_string(char* string1, char* string2, int a) {
    int duzina1 = strlen(string1);
    int duzina2 = strlen(string2);
    int novi_duzina = duzina1 + (duzina1 / a) * duzina2;
    char rezultat[100 + 1] = "";
    int indeks = 0;
    for (int i = 0; i < duzina1; i++) {
        rezultat[indeks++] = string1[i];
        if ((i + 1) % a == 0) {
            strcat(rezultat, string2);
            indeks += duzina2;
        }
    }
    strcpy(string1, rezultat);
    return duzina1 / a;
}

int main()
{
    char string1[100 + 1];
    char string2[50 + 1];
    int a;
    scanf(" str1: %[^\n]", string1);
    scanf(" str2: %[^\n]", string2);
    scanf(" a=%d", &a);
    printf("Ubaceno: %d\n", ubaci_string(string1, string2, a));
    printf("%s", string1);
    return 0;
}


