#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
Mario, Arian i Ivan su naizgled obični studenti. No, pokazalo se da njihov mlađi brat Branimir 
i nije tako običan. On naime voli pratiti rukomet, i bilježiti rezultate rukometnih utakmicama i 
igrati jednu (njemu) izuzetno interesnatnu igru s brojevima. Naime, on zapiše rezultate N rukometnih 
utakmica, te za svaki tako napisani par brojeva a i b izračuna redom:
broj Sz koji označava sumu svih znamenki svih brojeva u intervalu [a,b]
broj Nd koji označava ukupan broj svih djelitelja svih brojeva u intervalu [a,b]
zapiše zbroj Sz % Nd (modulo operacija) na novi papir. Ukoliko je Nd jednak 0, potrebno je zapisati 
broj 0 na novi papir.
Nakon toga, Branimir posloži sve brojeve na novom papiru po redu od najvećeg do najmanjeg i pošalje u 
SMS poruci Mariu, Arianu i Ivanu. 
S druge strane, Mario, Arian i Ivan, znajući koje utakmice se trenutno odigravaju, pokušavaju 
predvidjeti koji će SMS dobiti. Mario je, ponukan uspjehom u programiranju, odlučio nadmudriti 
Ariana i Ivana i napraviti program koji će mu odmah izračunati koja bi mogla biti SMS poruka. 
Hoće li Mario uspjeti u tome? Ostaje da vidimo...

Napomena: potrebno je izračun brojeva Sz i Nd realizirati funkcijom. U zadatku je dopušteno 
koristiti više funkcija.

Test case #1
Primjer ulaza:
2
21 22
25 24

Primjer izlaza:
6, 3


Test case #2
Primjer ulaza:
10
54 39
57 38
39 43
43 59
39 59
48 53
57 30
30 56
44 32
47 40

Primjer izlaza:
60, 54, 52, 34, 24, 24, 16, 13, 9, 6
*/

#define MAX 200

int Sz(int a, int b) {
	int znamenka, sumaZ = 0, suma = 0;
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	for (int i = a; i <= b; i++) {
		int broj = i;
		sumaZ = 0;
		while (broj > 0) {
			znamenka = broj % 10;
			broj = broj / 10;
			sumaZ += znamenka;
		}
		suma += sumaZ;
	}
	return suma;
}

int Nd(int a, int b) {
	int brD = 0, br = 0;
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	for (int i = a; i <= b; i++) {
		brD = 0;
		for (int j = 2; j <= i/2; j++) {
			if (i % j == 0) {
				brD++;
			}
		}
		br += brD;
	}
	return br;
}

int main()
{
	long long int n, gol1, gol2;
	long long int sz, nd, niz[MAX];
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &gol1, &gol2);
		sz = Sz(gol1, gol2);
		nd = Nd(gol1, gol2);
		if (nd == 0) {
			niz[i] = 0;
		}
		else {
			niz[i] = sz % nd;
		}
	}
	int bilaZamjena = 1;
	do {
		bilaZamjena = 0;
		for (int i = 0; i < n - 1; i++) {
			if (niz[i] > niz[i + 1]) {
				int temp = niz[i];
				niz[i] = niz[i + 1];
				niz[i + 1] = temp;
				bilaZamjena = 1;
			}
		}
	} while (bilaZamjena);
	
	for (int i = n - 1; i >= 0; i--) {
		if (i == 0) {
			printf("%lld", niz[i]);
		}
		else printf("%lld, ", niz[i]);
	}
	return 0;
}

