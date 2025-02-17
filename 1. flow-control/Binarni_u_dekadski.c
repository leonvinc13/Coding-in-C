#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
Program koji pretvara binarni broj u dekadski
*/
int main()
{
    int broj, znamenka, rezultat, suma = 0;
    int x = 0;
    scanf("%d", &broj);
    while (broj > 0) {
        znamenka = broj % 10;
        rezultat = znamenka * pow(2, x);
        broj = broj / 10;
        x++;
        suma = suma + rezultat;
    }
    //printf("%X", broj);
    printf("%d", suma);
    return 0;
}

