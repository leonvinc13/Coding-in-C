#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Zamislite da imate vrt s  fontanom. Fontana radi od 9.00 do 18.00
//Fontana je prazna do 9.00, najviša razina vode je u 15.00 i ponovno prazna u 18.00
//Napiši program koji, ut trenutno vrijeme u satima i minutama, izraèunava i prikazuje razinu vode
//Pretpostavite da razina vode linearno raste i opada
int main()
{
    int sati, minute, vrijeme;
    float razina;
    scanf("%d:%d", &sati, &minute);
    if (sati < 9 || (sati == 18 && minute > 0) || sati > 18) {
        printf("Razina vode: 0.00%%");
        return 0;
    }
    vrijeme = (sati - 9) * 60 + minute;
    if (vrijeme <= 360) {
        razina = (float)vrijeme / 360 * 100;
    }
    else {
        razina = (float)(1080 - (sati * 60 + minute)) / 180 * 100;;
    }
    printf("Razina vode: %.2f%%", razina);
    return 0;
}


