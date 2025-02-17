#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
Preko stranice woohoo.com je moguæe putovati vlakom besplatno, ali uz moguænost da
ste u pogrešnom vagonu koji æe biti izostavljen iz kompozicije. 
To može biti nezgodno ako vam je hitno nekud stiæi, ali može biti odlièno ako vam nije bitno
hoæete li uspjeti poæi ili ne. 
Radi se naime o sljedeæem: woohoo vlakovi polaze s kolodvora samo ukoliko u svakom vagonu, 
poèevši bilo sprijeda bilo straga, se u svakom vagonu nalazi više ili jednako putnika nego u prethodnom, 
te nakon što se svi putnici ukrcaju, vlakovoða odluèuje koje vagone treba izbaciti da bi vlak mogao poæi. 
Èini to na naèin da krene od prvog vagona te kad naiðe na vagon koji mu narušava slijed 
(ima manje putnika nego u prethodnom), onda taj vagon izbacuje iz kompozicije i pregledava sljedeæe 
vagone.
Vaš zadatak je napisati program koji æe vlakovoði pomoæi da izbaci vagone i ispiše koji vagoni 
ostaju u kompoziciji.
U prvom redu se nalazi broj 1 <= N <= 1000 broj vagona. 
U drugom redu slijedi N brojeva gdje svaki predstavlja broj putnika u pojedinom vagonu. 
Broj putnika u svakom vagonu neæe biti veæi od 500.
Napomena: treba uzeti u obzir da su dvije moguænosti - da je slijed rastuæi od prvog vagona 
prema zadnjem, ili od zadnjeg prema prvom, te treba izabrati opciju koja izbacuje manje vagona. 
Ukoliko jednaki broj vagona ostaje u jednoj i drugoj varijanti, treba odabrati opciju u kojoj 
broj putnika raste od prvog prema zadnjem vagonu.

Test case #1
Primjer ulaza: 
8
1 2 3 8 4 3 2 1

Primjer izlaza:
Ostaje 5 vagona: 8 4 3 2 1
*/
int main() {
    int n1, n2;
    int niz1[500], niz2[500];
    int broj_izbacenih1 = 0, broj_izbacenih2 = 0;
    scanf("%d", &n1);
    n2 = n1;
    for (int i = 0; i < n1; i++) {
        scanf("%d", &niz1[i]);
    }
    for (int i = 0; i < n1; i++) {
        niz2[i] = niz1[i];
    }
    // Opcija 1: Od prvog prema zadnjem
    int pocetni_vagon1 = niz1[0];  // Poèetni vagon
    int preostali_vagoni1 = 1;  // Prvi vagon uvijek ostaje
    int odabrani_vagoni1[500];
    odabrani_vagoni1[0] = niz1[0];  // Poèetni vagon se dodaje
    for (int i = 1; i < n1; i++) {
        if (niz1[i] >= pocetni_vagon1) {
            odabrani_vagoni1[preostali_vagoni1++] = niz1[i];
            pocetni_vagon1 = niz1[i];  // Ažuriramo poèetni vagon (posljednji odabran vagon)
        }
    }
    // Opcija 2: Od zadnjeg prema prvom
    int posljednji_vagon2 = niz2[n2 - 1];  // Posljednji vagon
    int preostali_vagoni2 = 1;  // Posljednji vagon uvijek ostaje
    int odabrani_vagoni2[500];
    odabrani_vagoni2[0] = niz2[n2 - 1];  // Posljednji vagon se dodaje
    for (int i = n2 - 2; i >= 0; i--) {
        if (niz2[i] >= posljednji_vagon2) {
            odabrani_vagoni2[preostali_vagoni2++] = niz2[i];
            posljednji_vagon2 = niz2[i];  // Ažuriramo posljednji vagon (posljednji odabran vagon)
        }
    }
    if (preostali_vagoni1 >= preostali_vagoni2) {
        printf("Ostaje %d vagona: ", preostali_vagoni1);
        for (int i = 0; i < preostali_vagoni1; i++) {
            printf("%d ", odabrani_vagoni1[i]);
        }
    }
    else {
        printf("Ostaje %d vagona: ", preostali_vagoni2);
        for (int i = preostali_vagoni2 - 1; i >= 0; i--) {
            printf("%d ", odabrani_vagoni2[i]);
        }
    }
    return 0;
}
