#include <stdio.h>
#include <time.h>

int faktorial(int n);
int permutasi(int n, int r);
int kombinasi(int n, int r);

int main() {
    int n, r;
    time_t t1, t2;
    long int waktukomputasi;

    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    printf("Masukkan nilai r: ");
    scanf("%d", &r);

    time(&t1);
    printf("Permutasi dari %d dan %d adalah: %d\n", n, r, permutasi(n, r));
    time(&t2);
    waktukomputasi = difftime(t2, t1);
    printf("Waktu komputasi untuk menghitung permutasi: %ld detik\n", waktukomputasi);

    time(&t1);
    printf("Kombinasi dari %d dan %d adalah: %d\n", n, r, kombinasi(n, r));
    time(&t2);
    waktukomputasi = difftime(t2, t1);
    printf("Waktu komputasi untuk menghitung kombinasi: %ld detik\n", waktukomputasi);

    return 0;
}

int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * faktorial(n - 1);
    }
}

int permutasi(int n, int r) {
    return faktorial(n) / faktorial(n - r);
}

int kombinasi(int n, int r) {
    return faktorial(n) / (faktorial(r) * faktorial(n - r));
}
