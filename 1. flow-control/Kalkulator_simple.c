#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

/*
Isprogramirajte jednostavni kalkulator!
Vaš kalkulator treba podržavati funkcije:

Zbrajanje
Oduzimanje
Množenje
Dijeljenje
Kvadriranje

Kalkulator treba raditi samo s cijelim brojevima.
Pogledajte test caseove za primjere rada kalkulatora. 

Test case #1
Primjer ulaza: 3+65
Primjer izlaza: 68

Test case #2
Primjer ulaza: 5-21
Primjer izlaza: -16

Test case #3
Primjer ulaza: 12K
Primjer izlaza: 144
*/

int main()
{
	int broj1, broj2;
	char operacija;
	scanf("%d", &broj1);
	scanf("%c", &operacija);
	if (operacija == 'K')
	{
		int kvadrat = pow(broj1, 2);
		printf("%d", kvadrat);
		return 0;
	}
	scanf("%d", &broj2);
	if (operacija == '+')
	{
		int zbroj = broj1 + broj2;
		printf("%d", zbroj);
		return 0;
	}
	if (operacija == '-')
	{
		int razlika = broj1 - broj2;
		printf("%d", razlika);
		return 0;
	}
	if (operacija == '*')
	{
		int umnozak = broj1 * broj2;
		printf("%d", umnozak);
		return 0;
	}
	if (operacija == '/')
	{
		int kvocijent = broj1 / broj2;
		printf("%d", kvocijent);
		return 0;
	}

}