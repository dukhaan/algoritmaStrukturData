#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int iterasi(int n);
int rekursi(int n);
int rekursi_tail_bantuan(int n, int hasil);
int rekursi_tail(int n);
double waktu();

int main() {
    int n, menu1;
    double waktu_mulai, waktu_selesai;

    printf("Masukkan angka : ");
    scanf("%d", &n);

    while(menu1 != 4){
        printf("\nDaftar Menu:\n");
        printf("1. Iterasi\n2. Rekursi\n3. Rekursi Tail\n4. exit\n");
        printf("Pilih menu : ");
        scanf("%d", &menu1);

        switch (menu1) {
        case 1:
            waktu_mulai = waktu();
            printf("%d! = %d\n", n, iterasi(n));
            waktu_selesai = waktu();
            break;
        case 2:
            waktu_mulai = waktu();
            printf("%d! = %d\n", n, rekursi(n));
            waktu_selesai = waktu();
            break;
        case 3:
            waktu_mulai = waktu();
            printf("%d! = %d\n", n, rekursi_tail(n));
            waktu_selesai = waktu();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid menu1!\n");
            return 1;
        }
        printf("Time elapsed: %.6f seconds\n", waktu_selesai - waktu_mulai);
    }
    return 0;
}

int iterasi(int n) {
    int i, hasil = 1;
    for (i = 1; i <= n; i++) {
        hasil *= i;
    }
    return hasil;
}

int rekursi(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * rekursi(n - 1);
    }
}

int rekursi_tail_bantuan(int n, int hasil) {
    if (n == 0 || n == 1) {
        return hasil;
    } else {
        return rekursi_tail_bantuan(n - 1, n * hasil);
    }
}

int rekursi_tail(int n) {
    return rekursi_tail_bantuan(n, 1);
}

double waktu() {
    return (double)clock() / CLOCKS_PER_SEC;
}
