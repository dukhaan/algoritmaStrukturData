#include <stdio.h>
#include <stdlib.h>

void tampil(int n);

int main() {
    int n;
    printf("Masukkan nilai n: ");
    scanf("%d", &n);
    printf("Angka dari 0 ke %d adalah:\n", n);
    tampil(n);
    return 0;
}

void tampil(int n) {
    if (n < 0) {
        return;
    }
    tampil(n - 1);
    printf("%d ", n);
}
