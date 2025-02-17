#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*Bo�tjan izra�uje aplikaciju za pametni kalendar.
Kao jednu od osnovnih funkcionalnosti, potrebno je napraviti modul za izra�un to�nog datuma u odnosu
na zadani trenutak u vremenu.
Kao prvi parametar, potrebno je u�itati brojeve D, M, G H, m i s,
koji predstavljaju dan, mjesec, godinu, sat, minutu i sekundu.
Ukoliko je godina manja od 1900 ili ve�a od 2015, potrebno je ponoviti upis.
Nakon toga potrebno je ucitati prirodni broj K. 
Kao rezultat, potrebno je ispisati to�an datum (dan, mjesec, godinu i vrijeme)
uve�an za K sekundi u odnosu na po�etni datum
Primjerice, ukoliko se unese datum 10.09.2015 15:45:30, i za uneseni broj sekundi K = 45,
rezultat bi bio 10.09.2015 15:46:15 (po�etni datum uve�an za 1min i 15s).
svi datumi �e biti u ispravnom formatu (osim mo�da godine, koja ako ne spada u gore navedeni interval,
treba ponoviti upis - pogledati test primjere za poja�njenje)
za broj sekundi vrijedi, 0 < K < 232
priprema sadr�i 10 test primjera, od kojih su 2 skrivena test primjera.
Za dobivanje boda, potrebno je da kod radi za 80% primjera.
Za prisustvo vje�bi potrebno je da priprema radi za 20% primjera
potrebno je samostalno istra�iti pravila prijestupne godine*/

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

        // Odre�ujemo broj dana u trenutnom mjesecu
        if (M == 2) { // velja�a
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
        // Ako trenutni dan prelazi broj dana u mjesecu, prelazimo na sljede�i mjesec
        D -= dani_u_mjesecu;
        M++;
        // Ako smo pre�li prosinac, prelazimo na sljede�u godinu
        if (M > 12) {
            M = 1;
            G++;
        }
    }
    // Ispis rezultata
    printf("%llu.%llu.%llu. %02llu:%02llu:%02llu\n", D, M, G, H, m, s);
    return 0;
}

