#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Odlučili ste isprogramirati igru Kaladont koju ćete sa svojim prijateljima igrati preko nekog messengera.
Princip igranja igre je sljedeći:
Prijava igrača
Na početku igre igrači se prijavljuju porukama sa svojim imenom uz koji se veže jedinstveni ID.
Format poruke za prijavu je Ime_igrača, dakle igrači šalju samo svoje ime, a ID im se dodjeljuje 
automatski ovisno o redoslijedu prijave (vrijednost najnižeg ID-a je 1, ostale vrijednosti se 
uvećavaju za 1).
Igru može igrati neograničen broj igrača, ali minimalno dva igrača.
Prijava igrača završava unosom riječi "KRAJ".
U slučaju prijave samo jednog igrača potrebno je ispisati poruku "U igri moraju sudjelovati minimalno 
2 igraca. Unesite jos igraca." i obaviti unos još igrača.
Nakon prijave igrača ispisuje se popis igrača i njihovih ID-a u formatu ID_igrača#Ime_igrača.
Početak igre
Igra započinje tako što se od zadnjeg prijavljenog igrača uzimaju zadnja dva slova imena za koja 
igrač s najmanjim ID-jem (prvi prijavljeni igrač) mora smisliti riječ koja počinje tim slovima. 
Zatim drugi igrač mora osmisliti riječ koja počinje sa zadnja dva slova riječi koju je smislio 
prethodni igrač i tako sve dok igra ne završi.
Za svaki skup slova ispisuje se poruka u formatu "N-ti. zadani skup slova je XY."
Osmišljena riječ za svakog igrača šalje se u formatu ID_igrača#Riječ.
Redoslijed igranja igrača je prema njihovom ID-u, dakle prvi, pa drugi, pa treći itd., pa ponovo prvi, 
pa drugi itd.
Kraj igre
Za pojedinog igrača igra završava u slučaju da igrač ne može smisliti riječ koja počinje zadanim 
slovima te u tom slučaju šalje poruku "Ne znam". Igra se nastavlja za preostale igrače, a riječ 
pokušava smisliti idući igrač.
Igra je gotova kada za zadani par slova svi igrači, osim igrača koji je zadao par slova, pošalju 
poruku "Ne znam". U tom slučaju pobjednik je osoba koja je osmislila riječ iz koje je uzet taj par slova.
Na kraju igre ispisuje se poruka "Pobjednik je: IME_OSOBE". Ime osobe potrebno je ispisati velikim 
slovima.

Test case #1
Ulaz: 
Marko
KRAJ
KRAJ
Pero
KRAJ
1#Romobil
2#Iluzija
1#Jabuka
2#Kaladont
1#Ne znam

Izlaz:
U igri moraju sudjelovati minimalno 2 igraca. Unesite jos igraca.
U igri moraju sudjelovati minimalno 2 igraca. Unesite jos igraca.
Igru igraju:
1#Marko
2#Pero

1. zadani skup slova je RO.
2. zadani skup slova je IL.
3. zadani skup slova je JA.
4. zadani skup slova je KA.
5. zadani skup slova je NT.

Pobjednik je: PERO

*/


#define MAX_IGRACA 50
#define MAX_IME 100

int main() {
    int brIgraca = 0;
    char igrac[MAX_IGRACA][MAX_IME + 1];
    char unos[MAX_IME + 1];
    while (1) {
        scanf("%s", unos);
        if (strcmp(unos, "KRAJ") == 0) {
            if (brIgraca < 2) {
                printf("U igri moraju sudjelovati minimalno 2 igraca. Unesite jos igraca.\n");
                continue;
            }
            else {
                break;
            }
        }
        strcpy(igrac[brIgraca], unos);
        brIgraca++;
    }
    printf("\nIgru igraju:\n");
    for (int i = 0; i < brIgraca; i++) {
        printf("%d#%s\n", i + 1, igrac[i]);
    }
    printf("\n");
    char poruka[MAX_IME + 1];
    char rijec[MAX_IME + 1];
    char dio[2 + 1];
    int broj;
    int ostalo = brIgraca;
    int redni = 1;
    while (ostalo > 1) {
        if (redni == 1) {
            dio[0] = igrac[brIgraca - 1][strlen(igrac[brIgraca - 1]) - 2];
            dio[1] = igrac[brIgraca - 1][strlen(igrac[brIgraca - 1]) - 1];
            dio[2] = '\0';
        }
        if (strcmp(rijec, "Ne znam") != 0) {
            _strupr(dio);
            printf("%d. zadani skup slova je %s.\n", redni, dio);
        }
        getchar();
        scanf("%[^\n]", poruka);
        sscanf(poruka, "%d#%[^\n]", &broj, rijec);
        if (strcmp(rijec, "Ne znam") == 0) {
            ostalo--;
            strcpy(igrac[broj - 1], "Izgubio");
            continue;
        }
        else {
            dio[0] = rijec[strlen(rijec) - 2];
            dio[1] = rijec[strlen(rijec) - 1];
            dio[2] = '\0';
        }
        redni++;
    }
    printf("\n");
    for (int i = 0; i < brIgraca; i++) {
        if (strcmp(igrac[i], "Izgubio") != 0) {
            printf("Pobjednik je: %s", _strupr(igrac[i]));
        }
    }
    return 0;
}
