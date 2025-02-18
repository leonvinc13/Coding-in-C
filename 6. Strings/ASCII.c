#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Zadatak: Riječ s najvećom ASCII sumom
Napišite program koji iz zadane rečenice pronalazi riječ s najvećom sumom ASCII vrijednosti 
njezinih znakova.
Ulaz: Jedna rečenica duljine do 100 znakova, unosi se do prve točke (.), koja ne ulazi u analizu.
Rečenica se sastoji od riječi razdvojenih razmakom.
Izlaz: Riječ s najvećom sumom ASCII vrijednosti znakova i njezina ukupna ASCII vrijednost.

Test case #1
Ulaz:
Hello world example.

Izlaz:
example: 748
*/

int sumaZnakova(char* recenica, char* najrijec) {
    int n = 1;
    int max = 0;
    char** rijeci;
    int sumaASCII = 0;
    for (int i = 0; i < strlen(recenica); i++) {
        if (recenica[i] == ' ') {
            n++;
        }
    }
    rijeci = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        rijeci[i] = (char*)malloc(sizeof(char) * 100);
    }
    char* token = strtok(recenica, " ");
    int index = 0;
    while (token != NULL) {
        strcpy(rijeci[index++], token);
        sumaASCII = 0;
        for (int i = 0; i < (strlen(token)); i++) {
            sumaASCII += (int)token[i];
        }
        if (sumaASCII > max) {
            max = sumaASCII;
            strcpy(najrijec, token);
        }
        token = strtok(NULL, " ");
    }
    return max;
}

int main()
{
    char najrijec[100 + 1];
    char recenica[100 + 1];
    scanf("%[^.]", recenica);
    int maxSum = sumaZnakova(recenica, najrijec);
    printf("%s: %d", najrijec, maxSum);
    return 0;
}

