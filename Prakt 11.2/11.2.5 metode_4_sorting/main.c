#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10

struct Siswa {
    int NO;
    char Nama[50];
    int Nilai;
};

void insertionSort(struct Siswa *siswa);
void selectionSort(struct Siswa *siswa);
void bubbleSort(struct Siswa *siswa);
void shellSort(struct Siswa *siswa);
void tampil(struct Siswa *siswa, int n);
void allmenu(int menuSort);
void mode_urut();

int menuSort = 0, mode = 0;

int main() {
    while (menuSort != 5) {
        puts("\n\nMENU METODE SORTING");
        printf("1. Insertion Sort\n2. Selection Sort\n3. Shell Sort\n4. Bubble Sort\n5. Exit");
        printf("\nPilihan anda [1/2/3/4/5] : ");
        scanf("%d", &menuSort);

        if (menuSort == 5) {
            exit(0);
        } else if (menuSort < 1 || menuSort > 5) {
            printf("Menu yang dimasukkan salah!\n");
        } else {
            mode_urut();
            if (mode < 1 || mode > 5) {
                printf("Menu yang dimasukkan salah!\n");
            } else {
                allmenu(menuSort);
            }
        }
    }
    return 0;
}


void shellSort(struct Siswa *siswa) {
    int k, i, j, iterasi = 1;
    struct Siswa temp;
    puts("");
    for (k = MAX/2; k > 0; k = k/2) {
        for (i = k; i < MAX; i++) {
            temp = siswa[i];
            j = i;
            while (j >= k && ((mode == 1 && siswa[j-k].NO > temp.NO) || (mode == 2 && siswa[j-k].NO < temp.NO) || (mode == 3 && siswa[j-k].NO > temp.NO) || (mode == 4 && strcmp(siswa[j-k].Nama, temp.Nama) > 0) || (mode == 5 && siswa[j-k].Nilai > temp.Nilai))) {
                siswa[j] = siswa[j-k];
                j -= k;
            }
            siswa[j] = temp;
        }
        /*
        printf("Iterasi %d: ", iterasi++);
        tampil(siswa, MAX);
        printf("\n");
        */
    }
}

void insertionSort(struct Siswa *siswa) {
    int i, j, iterasi = 1;
    struct Siswa temp;
    puts("");

    for (i = 1; i < MAX; i++) {
        temp = siswa[i];
        j = i - 1;

        while (j >= 0 && ((mode == 1 && siswa[j].NO > temp.NO) || (mode == 2 && siswa[j].NO < temp.NO) || (mode == 3 && siswa[j].NO > temp.NO) || (mode == 4 && strcmp(siswa[j].Nama, temp.Nama) > 0) || (mode == 5 && siswa[j].Nilai > temp.Nilai))) {
            siswa[j+1] = siswa[j];
            j--;
        }

        siswa[j+1] = temp;

        /*
        printf("Iterasi %d: ", iterasi++);
        tampil(siswa, MAX);
        printf("\n");
        */
    }
}

void selectionSort(struct Siswa *siswa) {
    int i, j, min;
    struct Siswa temp;
    for (i = 0; i < MAX - 1; i++) {
        min = i;
        for (j = i + 1; j < MAX; j++) {
            if ((mode == 1 && siswa[j].NO < siswa[min].NO) || (mode == 2 && siswa[j].NO > siswa[min].NO) || (mode == 3 && siswa[j].Nilai < siswa[min].Nilai) || (mode == 4 && strcmp(siswa[j].Nama, siswa[min].Nama) < 0)) {
                min = j;
            }
        }
        if (min != i) {
            temp = siswa[i];
            siswa[i] = siswa[min];
            siswa[min] = temp;
        }
        /*
        printf("Iterasi %d: ", i+1);
        tampil(siswa, MAX);
        printf("\n");
        */
    }
}




void bubbleSort(struct Siswa *siswa) {
    int i, j, iterasi = 1;
    struct Siswa temp;
    puts("");
    for (i = 0; i < MAX-1; i++) {
        for (j = 0; j < MAX-i-1; j++) {
            if ((mode == 1 && siswa[j].NO > siswa[j+1].NO) ||
                (mode == 2 && siswa[j].NO < siswa[j+1].NO) ||
                (mode == 3 && siswa[j].NO > siswa[j+1].NO) ||
                (mode == 4 && strcmp(siswa[j].Nama, siswa[j+1].Nama) > 0) ||
                (mode == 5 && siswa[j].Nilai > siswa[j+1].Nilai)) {
                temp = siswa[j];
                siswa[j] = siswa[j+1];
                siswa[j+1] = temp;
            }
        }
        /*
        printf("Iterasi %d: ", iterasi++);
        tampil(siswa, MAX);
        printf("\n");
        */
    }
}

void tukar(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void mode_urut() {
    printf("\nPengurutan yang dipilih:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("3. SortByNO\n");
    printf("4. SortByNama\n");
    printf("5. SortByNilai\n");

    printf("Pilihan anda [1/2/3/4/5]: ");
    scanf("%d", &mode);
}

void tampil(struct Siswa *siswa, int n)
{
    printf("| %-3s | %-20s | %-5s |\n", "NO", "Nama", "Nilai");
    printf("+-----+----------------------+-------+\n");
    for (int i = 0; i < n; i++) {
        printf("| %3d | %-20s | %-5d |\n", siswa[i].NO, siswa[i].Nama, siswa[i].Nilai);
    }
    printf("+-----+----------------------+-------+\n");
}

void allmenu(int menuSort){
    struct Siswa data[MAX] = {
        {5, "Ade", 92},
        {4, "Budi", 94},
        {7, "Cici", 87},
        {8, "Dodi", 85},
        {2, "Eka", 86},
        {3, "Fajar", 82},
        {1, "Gita", 83},
        {6, "Hana", 89},
        {10, "Ira", 95},
        {9, "Jono", 93}
    };

    switch (menuSort) {
            case 1:
                system("cls");
                insertionSort(data);
                puts("\nShell Sort :\n");
                tampil(data,MAX);
                puts("");
                break;
            case 2:
                system("cls");
                selectionSort(data);
                puts("\nShell Sort :\n");
                tampil(data,MAX);
                puts("");
                break;
            case 3:
                system("cls");
                shellSort(data);
                puts("\nShell Sort :\n");
                tampil(data,MAX);
                puts("");
                break;
            case 4:
                system("cls");
                bubbleSort(data);
                puts("\nShell Sort :\n");
                tampil(data,MAX);
                puts("");
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid menu!\n");
                return 1;
    }
}
