#include <stdio.h>
#include <math.h>
#include <time.h>

int prima(int n);
double waktu();

int main() {
    int n;
    printf("Masukkan sebuah angka: ");
    scanf("%d", &n);

    if (prima(n)) {
        printf("%d adalah bilangan prima.\n", n);
    } else {
        printf("%d bukan bilangan prima.\n", n);
    }

    return 0;
}

int prima(int n) {
    int i;

    // Kasus khusus
    if (n <= 1) {
        return 0;
    }

    // Basis rekursif
    if (n == 2) {
        return 1;
    }

    // Kasus rekursif
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

double waktu() {
    return (double) clock() / CLOCKS_PER_SEC;
}
