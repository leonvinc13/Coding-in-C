#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*Tvoja kolegica Katarina pala je prvi kolokvij iz Matematike 1 jer ne razumije izvoðenje 
osnovnih operacija s matricama.
Pomozi joj tako što æeš napraviti program koji zbraja, oduzima, transponira i množi dvije matrice.
Napomena: Prilikom ispisa koristite %4d. Maksimalna dimenzija matrica je 10x10, a minimalna 2x2.

Test case #1
Primjer ulaza:
3x2
5x4
2x4

12 12
-7 0
2 1

1 2 3 4
-5 0 0 2


Primjer izlaza:
Matrice nisu ulancane!
Matrice nisu istih dimenzija, ne mogu se zbrojiti!
Matrice nisu istih dimenzija, ne mogu se oduzimati!
Transponirana prva matrica:
12 -7 2
12 0 1
Transponirana druga matrica:
 1 -5
 2 0
 3 0
 4 2
Umnozak matrica:
-48 24 36 72
-7 -14 -21 -28
-3 4 6 10
*/

#define MAX 20
int main()
{
    int m1, n1, m2, n2;
    int mat1[MAX][MAX], mat2[MAX][MAX];
    int matr[MAX][MAX];
    //upis
    do {
        scanf("%dx%d", &m1, &n1);
        if (m1 > 10 || m1 < 2 || n1>10 || n1 < 2) {
            printf("Unesena je nedozvoljena dimenzija prve matrice!\n");
        }
    } while (m1 > 10 || m1 < 2 || n1>10 || n1 < 2);
    do {
        scanf("%dx%d", &m2, &n2);
        if (m2 > 10 || m2 < 2 || n2>10 || n2 < 2) {
            printf("Unesena je nedozvoljena dimenzija druge matrice!\n");
            continue;
        }
        if (n1 != m2) {
            printf("Matrice nisu ulancane!\n");
        }
    } while (m2 > 10 || m2 < 2 || n2>10 || n2 < 2 || n1 != m2);
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    //zbroji i razlika
    if (m1 != m2 || n1 != n2) {
        printf("Matrice nisu istih dimenzija, ne mogu se zbrojiti!\n");
        printf("Matrice nisu istih dimenzija, ne mogu se oduzimati!\n");
    }

    else {
        //zbroj
        printf("Suma matrica:\n");
        for (int i = 0; i < m1; i++) {
            for (int j = 0; j < n1; j++) {
                matr[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        for (int i = 0; i < m1; i++) {
            for (int j = 0; j < n1; j++) {
                printf("%4d", matr[i][j]);
            }
            printf("\n");
        }

        //razlika
        printf("Razlika matrica:\n");
        for (int i = 0; i < m1; i++) {
            for (int j = 0; j < n1; j++) {
                matr[i][j] = mat1[i][j] - mat2[i][j];
            }
        }
        for (int i = 0; i < m1; i++) {
            for (int j = 0; j < n1; j++) {
                printf("%4d", matr[i][j]);
            }
            printf("\n");
        }
    }

    //transponiranje
    printf("Transponirana prva matrica:\n");
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            matr[i][j] = mat1[j][i];
        }
    }
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            printf("%4d", matr[i][j]);
        }
        printf("\n");
    }
    printf("Transponirana druga matrica:\n");
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            matr[i][j] = mat2[j][i];
        }
    }
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            printf("%4d", matr[i][j]);
        }
        printf("\n");
    }

    //mnozenje
    printf("Umnozak matrica:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            matr[i][j] = 0;
        }
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            for (int k = 0; k < n1; k++) {
                matr[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            printf("%4d", matr[i][j]);
        }
        printf("\n");
    }
    return 0;
}



