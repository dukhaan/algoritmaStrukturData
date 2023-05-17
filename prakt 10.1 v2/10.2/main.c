#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Siswa {
    int NO;
    char Nama[50];
    char Nilai;
};

void insertion(int x[], int submenu);
void selection(int x[], int submenu);
void tukar(int *a, int *b);
void tampil(struct Siswa *siswa, int n);
void allmenu(int menu1, int menu2);

int menu1 = 0, menu2 = 0;

int main(){
    while (menu1 != 3){
        puts("\n\nMENU METODE SORTING");
        printf("1. Insertion Sort\n2. Selection Sort\n3. Exit");
        printf("\nPilihan anda [1/2/3] : ");
        scanf("%d", &menu1);

        if (menu1 == 3){
            exit(0);
        }else if (menu1 < 1 || menu1 > 2){
            printf("Menu yang dimasukkan salah!\n");
        }else{
            puts("\nMENU METODE SORTING");
            printf("1. Ascending\n2. Descending\n");
            printf("Pilihan anda [1/2] : ");
            scanf("%d", &menu2);
            if (menu2 < 1 || menu2 > 2){
                printf("Menu yang dimasukkan salah!\n");
            }else{
                allmenu(menu1, menu2);
            }
        }
    }
    return 0;
}

void insertion(int x[], int submenu){
    int i, j, key;
    for (i = 1; i < MAX; i++) {
        key = x[i];
        j = i - 1;

        while (j >= 0 && ((submenu == 1 && x[j] > key) || (submenu == 2 && x[j] < key))) {
            x[j + 1] = x[j];
            j--;
        }
        x[j + 1] = key;
    }
}

void selection(int x[], int submenu){
    int i, j, min, temp;
    for (i = 0; i < MAX; i++) {
        min = i;
        for (j = i + 1; j < MAX; j++) {
            if ((submenu == 1 && x[j] < x[min]) || (submenu == 2 && x[j] > x[min])) {
                min = j;
            }
        }
        if (min != i) {
            tukar(&x[i], &x[min]);
        }
    }
}

void tukar(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(struct Siswa *siswa, int n)
{
    printf("| %-3s | %-20s | %-5s |\n", "NO", "Nama", "Nilai");
    printf("+-----+----------------------+-------+\n");
    for (int i = 0; i < n; i++) {
        printf("| %3d | %-20s | %-5c |\n", siswa[i].NO, siswa[i].Nama, siswa[i].Nilai);
    }
    printf("+-----+----------------------+-------+\n");
}

void allmenu(int menu1, int menu2){
    struct Siswa data[MAX] = {
        {1, "Ade", 'A'},
        {2, "Budi", 'B'},
        {3, "Cici", 'C'},
        {4, "Dodi", 'D'},
        {5, "Eka", 'E'},
        {6, "Fajar", 'A'},
        {7, "Gita", 'B'},
        {8, "Hana", 'C'},
        {9, "Ira", 'D'},
        {10, "Jono", 'E'}
    };
    printf("\nData sebelum diurutkan:\n");
    tampil(data, MAX);

    int nilai[MAX];
    for (int i = 0; i < MAX; i++){
        nilai[i] = data[i].Nilai;
    }if (menu1 == 1) {
        insertion(nilai, menu2);
    } else {
        selection(nilai, menu2);
    }for (int i = 0; i < MAX; i++) {
        data[i].Nilai = nilai[i];
    }
    printf("\nData setelah diurutkan:\n");
    tampil(data, MAX);
}
