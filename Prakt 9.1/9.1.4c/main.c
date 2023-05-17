#include <stdio.h>
#include <stdlib.h>

int factorial(int n, int result);

int main() {
    int n, result = 1;

    printf("Masukkan bilangan bulat positif: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Maaf, faktorial hanya dapat dihitung untuk bilangan bulat positif.\n");
    } else {
        printf("Faktorial dari %d adalah %d.\n", n, factorial(n, result));
    }

    return 0;
}

int factorial(int n, int result) {
    if (n == 0 || n == 1) {
        return result;
    } else {
        return factorial(n - 1, result * n);
    }
}
