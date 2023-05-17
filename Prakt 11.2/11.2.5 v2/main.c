#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10

typedef struct Siswa
{
    int NO;
    char Nama[50];
    int Nilai;
} Siswa;

void insertionSort(Siswa *siswa);
void selectionSort(Siswa *siswa);
void bubbleSort(Siswa *siswa);
void shellSort(Siswa *siswa);
void tukar(int *a, int *b);
void tampil(Siswa *siswa, int n);
void allmenu(Siswa [], int menuSort);
void modeAscDesc();
void modeSorting();

int menuSort = 0, metodeAscDesc = 0, metodeSorting = 0;

int main()
{
    Siswa data[MAX] ={
        {5, "Cici", 92},
        {4, "Budi", 94},
        {7, "Ade", 87},
        {8, "Gita", 85},
        {2, "Fajar", 86},
        {3, "Dodi", 82},
        {1, "Eka", 83},
        {6, "Jono", 89},
        {10, "Ira", 95},
        {9, "Hana", 93}
    };

        tampil(data, MAX);
    while(menuSort != 5){
        puts("\nMENU METODE SORTING");
        printf("1. Insertion Sort\n2. Selection Sort\n3. Shell Sort\n4. Bubble Sort\n5. Exit");
        printf("\nPilihan anda [1/2/3/4/5] : ");
        scanf("%d", &menuSort);

        if (menuSort == 5){
            exit(0);
        }else if (menuSort < 1 || menuSort > 5){
            printf("Menu yang dimasukkan salah!\n");
        }else{
            modeSorting();
            modeAscDesc();
            if (metodeSorting < 1 || metodeSorting > 5)
                printf("Menu yang dimasukkan salah!\n");
            else
                allmenu(data, menuSort);
        }
    }
    return 0;
}

