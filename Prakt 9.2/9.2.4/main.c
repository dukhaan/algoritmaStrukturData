#include <stdio.h>
#include <stdlib.h>

int iterasi(int n);
int rekursi(int n);
void menu();

int main() {
    int n, menu1;

    while (menu1 != 3) {
        menu();
        scanf("%d", &menu1);

        switch (menu1) {
            case 1:
                printf("Masukkan jumlah bilangan: ");
                scanf("%d", &n);
                printf("Deret Fibonacci:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", iterasi(i));
                }
                printf("\n");
                break;
            case 2:
                printf("Masukkan jumlah bilangan: ");
                scanf("%d", &n);
                printf("Deret Fibonacci:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", rekursi(i));
                }
                printf("\n");
                break;
            case 3:
                printf("Keluar\n");
                break;
            default:
                printf("Input tidak valid!\n");
        }
    }

    return 0;
}

void menu() {
    printf("Menu:\n");
    printf("1. Deret Fibonacci dengan iterasi\n");
    printf("2. Deret Fibonacci dengan rekursi\n");
    printf("3. Keluar\n");
    printf("Pilih menu: ");
}

int iterasi(int n) {
    int f1 = 0, f2 = 1, temp;

    if (n == 0) {
        return f1;
    }

    for (int i = 1; i < n; i++) {
        temp = f2;
        f2 = f1 + f2;
        f1 = temp;
    }

    return f2;
}

int rekursi(int n) {
    if (n <= 1) {
        return n;
    }
    return rekursi(n - 1) + rekursi(n - 2);
}
