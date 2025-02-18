#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
Nevenka Bekavac (40) iz Splita već nekoliko godina zaredom prijavljuje se u emisiju 
„Ljubav je na selu“ kako bi pronašla ljubav svog života. Međutim, do sada ju još uvijek nije pronašla. 
Ona zna što želi i kako bi trebao izgledati savršeni odabranik njenog srca, ali takav se još nije 
pojavio ni u emisiji ni u njenom životu. Kako bi joj pomogli, voditeljica showa Marijana Batinić i 
posrednik za ljubav Gangster pomažu Nevenki da pronađe svog princa na bijelom konju te joj šalju SMS 
poruke (jer Nevenka ne koristi podatkovne usluge svog mobilnog operatera) u kojima se nalaze informacije 
o potencijalnim ženicima. Od dobivenog skupa SMS poruka Nevenka se svaki put mora odlučiti za kandidate 
za spoj i njihova imena i prezimena poslati porukom nazad Marijani i Gangsteru.
Od svih kandidata Nevenka će se pristati naći s onim koji posjeduje neku od sljedećih karakteristika:
Mlađi je od nje ili maksimalno 5 godina stariji
Crn
Visok
Bogat
U svaku SMS poruku stane maksimalno 160 znakova, te su poruke često jako sažete, a u njima se može 
nalaziti opis i više kandidata. Ime i prezime kandidata uvijek se nalazi napisano na početku svake 
SMS poruke. Ukoliko u jednoj poruci ima više kandidata isti su odvojeni znakom '#'. Nevenka nikada ne 
zna koliko će dobiti SMS poruka (svaka SMS poruka prima se kao zasebni string). Prije nego dobije 
SMS-ove s potencijalnim ženicima, Nevenka dobiva kontrolni SMS (također string!) u kojem piše broj 
poruka koje će dobiti.
Napišite funkciju prototipa char *trazi(char *sms) koja će na temelju primljenih SMS poruka pronaći 
kandidate koji se sviđaju Nevenki te umjesto nje složiti SMS poruku (funkcija kreira znakovni niz s 
imenima i prezimenima kandidata iz SMS poruke) koja se šalje Marijani i Gangsteru.

Test case #1
Ulaz:
3
Ranko Pavlovic Rumeni (39). Kokinci. Bavi se uzgojem svinja te radi i kao licilac. Dvoje djece. Na youtube kanalu postavlja skeceve.
Danko Bezmalinovic (57). Brac. Zidar.#Josip Juric (25). Sportas. Vinar. Zivi sa sestrom.#Ivica Stapic (52). Habjanovci. Autoelektricar.
Stipe Filipovic (40). Aleksinci. Ima brk. Uzgaja ovce. Ne podnosi nepravdu i laz.

Izlaz:
Ranko Pavlovic Rumeni
Josip Juric
Stipe Filipovic
*/
char* trazi(char* sms) {
    char kandidat[160 + 1], starost[3 + 1], opis[160 + 1];
    char prosli_opis[160 + 1];
    sscanf(sms, "%[^(](%[^)]).%[^\n]", kandidat, starost, opis);
    char* rezultat = (char*)malloc(strlen(kandidat) + 1);
    strcpy(rezultat, kandidat);
    int dob = atoi(starost);
    if (dob <= 45 || strstr(opis, "Crn") != 0 || strstr(opis, "Bogat") != 0 || strstr(opis, "Visok") != 0) {
        return rezultat;
    }
    if (strchr(opis, '#') != 0) {
        while ((strchr(opis, '#') != 0)) {
            sscanf(opis, "%[^#]#%[^(](%[^)]).%[^\n]", prosli_opis, kandidat, starost, opis);
            char* rezultat = (char*)malloc(strlen(kandidat) + 1);
            strcpy(rezultat, kandidat);
            int dob = atoi(starost);
            if (dob <= 45 || strstr(opis, "Crn") != 0 || strstr(opis, "Bogat") != 0 || strstr(opis, "Visok") != 0) {
                return rezultat;
            }
        }
    }
    else return 0;
    
}

int main()
{
    int n;
    char sms[160 + 1];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%[^\n]", sms);
        if (trazi(sms)) {
            printf("%s\n", trazi(sms));
        }
        getchar();
    }
    return 0;
}


