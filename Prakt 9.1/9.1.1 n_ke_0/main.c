#include <stdio.h>
#include <stdlib.h>

void tampil(int n);

int main() {
    int n;
    printf("Masukkan nilai n: ");
    scanf("%d", &n);
    printf("Angka dari %d ke 0 adalah:\n", n);
    tampil(n);
    return 0;
}

void tampil(int n) {
    if (n < 0) {
        return;
    }
    printf("%d ", n);
    tampil(n - 1);
}
