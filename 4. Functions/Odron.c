#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

/*
* Zadatak: Odron na smetli�tu
Na smetli�tu su naslagane hrpe otpada, pri �emu se njihova visina mjeri u jedinicama. 
Me�utim, zbog nestabilnog tla, mo�e do�i do odrona, gdje se dio otpada s jedne hrpe prelije na susjednu.

Napi�i program koji:
U�ita broj hrpa otpada n i prag visinske razlike z koji uzrokuje odron.
U�ita visine n hrpa otpada.
Pronalazi najve�u visinsku razliku izme�u dvije susjedne hrpe.
Ako je ta razlika ve�a ili jednaka zadanoj vrijednosti z, simulira odron tako da se masa s vi�e hrpe prelije 
na ni�u prema pravilu:
Novi sadr�aj obje hrpe odre�uje se tako da se masa ravnomjernije preraspodijeli.
Visina vi�e hrpe postaje razlika izme�u ukupne mase i prelivene koli�ine.
Visina ni�e hrpe postaje prelivena koli�ina.
Ako nema zna�ajnog odrona (maksimalna razlika je manja od z), program ispisuje: Zrak je �ist, samo smrdi.
Ina�e, program ispisuje a�urirani niz visina hrpa otpada.

Test case #1
Ulaz: 
10 5
1 2 5 10 8 8 8 8 8 8

Izlaz:
1 2 7 8 8 8 8 8 8 8

Test case #2
Ulaz: 
10 5
7 6 7 6 8 8 8 8 8 8

Izlaz:
Zrak je cist, samo smrdi.
*/
#define MAX 100

void izmjeniNiz(int n, int niz2[], int odron, int preljev) {
    int preliti = 0;
    for (int i = 0; i < n; i++) {
        if (i == odron) {
            preliti = (niz2[i + 1] + niz2[i]) / 2;
            if (niz2[i] > niz2[i + 1]) {
                niz2[odron] = (niz2[i] + niz2[i + 1]) - preliti;
                niz2[preljev] = preliti;
            }
            if (niz2[i] < niz2[i + 1]) {
                int ukupno = niz2[i] + niz2[i + 1];
                niz2[odron] = preliti;
                niz2[preljev] = ukupno - preliti;
            }
        }
    }
}

int main()
{
    int n, z, niz[MAX];
    int maxRazlika = 0, razlika = 0;
    int mjestoOdrona, mjestoPreljeva;
    scanf("%d %d", &n, &z);
    for (int i = 0; i < n; i++) {
        scanf("%d", &niz[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        razlika = 0;
        razlika = abs(niz[i] - niz[i + 1]);
        if (razlika > maxRazlika) {
            maxRazlika = razlika;
            mjestoOdrona = i;
            mjestoPreljeva = i + 1;
        }
    }
    izmjeniNiz(n, niz, mjestoOdrona, mjestoPreljeva);
    if (maxRazlika >= z) {
        for (int i = 0; i < n; i++) {
            printf("%d ", niz[i]);
        }
    }
    else {
        printf("Zrak je cist, samo smrdi.");
    }
}