#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

struct Siswa {
    int NO;
    char Nama[50];
    int Nilai;
};

void bubbleSort(struct Siswa A[]);
void tukar(int *a, int *b);
void tampil(struct Siswa *siswa, int n);
void mode_urut();
void allmenu(int menuSort);
int menuSort = 0, mode = 0;

int main(){
    while (menuSort != 2){
        puts("\n\nMENU METODE SORTING");
        printf("1. Bubble Sort\n2. Exit");
        printf("\nPilihan anda [1/2] : ");
        scanf("%d", &menuSort);

        if (menuSort == 3){
            exit(0);
        }else if (menuSort < 1 || menuSort > 2){
            printf("Menu yang dimasukkan salah!\n");
        }else{
            mode_urut();
            if (mode < 1 || mode > 5){
                printf("Menu yang dimasukkan salah!\n");
            }else{
                allmenu(menuSort);
            }
        }
    }
    return 0;
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
                bubbleSort(data);
                puts("\nBubble Sort :\n");
                tampil(data,MAX);
                puts("");
                break;
            case 2:
                exit(0);
                break;
            default:
                printf("Invalid menu!\n");
                return 1;
    }
}