void allmenu(Siswa data[MAX], int menuSort)
{
    switch (menuSort){
    case 1:
        system("cls");
        insertionSort(data);
        puts("Insertion Sort :\n");
        tampil(data, MAX);
        puts("");
        break;
    case 2:
        system("cls");
        selectionSort(data);
        puts("Selecetion Sort :\n");
        tampil(data, MAX);
        puts("");
        break;
    case 3:
        system("cls");
        shellSort(data);
        puts("Shell Sort :\n");
        tampil(data, MAX);
        puts("");
        break;
    case 4:
        system("cls");
        bubbleSort(data);
        puts("Bubble Sort :\n");
        tampil(data, MAX);
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

void insertionSort(Siswa *siswa){
    int i, j;
    Siswa temp;
    puts("");

    for (i = 1; i < MAX; i++){
        temp = siswa[i];
        j = i - 1;

        while (j >= 0 && ((metodeSorting == 1 && metodeAscDesc == 1 && siswa[j].NO > temp.NO) ||
                          (metodeSorting == 1 && metodeAscDesc == 2 && siswa[j].NO < temp.NO) ||
                          (metodeSorting == 2 && metodeAscDesc == 1 && strcmp(siswa[j].Nama, temp.Nama) > 0) ||
                          (metodeSorting == 2 && metodeAscDesc == 2 && strcmp(siswa[j].Nama, temp.Nama) < 0) ||
                          (metodeSorting == 3 && metodeAscDesc == 1 && siswa[j].Nilai > temp.Nilai) ||
                          (metodeSorting == 3 && metodeAscDesc == 2 && siswa[j].Nilai < temp.Nilai)
                          )){
            siswa[j+1] = siswa[j];
            j--;
        }
        siswa[j+1] = temp;
    }
}

void selectionSort(Siswa *siswa)
{
    int i, j, min;
    Siswa temp;
    for (i = 0; i < MAX - 1; i++){
        min = i;
        for (j = i + 1; j < MAX; j++){
            if ((metodeSorting == 1 && metodeAscDesc == 1 && siswa[j].NO < siswa[min].NO) ||
                (metodeSorting == 1 && metodeAscDesc == 2 && siswa[j].NO > siswa[min].NO) ||
                (metodeSorting == 2 && metodeAscDesc == 1 && strcmp(siswa[j].Nama, siswa[min].Nama) < 0) ||
                (metodeSorting == 2 && metodeAscDesc == 2 && strcmp(siswa[j].Nama, siswa[min].Nama) > 0) ||
                (metodeSorting == 3 && metodeAscDesc == 1 && siswa[j].Nilai < siswa[min].Nilai) ||
                (metodeSorting == 3 && metodeAscDesc == 2 && siswa[j].Nilai > siswa[min].Nilai)){
                min = j;
            }
        }
        if (min != i){
            temp = siswa[i];
            siswa[i] = siswa[min];
            siswa[min] = temp;
        }
    }
}

void bubbleSort(Siswa *siswa)
{
    int i, j;
    Siswa temp;
    puts("");
    for (i = 0; i < MAX-1; i++){
        for (j = 0; j < MAX-i-1; j++){
            if ((metodeSorting == 1 && metodeAscDesc == 1 && siswa[j].NO > siswa[j+1].NO) ||
                (metodeSorting == 1 && metodeAscDesc == 2 && siswa[j].NO < siswa[j+1].NO) ||
                (metodeSorting == 2 && metodeAscDesc == 1 && strcmp(siswa[j].Nama, siswa[j+1].Nama) > 0) ||
                (metodeSorting == 2 && metodeAscDesc == 2 && strcmp(siswa[j].Nama, siswa[j+1].Nama) < 0) ||
                (metodeSorting == 3 && metodeAscDesc == 1 && siswa[j].Nilai > siswa[j+1].Nilai) ||
                (metodeSorting == 3 && metodeAscDesc == 2 && siswa[j].Nilai < siswa[j+1].Nilai)){
                temp = siswa[j];
                siswa[j] = siswa[j+1];
                siswa[j+1] = temp;
            }
        }
    }
}

void shellSort(Siswa *siswa)
{
    int k, i, j;
    Siswa temp;
    puts("");
    for (k = MAX/2; k > 0; k = k/2){
        for (i = k; i < MAX; i++){
            temp = siswa[i];
            j = i;
            while (j >= k && ((metodeSorting == 1 && metodeAscDesc == 1 && siswa[j-k].NO > temp.NO) ||
                              (metodeSorting == 1 && metodeAscDesc == 2 && siswa[j-k].NO < temp.NO) ||
                              (metodeSorting == 2 && metodeAscDesc == 1 && strcmp(siswa[j-k].Nama, temp.Nama) > 0) ||
                              (metodeSorting == 2 && metodeAscDesc == 2 && strcmp(siswa[j-k].Nama, temp.Nama) < 0) ||
                              (metodeSorting == 3 && metodeAscDesc == 1 && siswa[j-k].Nilai > temp.Nilai) ||
                              (metodeSorting == 3 && metodeAscDesc == 2 && siswa[j-k].Nilai < temp.Nilai))){
                siswa[j] = siswa[j-k];
                j -= k;
            }
            siswa[j] = temp;
        }
    }
}

void tukar(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void modeAscDesc(){
    printf("\nPengurutan yang dipilih:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan anda [1/2]: ");
    scanf("%d", &metodeAscDesc);
}

void modeSorting(){
    printf("\nPengurutan yang dipilih:\n");
    printf("1. SortByNO\n");
    printf("2. SortByNama\n");
    printf("3. SortByNilai\n");
    printf("Pilihan anda [1/2/3]: ");
    scanf("%d", &metodeSorting);
}

void tampil(struct Siswa *siswa, int n){
    printf("+-----+----------------------+-------+\n");
    printf("| %-3s | %-20s | %-5s |\n", "NO", "Nama", "Nilai");
    printf("+-----+----------------------+-------+\n");
    for (int i = 0; i < n; i++){
        printf("| %3d | %-20s | %-5d |\n", siswa[i].NO, siswa[i].Nama, siswa[i].Nilai);
    }
    printf("+-----+----------------------+-------+\n");
}
