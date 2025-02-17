#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
Napišite C program koji računa cijenu za ličenje prostorije visine V metara,
 širine S metara i duljine D metara, ako se jedan metar kvadratni naplaćuje 10,40 kn. 
Potrebno je uzeti u obzir da se u prostoriji ne liče podovi i vrata visine 0,75*V 
(75% visine prostorije) i širine A i dva prozora dimenzija 0,1*Vx0,1*S (10% visine i širine prostorije). 

V,S,D i A su pozitivni realni brojevi koje unosi korisnik.
U slučaju pogrešnih unosa dimenzija, ispisati odgovarajuće poruke
( "Dimenzija mora biti pozitivna!" ili "Vrata moraju stati u prostoriju!").

Nakon ispravnih unosa potrebno je ispisati konačnu cijenu ličenja u obliku:
Konacna cijena je: __ kuna i ___lipa.

Test case #1
Primjer ulaza: 2.2 3 4 0.9
Primjer izlaza: Konacna cijena je: 428 kuna i 30 lipa.

Test case #2
Primjer ulaza: 3.1 -4 2.45 0.9
Primjer izlaza: Dimenzija mora biti pozitivna!

Test case #3
Primjer ulaza: 4 2.3 2.81 3
Primjer izlaza: Vrata moraju stati u prostoriju!
*/
int main()
{
    float V, S, D, A;
    scanf("%f %f %f %f", &V, &S, &D, &A);
    float strop = S * D;
    float zidovi = (2 * V * S) + (2 * V * D);
    float vrata = A * 0.75 * V;
    float prozori = 2 * 0.1 * V * 0.1 * S;
    float prostorija = strop + zidovi - vrata - prozori;
    float ukupno = prostorija * 10.40;
    int kuna = (int)ukupno;
    int lipa = (ukupno - kuna) * 100;
    if (V < 0 || S < 0 || D < 0 || A < 0)
    {
        printf("Dimenzija mora biti pozitivna!");
        return 0;
    }
    if (A > D && A > S)
    {
        printf("Vrata moraju stati u prostoriju!");
        return 0;
    }
    printf("Konacna cijena je: %d kuna i %d lipa.", kuna, lipa);
    return 0;
}

