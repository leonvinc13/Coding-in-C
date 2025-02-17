#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
Kada je u predstavljanju kandidata u televizijskoj emisiji Ljubav je na selu ugledao Sandru, 
Kristijan se odmah u nju zaljubio. Pisao je Sandri i ona ga je pozvala kod sebe na farmu. 
No na Kristijanovu nesreću Sandra je pozvala još dva dečka, Denisa i Marina. 
Kako bi vidjela tko je od njih trojice najbolji radnik na farmi Sandra im je zadala zadatak branja 
kukuruza: onaj tko ubere najviše kukuruza u najkraćem vremenu dobit će pusu od Sandre i neće biti 
izbačen s farme; s time da Sandra u ukupnom rezultatu tolerira razliku od 3 kukuruza.
Kristijan vas je zamolio da mu napišete program koji će mu na temelju segmenta kukuruzišta 
(kojeg se domogao kodiranjem snimki fotografiranih svojim dronom) predložiti najbolji red u koji se 
treba stati kako bi osvojio Sandrinu ljubav. Segment je velik 3x20 i u svakom redu u segmentu mogu 
se nalaziti:

·       kukuruz 'I' – za čije branje mu je potrebno 5 sekundi
·       trava '.' – na kojoj nema kukuruza i prolazi se u roku 1 sekunde
·       blato ',' – na kojem nema kukuruza, ali su potrebne 2 sekunde da ga se prohoda
Ukoliko postoje redovi s istim brojem kukuruza koje je moguće ubrati u istom vremenu, 
Kristijan preferira biti u prvom rubnom redu. 
U svakom slučaju red se, kako god izgledao, mora proći od početka do kraja.
NAPOMENA: Segment kukuruza potrebno je pohraniti kao 2D polje.

Test case #1
Primjer ulaza:
IIIIII..IIIIIII,IIII
I,I..I,,III..II,,,II
IIII,IIIIIIIII..IIII

Primjer izlaza:
Pozicioniraj se u 1. red!
*/
#define MAX 20
int main()
{
    char mat[MAX][MAX];
    int brKukuruza[MAX] = { 0 }, vrijeme[MAX] = { 0 };
    int maxKukuruz = 0, minVrijeme = 10000;
    int red;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 20; j++) {
            scanf(" %c", &mat[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 20; j++) {
            if (mat[i][j] == 'I') {
                brKukuruza[i]++;
                vrijeme[i] += 5;
            }
            if (mat[i][j] == '.') {
                vrijeme[i] += 1;
            }
            if (mat[i][j] == ',') {
                vrijeme[i] += 2;
            }
        }
        if (brKukuruza[i] > maxKukuruz) {
            int temp = maxKukuruz;
            maxKukuruz = brKukuruza[i];
            if ((maxKukuruz - temp) > 3) {
                red = i + 1;
            }
        }
        if ((maxKukuruz - temp) <= 3 && vrijeme[i] < minVrijeme) {
            minVrijeme = vrijeme[i];
            red = i + 1;
        }
    }
    printf("Pozicioniraj se u %d. red!", red);
}


