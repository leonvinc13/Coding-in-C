#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*Dogaðaju se izbori u jednoj dalekoj zemlji, koja ima zanimljiv koncept glasanja – naime,
zemlja se podijeli u matricu NxM, i svako polje u matrici daje odreðen broj glasova jednom i
odreðen broj glasova drugom kandidatu.
Vi nikako ne biste htjeli da kandidat Ronald pobijedi, i ono što možete napraviti je dignuti zid 
oko jednog retka ili jednog stupca,
tako da glasovi unutar tog retka ili stupca budu potpuno neutralizirani, što znaèi da niti Ronald, 
ali ni drugi kandidat neæe dobiti te glasove.
S obzirom na procjene anketa, potrebno je izabrati optimalni stupac ili redak koji treba ograditi zidom.
Napomena: one koji su krivo glasali protjerat æete iz države kasnije, a onima sliènim njima zabraniti 
ulaz.
Prvo se uèitavaju N i M, a nakon toga slijede 2 matrice gdje je definirano koliko je 
glasova za kandidata Ronalda,
te koliko je glasova za drugog kandidata. Maximalna velicina polja je 100x100.

Test case #1
Primjer ulaza:
5 5

4 26 23 12 5
16 29 5 17 3
14 21 16 18 23
21 10 27 7 10
18 28 25 16 15

20 23 13 8 26
13 1 4 18 8
2 28 30 10 3
9 20 16 8 15
9 9 2 20 5

Primjer izalza:
Najbolje je ukloniti 5. red iz tablica.


Test case #2
Primjer ulaza:
2 3

1 4 5
2 19 6

7 7 9
5 1 2

Primjer izlaza:
Najbolje je ukloniti 2. red iz tablica.
*/

#define MAX 100

int main()
{
    int n, m;
    int mat1[MAX][MAX], mat2[MAX][MAX];
    int sumRed1[MAX] = { 0 }, sumRed2[MAX] = { 0 }, sumStup1[MAX] = { 0 }, sumStup2[MAX] = { 0 };
    int razlika[MAX], maxRazlika;
    int maxRed = 0, maxStup = 0;
    int red, stupac;

    //upis
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    
    //provjera najvece razlike redaka
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sumRed1[i] += mat1[i][j];
            sumRed2[i] += mat2[i][j];
        }
        razlika[i] = sumRed1[i] - sumRed2[i];
        if (razlika[i] > maxRed) {
            maxRed = razlika[i];
            red = i + 1;
        }
    }

    //provjera najvece razlike stupaca
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            sumStup1[j] += mat1[i][j];
            sumStup2[j] += mat2[i][j];
        }
        razlika[j] = sumStup1[j] - sumStup2[j];
        if (razlika[j] > maxStup) {
            maxStup = razlika[j];
            stupac = j + 1;
        }
    }

    if (maxRed > maxStup) {
        printf("Najbolje je ukloniti %d. red iz tablica.", red);
    }
    else {
        printf("Najbolje je ukloniti %d. stupac iz tablica.", stupac);
    }
    return 0;
}

