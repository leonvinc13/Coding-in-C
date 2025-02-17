#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*Ana ima niz kriterija prema kojima bira svog idealnog partnera.
Vi ste tu da joj pomognete da si lakše i brže izabere svog idealnog partnera.
Na poèetku je potrebno uèitati Anine kriterije za izbor:
interval za visinu u centimetrima - dva cijela broja u intervalu (50, 250], 
te razlika veæeg i manjeg ne smije biti veæa od 35
interval za težinu u kilogramima - dva cijela broja u intervalu  [50, 100], 
te razlika veæeg i manjeg mora biti veæa od 5
interval za broj godina .- dva cijela broja u intervalu (15, 100), 
te razlika veæeg i manjeg mora biti toèno 5
Za svaki interval koji se uèitava potrebno je tražiti ponovni unos oba cijela broja
iz intervala ukoliko gornja pravila nisu zadovoljena.
Nakon toga potrebno je uèitati cijeli broj N u intervalu (3, 20]. 
Takoðer tražiti ponovni unos ako broj nije u intervalu.
Zatim uèitati N podataka o potencijalnim partnerima: visinu, tezinu i broj godina.
Na kraju programa ispisati koliko partnera odgovara Aninim zahtjevima. 
Partner odgovara zahtjevima ako zadovoljava sva 3 uvjeta.

Test case #1
Primjer ulaza: 
50 85
220 250
50 100
15 20
16 20
16 21
4
225 75 22
225 75 17
219 101 15
175 80 17 

Primjer izlaza:
Nepravilni unos visine!
Nepravilni unos godina!
Nepravilni unos godina!
Prolazi kriterije: 1 osoba.
*/
int main()
{
    int visina_min, visina_max;
    int tezina_min, tezina_max;
    int godine_min, godine_max;
    int n, br = 0, i;
    do {
        scanf("%d %d", &visina_min, &visina_max);
        if (!(visina_min > 50 && visina_max <= 250 && visina_max - visina_min <= 35)) {
            printf("Nepravilni unos visine!\n");
        }
    } while (!(visina_min > 50 && visina_max <= 250 && visina_max - visina_min <= 35));
    do {
        scanf("%d %d", &tezina_min, &tezina_max);
        if (!(tezina_min >= 50 && tezina_max <= 100 && tezina_max - tezina_min > 5)) {
            printf("Nepravilni unos tezine!\n");
        }
    } while (!(tezina_min >= 50 && tezina_max <= 100 && tezina_max - tezina_min > 5));
    do {
        scanf("%d %d", &godine_min, &godine_max);
        if (!(godine_min > 15 && godine_max < 100 && godine_max - godine_min == 5)) {
            printf("Nepravilni unos godina!\n");
        }
    } while (!(godine_min > 15 && godine_max < 100 && godine_max - godine_min == 5));
    do {
        scanf("%d", &n);
        if (!(n > 3 && n <= 20)) {
            printf("Nepravilni unos broja partnera!\n");
        }
    } while (!(n > 3 && n <= 20));
    int visine[20], tezine[20], godine[20];
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &visine[i], &tezine[i], &godine[i]);
        if (visine[i] >= visina_min && visine[i] <= visina_max &&
            tezine[i] >= tezina_min && tezine[i] <= tezina_max &&
            godine[i] >= godine_min && godine[i] <= godine_max) {
            br++;
        }
    }
    if (br == 1) {
        printf("Prolazi kriterije: %d osoba.\n", br);
    }
    else {
        printf("Prolazi kriterije: %d osobe.\n", br);
    }
    return 0;
}

