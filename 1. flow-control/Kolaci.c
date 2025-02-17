#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

/*
Perici je mama dala džeparac za šlolu, a on ga je odlučio potrošiti na kolače u slastičarni.
Slastičarna nudi kolače različitih oblika,veličina i cijena.
Perica treba program u koji unosi iznos džeparca,broj stranica,duljinu stranice,
visinu kolača(sve u cm) i cijenu jednog komada(u kn).
Program ispisuje koliko kolača može kupiti i kolika je isplativost
(koliko kuna plati za jedan cm^3 kolača).

Broj stranica kolača ne smije biti manji od 3. Duljina stranice moraju biti 0 ili veći.
Ukoliko je unos krivi, ispisati "Krivi unos! Molim probajte opet." i čekati na novi unos.

Napomene: 
formula za volumen jednog kolača: V=h*n*(a^2)*(cos(3.14/n)/sin(3.14/n))/4
isplativost=cijena jednog kolača/volumen jednog kolača

Test case #1
Primjer ulaza: 1003 3 5 2 10
Primjer izlaza: Perica moze kupiti: 100 kolaca, a platit ce 0.46kn/cm^3.

Test case #2
Primjer ulaza: 67 2 6 2 1 3
Primjer izlaza: Krivi unos! Molim probajte opet.
Perica moze kupiti: 22 kolaca, a platit ce 0.29kn/cm^3.

Test case #3
Primjer ulaza: 5 3 4 1 7
Primjer izlaza: Perica moze kupiti: 0 kolaca, a platit ce 1.01kn/cm^3.
*/


int main()
{
	float duljina_stranice, visina_kolaca, cijena_jednog, volumen, isplativost;
	int deparac, broj_stranica, kolicina;
	scanf("%d %d %f %f %f", &deparac, &broj_stranica, &duljina_stranice, &visina_kolaca, &cijena_jednog);
	volumen = visina_kolaca * broj_stranica * (pow(duljina_stranice, 2)) * (cos(3.14 / broj_stranica) / sin(3.14 / broj_stranica)) / 4;
	isplativost = cijena_jednog / volumen;
	kolicina = deparac / cijena_jednog;
	if (broj_stranica < 3 || duljina_stranice < 0)
	{
		printf("Krivi unos! Molim probajte opet.\n");
	}
	printf("Perica moze kupiti: %d kolaca, a platit ce %.2fkn/cm^3.", kolicina, isplativost);
	return 0;
}

