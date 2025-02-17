#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
Preko stranice woohoo.com je mogu�e putovati vlakom besplatno, ali uz mogu�nost da
ste u pogre�nom vagonu koji �e biti izostavljen iz kompozicije. 
To mo�e biti nezgodno ako vam je hitno nekud sti�i, ali mo�e biti odli�no ako vam nije bitno
ho�ete li uspjeti po�i ili ne. 
Radi se naime o sljede�em: woohoo vlakovi polaze s kolodvora samo ukoliko u svakom vagonu, 
po�ev�i bilo sprijeda bilo straga, se u svakom vagonu nalazi vi�e ili jednako putnika nego u prethodnom, 
te nakon �to se svi putnici ukrcaju, vlakovo�a odlu�uje koje vagone treba izbaciti da bi vlak mogao po�i. 
�ini to na na�in da krene od prvog vagona te kad nai�e na vagon koji mu naru�ava slijed 
(ima manje putnika nego u prethodnom), onda taj vagon izbacuje iz kompozicije i pregledava sljede�e 
vagone.
Va� zadatak je napisati program koji �e vlakovo�i pomo�i da izbaci vagone i ispi�e koji vagoni 
ostaju u kompoziciji.
U prvom redu se nalazi broj 1 <= N <= 1000 broj vagona. 
U drugom redu slijedi N brojeva gdje svaki predstavlja broj putnika u pojedinom vagonu. 
Broj putnika u svakom vagonu ne�e biti ve�i od 500.
Napomena: treba uzeti u obzir da su dvije mogu�nosti - da je slijed rastu�i od prvog vagona 
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
    int pocetni_vagon1 = niz1[0];  // Po�etni vagon
    int preostali_vagoni1 = 1;  // Prvi vagon uvijek ostaje
    int odabrani_vagoni1[500];
    odabrani_vagoni1[0] = niz1[0];  // Po�etni vagon se dodaje
    for (int i = 1; i < n1; i++) {
        if (niz1[i] >= pocetni_vagon1) {
            odabrani_vagoni1[preostali_vagoni1++] = niz1[i];
            pocetni_vagon1 = niz1[i];  // A�uriramo po�etni vagon (posljednji odabran vagon)
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
            posljednji_vagon2 = niz2[i];  // A�uriramo posljednji vagon (posljednji odabran vagon)
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
