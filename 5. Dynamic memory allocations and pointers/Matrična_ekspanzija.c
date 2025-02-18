#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
* Upisuju se dimenzije matrice. Zatim se upisuje k ekspanzija. 
Nakon toga k reda i stupaca ekspanzije te se na tom mjestu te na svim mjestima oko njega 
(gore lijevo, gore, gore desno, desno, dolje desno, dolje, dolje lijevo i lijevo) stavlja 'X'.
* Napomena: Memorija se alocira dinamički
Test case #1
Ulaz:
4 6 5
2 5
2 5
1 5
1 5
2 4

Izlaz:
..xxxx
...xxx
..xxxx
......
*/
void ekspanzija(char** mat, int Er, int Es) {
    if (mat[Er - 1][Es - 1] == '.') {
        mat[Er - 1][Es - 1] = 'x';
    }
    else if (mat[Er - 1][Es - 1] == 'x') {
        if (Er - 1 == 0) {
            mat[Er][Es - 2] = 'x';
            mat[Er][Es] = 'x';
        }
        else if (Es - 1 == 0) {
            mat[Er - 2][Es] = 'x';
            mat[Er][Es] = 'x';
        }
        else {
            mat[Er - 2][Es - 2] = 'x';
            mat[Er][Es - 2] = 'x';
            mat[Er - 2][Es] = 'x';
            mat[Er][Es] = 'x';
        }
    }
}

int main()
{
    int n, m, k, Er, Es;
    char** mat;
    scanf("%d %d %d", &n, &m, &k);
    mat = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        mat[i] = (char*)malloc(m * sizeof(char));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = '.';
        }
    }
    for (int t = 0; t < k; t++) {
        scanf("%d %d", &Er, &Es);
        ekspanzija(mat, Er, Es);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
    return 0;
}