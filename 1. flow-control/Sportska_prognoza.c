#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*Ante radi u sportskom tjedniku, i njegov jedini zadatak je da odabere jednu utakmicu
i izbroji koliko je bilo golova (g), udaraca u okvir (o), udaraca prema golu (u), kornera (k),
faulova (f) i kartona (z ili c) , i to za svaku ekipu posebno.
Vi mu trebate napisati program u koji on unosi znak po znak, ovisno što se u utakmici dogodilo,
a program na kraju ispisuje cijeli rezime. Kada treba voditi evidenciju za nesto vezano za domaæu ekipu,
on unosi malo slovo, a za gostujuæu veliko. Npr., kad unese G, to znaci da je gostujuæa ekipa zabila gol.
Ako unese g, znaci da je domaæa ekipa zabila gol. Za kraj unosi znak *.
Broj golova: 1
Udarci prema golu: 3
Udarci u okvir: 2
Korneri: 0
Faulovi: 0
Zuti kartoni: 0
Crveni kartoni: 0
*/

int main()
{
    char znak;
    int br = 0;
    int golD = 0, golG = 0, udarciD = 0, udarciG = 0, udarciOkD = 0, udarciOkG = 0, kornerD = 0,
        kornerG = 0, faulD = 0, faulG = 0, ZKartonD = 0, ZKartonG = 0, CKartonD = 0, CkartonG = 0;
    do {
        scanf(" %c", &znak);

        if (znak == 'g') {
            golD++;
            udarciD++;
            udarciOkD++;
        }
        else if (znak == 'G') {
            golG++;
            udarciG++;
            udarciOkG++;
        }
        else if (znak == 'o') {
            udarciOkD++;
            udarciD++;
        }
        else if (znak == 'O') {
            udarciG++;
            udarciOkG++;
        }
        else if (znak == 'u') {
            udarciD++;
        }
        else if (znak == 'U') {
            udarciG++;
        }
        else if (znak == 'f') {
            faulD++;
        }
        else if (znak == 'F') {
            faulG++;
        }
        else if (znak == 'k') {
            kornerD++;
        }
        else if (znak == 'K') {
            kornerG++;
        }
        else if (znak == 'z') {
            ZKartonD++;
            faulD++;
        }
        else if (znak == 'Z') {
            ZKartonG++;
            faulG++;
        }
        else if (znak == 'c') {
            CKartonD++;
            faulD++;
        }
        else if (znak == 'C') {
            CkartonG++;
            faulG++;
        }
        else if (znak != '*') {
            br++;
        }
    } while (znak != '*' && CKartonD < 5 && CkartonG < 5);
    while (br > 0) {
        printf("Znak nije ispravan!\n");
        br--;
    }
    printf("Utakmica je zavrsila!\nStatistike utakmice:\n\n");
    printf("Domaca ekipa:\n");
    printf("Broj golova: %d\nUdarci prema golu: %d\nUdarci u okvir: %d\nKorneri: %d\nFaulovi: %d\nZuti kartoni: %d\nCrveni kartoni: %d\n\n", golD, udarciD, udarciOkD, kornerD, faulD, ZKartonD, CKartonD);
    printf("Gostujuca ekipa:\n");
    printf("Broj golova: %d\nUdarci prema golu: %d\nUdarci u okvir: %d\nKorneri: %d\nFaulovi: %d\nZuti kartoni: %d\nCrveni kartoni: %d\n\n", golG, udarciG, udarciOkG, kornerG, faulG, ZKartonG, CkartonG);
}
