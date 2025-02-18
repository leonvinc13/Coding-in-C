#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

/*
Zadatak: Sortiranje rečenica po broju slova 'A'
Napišite program koji sortira unesene rečenice prema broju pojavljivanja slova 'a' i 'A'. 
Rečenice s većim brojem tih slova dolaze prije onih s manjim brojem.
Ulaz: Više rečenica (do 20), svaka duljine do 30 znakova.
Unos završava rečenicom koja sadrži znak ?, koja se također obrađuje.
Izlaz: Rečenice ispisane u silaznom redoslijedu prema broju slova 'A'/'a'.

Test case #1
Ulaz:
An apple a day keeps the doctor away  
Amazing algorithm analysis  
Artificial intelligence is awesome  
Are you ready?  

Izlaz:
Amazing algorithm analysis  
Artificial intelligence is awesome  
An apple a day keeps the doctor away  
Are you ready?  
*/

void sortiraj(int n, char recenica[][30 + 1]) {
    int sumA[20] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < strlen(recenica[i]); j++) {
            if (recenica[i][j] == 'a' || recenica[i][j] == 'A') {
                sumA[i]++;
            }
        }
    }
    int bilaZamjena = 0;
    do {
        bilaZamjena = 0;
        for (int i = 0; i < n - 1; i++) {
            if (sumA[i] < sumA[i + 1]) {
                char temp[100 + 1];
                strcpy(temp, recenica[i]);
                strcpy(recenica[i], recenica[i + 1]);
                strcpy(recenica[i + 1], temp);
                int tempSum = sumA[i];
                sumA[i] = sumA[i + 1];
                sumA[i + 1] = tempSum;
                bilaZamjena = 1;
            }
        }
    } while (bilaZamjena);
}

int main()
{
    int n = 0;
    char recenica[20][30 + 1];
    while (1){
        scanf(" %[^\n]", recenica[n]);
        if (strchr(recenica[n], '?') != NULL) { 
            n++;
            break; 
        }
        n++;
    } 
    sortiraj(n, recenica);
    for (int i = 0; i < n; i++) {
        printf("%s\n", recenica[i]);
    }
    return 0;
}


