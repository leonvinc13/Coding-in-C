#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

/*
* Zadatak: Odron na smetlištu
Na smetlištu su naslagane hrpe otpada, pri èemu se njihova visina mjeri u jedinicama. 
Meðutim, zbog nestabilnog tla, može doæi do odrona, gdje se dio otpada s jedne hrpe prelije na susjednu.

Napiši program koji:
Uèita broj hrpa otpada n i prag visinske razlike z koji uzrokuje odron.
Uèita visine n hrpa otpada.
Pronalazi najveæu visinsku razliku izmeðu dvije susjedne hrpe.
Ako je ta razlika veæa ili jednaka zadanoj vrijednosti z, simulira odron tako da se masa s više hrpe prelije 
na nižu prema pravilu:
Novi sadržaj obje hrpe odreðuje se tako da se masa ravnomjernije preraspodijeli.
Visina više hrpe postaje razlika izmeðu ukupne mase i prelivene kolièine.
Visina niže hrpe postaje prelivena kolièina.
Ako nema znaèajnog odrona (maksimalna razlika je manja od z), program ispisuje: Zrak je èist, samo smrdi.
Inaèe, program ispisuje ažurirani niz visina hrpa otpada.

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