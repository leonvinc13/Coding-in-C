#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main()
{
    double cijena;
    scanf("%lf", &cijena);
    int novci[] = { 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    int cijena_cents = round(cijena * 100); 
    for (int i = 0; i < 14; i++) {
        int brNov = cijena_cents / novci[i];
        cijena_cents %= novci[i]; 
        if (brNov > 0) {
            printf("%d x %.2f\n", brNov, novci[i] / 100.0); 
        }
    }
    return 0;
}
