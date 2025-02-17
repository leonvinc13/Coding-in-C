#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*Potrebno je uèitati prirodni broj N, te u iduæoj liniji N cijelih brojeva.
Nakon toga uèitava se broj X, te slijedi X linija gdje se uèitava broj Ai i Bi.
Za svaki par Ai i Bi, treba broj Ai ubaciti na mjesto Bi u nizu
(broji se od 1 ne od 0 - pogledati test primjere), te ispisati niz.

Test case #1
Primjer ulaza: 
5
1 3 5 6 3
2
9 1
99 7
Primjer izlaza:
9 1 3 5 6 3
9 1 3 5 6 3 99
*/

int main()
{
    int N; 
    scanf("%d", &N);
    int niz[200]; 
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &niz[i]); 
    }
    int X; 
    scanf("%d", &X);
    for (int i = 0; i < X; i++)
    {
        int koji, gdje; 
        scanf("%d %d", &koji, &gdje);
        for (int j = N; j >= gdje; j--)
        {
            niz[j] = niz[j - 1];
        }
        niz[gdje - 1] = koji;
        N++;
        for (int j = 0; j < N; j++)
        {
            printf("%d ", niz[j]);
        }
        printf("\n");
    }
    return 0;
}

