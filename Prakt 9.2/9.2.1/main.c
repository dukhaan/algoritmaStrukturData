#include <stdio.h>
#include <stdlib.h>

int fpb(int a, int b);

int main() {
    int a, b;
    printf("Masukkan bilangan pertama: ");
    scanf("%d", &a);
    printf("Masukkan bilangan kedua: ");
    scanf("%d", &b);
    printf("FPB dari %d dan %d adalah %d", a, b, fpb(a, b));
    return 0;
}

int fpb(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return fpb(b, a % b);
    }
}

