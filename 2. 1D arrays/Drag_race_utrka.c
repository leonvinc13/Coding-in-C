#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
U zagrebu se održava utrka za konje. 
S ljeve i desne strane ima 20 mjesta za gledatalje te nakon svakog 5. mjesta mora biti praznina.
Pomozite organizatoru popuniti mjesta, tamo gdje je zauzeto biće 1, a gdje je prazno 0.
Pogledaj test casove.

Test case #1
Primjer ulaza:
1
3 5 7 20
4 7 8 10 15

Primjer izlaza:
Pregled zauzeca staze:
00001 01000 00000 00001

00000 01101 00001 00000


Test case #2
Primjer ulaza:
2
3 5 7 20
4 7 8 10 15
4 3 9 11 19
7 1 2 3 11 12 14 16

Primjer izlaza:
Pregled zauzeca staze:
00101 01010 10000 00011

11100 01101 11011 10000
*/


#define MAX 100

int main()
{
	int n, brojLKarti[MAX], brojDKarti[MAX], lkarte[MAX], dkarte[MAX];
	int niz1[MAX] = { 0 }, niz2[MAX] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &brojLKarti[i]);
		for (int j = 0; j < brojLKarti[i]; j++) {
			scanf("%d", &lkarte[j]);
			for (int k = 0; k < 20; k++) {
				if (k + 1 == lkarte[j]) {
					niz1[k] = 1;
				}
			}
		}
		scanf("%d", &brojDKarti[i]);
		for (int j = 0; j < brojDKarti[i]; j++) {
			scanf("%d", &dkarte[j]);
			for (int k = 0; k < 20; k++) {
				if (k + 1 == dkarte[j]) {
					niz2[k] = 1;
				}
			}
		}
	}
	for (int i = 0; i < 20; i++) {
		printf("%d", niz1[i]);
		if (i % 5 == 4) printf(" ");
	}
	printf("\n\n");
	for (int i = 0; i < 20; i++) {
		printf("%d", niz2[i]);
		if (i % 5 == 4) printf(" ");
	}
}

