#include <stdio.h>
#include <stdlib.h>

void deret_fibonacci(int n);

int main() {
    int n;
    printf("Masukkan banyak bilangan: ");
    scanf("%d", &n);
    printf("Deret bilangan Fibonacci:\n");
    deret_fibonacci(n);
    return 0;
}

void deret_fibonacci(int n) {
    int i, t1 = 0, t2 = 1, temp;
    for (i = 1; i <= n; i++) {
        printf("%d ", t1);
        temp = t1 + t2;
        t1 = t2;
        t2 = temp;
    }
}

