#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*Boštjan izraðuje aplikaciju za pametni kalendar.
Kao jednu od osnovnih funkcionalnosti, potrebno je napraviti modul za izraèun toènog datuma u odnosu
na zadani trenutak u vremenu.
Kao prvi parametar, potrebno je uèitati brojeve D, M, G H, m i s,
koji predstavljaju dan, mjesec, godinu, sat, minutu i sekundu.
Ukoliko je godina manja od 1900 ili veæa od 2015, potrebno je ponoviti upis.
Nakon toga potrebno je ucitati prirodni broj K. 
Kao rezultat, potrebno je ispisati toèan datum (dan, mjesec, godinu i vrijeme)
uveæan za K sekundi u odnosu na poèetni datum
Primjerice, ukoliko se unese datum 10.09.2015 15:45:30, i za uneseni broj sekundi K = 45,
rezultat bi bio 10.09.2015 15:46:15 (poèetni datum uveæan za 1min i 15s).
svi datumi æe biti u ispravnom formatu (osim možda godine, koja ako ne spada u gore navedeni interval,
treba ponoviti upis - pogledati test primjere za pojašnjenje)
za broj sekundi vrijedi, 0 < K < 232
priprema sadrži 10 test primjera, od kojih su 2 skrivena test primjera.
Za dobivanje boda, potrebno je da kod radi za 80% primjera.
Za prisustvo vježbi potrebno je da priprema radi za 20% primjera
potrebno je samostalno istražiti pravila prijestupne godine*/

int main()
{
    long long unsigned D, M, G, H, m, s, K;
    do {
        scanf("%llu %llu %llu %llu %llu %llu\n", &D, &M, &G, &H, &m, &s);
    } while (G < 1900 || G > 2015);
    scanf("%llu", &K);
    s += K;
    
    m += s / 60;      
    s %= 60;         

    H += m / 60;      
    m %= 60;         

    D += H / 24;      
    H %= 24;
    
    while (1) {
        int dani_u_mjesecu;

        // Odreðujemo broj dana u trenutnom mjesecu
        if (M == 2) { // veljaèa
            if ((G % 4 == 0 && G % 100 != 0) || (G % 400 == 0)) {
                dani_u_mjesecu = 29; // prijestupna godina
            }
            else {
                dani_u_mjesecu = 28;
            }
        }
        else if (M == 4 || M == 6 || M == 9 || M == 11) {
            dani_u_mjesecu = 30; // travanj, lipanj, rujan, studeni
        }
        else {
            dani_u_mjesecu = 31; // ostali mjeseci
        }
        // Ako trenutni dan ne prelazi broj dana u mjesecu, izlazimo iz petlje
        if (D <= dani_u_mjesecu) {
            break;
        }
        // Ako trenutni dan prelazi broj dana u mjesecu, prelazimo na sljedeæi mjesec
        D -= dani_u_mjesecu;
        M++;
        // Ako smo prešli prosinac, prelazimo na sljedeæu godinu
        if (M > 12) {
            M = 1;
            G++;
        }
    }
    // Ispis rezultata
    printf("%llu.%llu.%llu. %02llu:%02llu:%02llu\n", D, M, G, H, m, s);
    return 0;
}

