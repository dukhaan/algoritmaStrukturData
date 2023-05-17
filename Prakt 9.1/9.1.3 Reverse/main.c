#include <stdio.h>

void pembalik(char kalimat[], int panjang);

int main() {
    char kalimat[100];
    printf("Masukkan kalimat: ");
    scanf("%[^\n]s", kalimat); // membaca input kalimat dari pengguna

    pembalik(kalimat, strlen(kalimat)); // memanggil fungsi rekursi untuk membalikkan kalimat

    printf("Kalimat yang dibalik: %s\n", kalimat); // mencetak hasil kalimat yang sudah dibalik

    return 0;
}

void pembalik(char kalimat[], int panjang) {
    if (panjang <= 1) { // basis: jika panjang kalimat sudah <= 1, tidak perlu dibalikkan lagi
        return;
    } else { // rekursif: menukar posisi karakter awal dan akhir, lalu memanggil dirinya sendiri
        char temp = kalimat[0];
        kalimat[0] = kalimat[panjang - 1];
        kalimat[panjang - 1] = temp;
        pembalik(kalimat + 1, panjang - 2); // menggunakan pointer untuk mengakses karakter selain awal dan akhir
    }
}
