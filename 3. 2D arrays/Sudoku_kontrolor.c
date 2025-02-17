#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
Napravi program koji æe provjeriti je li matrica 9x9 sudoku, odnosno jesu li svi brojevi 
1-9 u svakom retku, stupcu i 3x3 kvadraticu
*/

#define SIZE 9

int main() {
    int sudoku[SIZE][SIZE];
    int greskaRed = -1, greskaStupac = -1, greskaKvadrat = -1;
    int pojavljen[SIZE + 1]; // Niz za praæenje brojeva
    int ispravna = 1;       // Varijabla za praæenje ispravnosti

    // Unos Sudoku matrice (po jedan redak od 9 znamenki)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%1d", &sudoku[i][j]); // Èitanje jednog broja po redu
        }
    }

    // Provjera redaka
    for (int i = 0; i < SIZE && ispravna; i++) {
        for (int k = 0; k <= SIZE; k++) pojavljen[k] = 0; // Reset praæenja
        for (int j = 0; j < SIZE; j++) {
            int broj = sudoku[i][j];
            if (broj < 1 || broj > SIZE || pojavljen[broj]) {
                greskaRed = i + 1;
                greskaStupac = j + 1;
                ispravna = 0;
                break;
            }
            pojavljen[broj] = 1;
        }
    }

    // Provjera stupaca
    for (int j = 0; j < SIZE && ispravna; j++) {
        for (int k = 0; k <= SIZE; k++) pojavljen[k] = 0; // Reset praæenja
        for (int i = 0; i < SIZE; i++) {
            int broj = sudoku[i][j];
            if (broj < 1 || broj > SIZE || pojavljen[broj]) {
                greskaStupac = j + 1;
                greskaRed = i + 1;
                ispravna = 0;
                break;
            }
            pojavljen[broj] = 1;
        }
    }

    // Provjera 3x3 kvadrata
    for (int startRed = 0; startRed < SIZE && ispravna; startRed += 3) {
        for (int startStupac = 0; startStupac < SIZE && ispravna; startStupac += 3) {
            for (int k = 0; k <= SIZE; k++) pojavljen[k] = 0; // Reset praæenja
            for (int i = startRed; i < startRed + 3; i++) {
                for (int j = startStupac; j < startStupac + 3; j++) {
                    int broj = sudoku[i][j];
                    if (broj < 1 || broj > SIZE || pojavljen[broj]) {
                        greskaKvadrat = (startRed / 3) * 3 + (startStupac / 3) + 1;
                        greskaRed = i + 1;
                        greskaStupac = j + 1;
                        ispravna = 0;
                        break;
                    }
                    pojavljen[broj] = 1;
                }
                if (!ispravna) break;
            }
        }
    }

    // Ispis rezultata
    if (ispravna) {
        printf("Ispravno!\n");
    }
    else {
        printf("Neispravno! Greska u %d. redak, %d. stupac, %d. kvadrat.\n", greskaRed, greskaStupac, greskaKvadrat);
    }

    return 0;
}
