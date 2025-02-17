#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
Spolizacija je proces u birokraciji kojim se na temelju JMBG broja građana određuje kojeg
je spola građanin.
Za Zagreb vrijedi sljedeće pravilo kod JMBG brojeva: prvih 7 znamenki nastaje iz datuma rođenja,
nakon toga 330 ako se radi o muškarcu, 335 ako se radi o ženi.
Algoritam za zadnje 3 znamenke je u našem slučaju nebitan, i recimo da su zadnje 3 znamenke proizvoljne. 

Primjer jednog JMBG-a muškarca rođenog na datum 04.07.2010.:
0407010330007 (test case 1)
Primjer jednog JMBG-a žene rođene na datum 12.03.1996.:
1203996335909 (test case 2)

Dodatno, spolizaciju obavlja tek referent početnik,
te zbog ne snalaženja u poslu unosi JMBG znamenku po znamenku u svaki redak.
Vaša je zadaća napisati program u kojem će on unijeti znamenku po znamenku i po unosu svih 13 znamenki,
program ispisuje „Muška osoba“ ukoliko se radi o muškarcu ili „Ženska osoba“ ukoliko se radi o ženi.
*/

int main()
{
    int z1, z2, z3, z4, z5, z6, z7, z8, z9, z10, z11, z12, z13;
    scanf("%d", &z1);
    scanf("%d", &z2);
    scanf("%d", &z3);
    scanf("%d", &z4);
    scanf("%d", &z5);
    scanf("%d", &z6);
    scanf("%d", &z7);
    scanf("%d", &z8);
    scanf("%d", &z9);
    scanf("%d", &z10);
    scanf("%d", &z11);
    scanf("%d", &z12);
    scanf("%d", &z13);
    if (z8 == 3 && z9 == 3 && z10 == 0)
    {
        printf("Musko!");
        return 0;
    }
    else if (z8 == 3 && z9 == 3 && z10 == 5)
    {
        printf("Zensko!");
        return 0;
    }
    else
    {
        printf("Greska!");
    }
    return 0;
}
