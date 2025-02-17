#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
Sortiranje matrice po retcima, zatim po stupcima
*/

#define MAX 100
int main()
{
	int n, m, mat[MAX][MAX], mat2[MAX][MAX];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat2[i][j] = mat[i][j];
		}
	}
	int bilaZamjena;
	do {
		bilaZamjena = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m - 1; j++) {
				if (mat[i][j] > mat[i][j + 1])
				{
					int temp = mat[i][j];
					mat[i][j] = mat[i][j + 1];
					mat[i][j + 1]  = temp;
					bilaZamjena = 1;
				}
			}
		}
	} while (bilaZamjena);
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

	int bilaZamjena2;
	do {
		bilaZamjena2 = 0;
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n - 1; i++) {
				if (mat2[i][j] > mat2[i + 1][j])
				{
					int temp = mat2[i][j];
					mat2[i][j] = mat2[i + 1][j];
					mat2[i + 1][j] = temp;
					bilaZamjena2 = 1;
				}
			}
		}
	} while (bilaZamjena2);
	printf("\n");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", mat2[i][j]);
		}
		printf("\n");
	}
	return 0;
}

