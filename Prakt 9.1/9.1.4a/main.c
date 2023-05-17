#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main() {
    int n;
    int hasil = factorial(n);

    printf("Masukkan bilangan bulat positif: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Input salah. Bilangan harus positif.\n");
    }else{
        int hasil = factorial(n);
        printf("Faktorial dari %d adalah %d.\n", n, hasil);
    }
}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
