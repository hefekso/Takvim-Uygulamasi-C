#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define KIRMIZI "\033[31m" // kirmizi rengi ayarladim
#define RESET   "\033[0m"  // normal renk

void Zeller(int y) {
    int ocak[31] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
    int subat[29] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29 };
    int mart[31] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
    int nisan[30] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 };
    int mayis[31] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
    int haziran[30] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 };
    int temmuz[31] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
    int agustos[31] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
    int eylul[30] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 };
    int ekim[31] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };
    int kasim[30] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 };
    int aralik[31] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 };

    int artik_yil = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 1 : 0;

    int* aylar[12] = { ocak, subat, mart, nisan, mayis, haziran, temmuz, agustos, eylul, ekim, kasim, aralik };
    const char* ay_isimleri[12] = { "OCAK", "SUBAT", "MART", "NISAN", "MAYIS", "HAZIRAN", "TEMMUZ", "AGUSTOS", "EYLUL", "EKIM", "KASIM", "ARALIK" };
    int gun_sayilari[12] = { 31, (artik_yil ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    system("cls");
    printf("\t\t %d YILI TAKVIMI \n", y);

    for (int ay_index = 0; ay_index < 12; ay_index++) {
        int q = 1;
        int m = ay_index + 1;
        int hesaplanan_yil = y;

        if (m == 1 || m == 2) {
            m += 12;
            hesaplanan_yil -= 1;
        }

        int K = hesaplanan_yil % 100;
        int J = hesaplanan_yil / 100;

        int h = (q + (13 * (m + 1) / 5) + K + (K / 4) + (J / 4) - (2 * J)) % 7;
        if (h < 0) h += 7;

        int baslangic_sutunu = (h + 5) % 7;

        printf("|-------------------------------------------------------------|\n\n");
        printf("\t\t %s\n", ay_isimleri[ay_index]);
        printf("Pzt\tSal\tCar\tPer\tCum\t" KIRMIZI "Cmt\tPaz" RESET "\n");

        for (int bosluk = 0; bosluk < baslangic_sutunu; bosluk++) {
            printf("\t");
        }

        int mevcut_sutun = baslangic_sutunu;
        for (int i = 0; i < gun_sayilari[ay_index]; i++) {
            if (mevcut_sutun == 5 || mevcut_sutun == 6) {
                printf(KIRMIZI "%d\t" RESET, aylar[ay_index][i]);
            }
            else {
                printf("%d\t", aylar[ay_index][i]);
            }

            mevcut_sutun++;
            if (mevcut_sutun == 7) {
                printf("\n");
                mevcut_sutun = 0;
            }
        }
        printf("\n\n");
    }
}

int main() {
    char tus, tus2;
    int yil;

    system(" ");

    while (1) {
        while (1) {
            system("cls");

            int i = 0, j = 0, a = 0;
            printf("\n\n\n\n\t\t\t\t%c", 201);

            for (i; i < 50; i++) {
                printf("%c", 205);
            }
            printf("%c\n", 187);

            for (j; j < 2; j++) {
                printf("\t\t\t\t%c", 186);
                printf("%49s %c\n", " ", 186);
            }

            printf("\t\t\t\t%c                 TAKVIM PROGRAMI                  %c\n", 186, 186);
            printf("\t\t\t\t%c%50s%c\n", 186, " ", 186);

            for (j; j < 4; j++) {
                printf("\t\t\t\t%c", 186);
                printf("%49s %c\n", " ", 186);
            }

            printf("\t\t\t\t%c     Devam etmek icin D veya d tusuna basiniz     %c\n", 186, 186);
            printf("\t\t\t\t%c%50s%c\n", 186, " ", 186);
            printf("\t\t\t\t%c          CIKIS icin ESC tusuna basiniz           %c\n", 186, 186);
            printf("\t\t\t\t%c%50s%c\n", 186, " ", 186);

            for (j; j < 6; j++) {
                printf("\t\t\t\t%c", 186);
                printf("%49s %c\n", " ", 186);
            }

            printf("\t\t\t\t%c", 200);
            for (a; a < 50; a++) {
                printf("%c", 205);
            }
            printf("%c\n", 188);

            tus = _getch();
            if (tus == 68 || tus == 100) {
                break;
            }
            else if (tus == 27) {
                system("cls");
                printf("\n Cikmak istediginizden emin misiniz?   (E/H)");
                tus2 = _getch();

                if (tus2 == 69 || tus2 == 101) {
                    return 0;
                }
                continue;
            }
        }

        system("cls");
        printf("\n\n\n\n%50s TAKVIM PROGRAMI \n", " ");
        printf("%35s ----------------------------------------- \n\n\n\n", " ");
        printf("%35s Takvim yilini giriniz\n\n %35s ", " ", " ");
        scanf_s("%d", &yil);

        while (yil > 2090 || yil < 1910) {
            system("cls");
            printf("\n\n\n\n%50s TAKVIM PROGRAMI \n", " ");
            printf("%35s ----------------------------------------- \n\n\n\n", " ");
            printf("%35s Lutfen 1910 - 2090 arasi bir yil giriniz!\n\n%35s", " ", " ");
            scanf_s("%d", &yil);
        }

        Zeller(yil);

        printf("\t\tTekrar denemek icin bir tusa basiniz\n");
        printf("\t\tCikmak icin ESC tusuna basiniz\n");
        tus = _getch();

        if (tus == 27) {
            system("cls");
            printf("\n Cikmak istediginizden emin misiniz?   (E/H)");
            tus2 = _getch();

            if (tus2 == 69 || tus2 == 101) {
                return 0;
            }
        }
    }
    return 0;
}
