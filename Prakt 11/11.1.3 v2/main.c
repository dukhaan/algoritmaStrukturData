#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void selectionSort(int x[]);
void insertionSort(int x[]);
void bubbleSort(int A[]);
void shellSort(int A[]);
void tampil(int A[]);
void tukar(int *a, int *b);
void mode_urut();
void generate(int A[]);
void generate_backup(int A_backup[], int A[]);
void allmenu(int menuSort, int jumlahData);
int menuSort,mode,jumlahData;

int main() {
    printf("Berapa Jumlah data (maks 100000) : ");
    scanf("%d", &jumlahData);
    while (menuSort != 5){
        puts("\n\nMENU METODE SORTING");
        printf("1. Insertion Sort\n2. Selection Sort\n3. Bubble sort\n4. Shell Sort\n5. Exit\n");
        printf("Pilihan anda [1/2/3/4/5] : ");
        scanf("%d",&menuSort);

        if(menuSort > 4){
            exit(0);
        }else if(menuSort!=5){
            mode_urut();
        }
        allmenu(menuSort, jumlahData);
    }
    return 0;
}

void insertionSort(int x[]){
    clock_t t;
    t = clock();
    puts("");
    int cmp = 0; //jumlah pembandingan
    int swp = 0; //jumlah penukaran
    int shf = 0; //jumlah pergeseran
    int i,j,key;
    for (i = 1; i < jumlahData ; i++){
        key = x[i];
        j = i - 1;

        while(j >= 0 && ((mode == 1 && x[j] > key) || (mode == 2 && x[j] < key))){
            x[j+1] = x[j];
            j--;
            shf++; // pergeseran
            cmp += 2; // pembandingan
        }
        x[j+1] = key;
        shf++; // pergeseran
        swp++; // penukaran
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Waktu yang dibutuhkan: %.3f detik\n", time_taken);
}

void selectionSort(int x[]){
    int cmp = 0; //jumlah pembandingan
    int swp = 0; //jumlah penukaran
    int shf = 0; //jumlah pergeseran
    int i,j,min,temp;
    clock_t t;
    t = clock();
    puts("");
    for (i = 0; i < jumlahData ; i++){
        min = i;
        for (j = i+1 ; j < jumlahData ; j++){
            cmp++; // pembandingan
            if((mode == 1 && x[j] < x[min]) || (mode == 2 && x[j] > x[min])){
                min = j;
            }
        }
        if(min != i){
            tukar(&x[min], &x[i]);
            swp++; // penukaran
        }
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Waktu yang dibutuhkan: %.3f detik\n", time_taken);
}

void bubbleSort(int A[]) {
    int i, j, temp, swp=0, cmp=0, shf=0;
    int did_swap = 1;
    int iterasi = 1;
    clock_t t;
    t = clock();
        puts("");
    while (did_swap) {
        did_swap = 0;
        for (i = 0; i < jumlahData - 1; i++) {
            if ((mode == 1 && A[i] > A[i + 1]) || (mode == 0 && A[i] < A[i + 1])) {
                tukar(&A[i],&A[i+1]);
                did_swap = 1;
                swp++;
            }
            cmp++;
        }
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Waktu yang dibutuhkan: %.3f detik\n", time_taken);
}

void shellSort(int A[]) {
    int i, j, k, temp, cmp=0, swp=0, shf=0;
    int iterasi = 1;
    clock_t t;
    t = clock();
    puts("");
    for (k = jumlahData/2; k > 0; k = k/2) {
        for (i = k; i < jumlahData; i++) {
            temp = A[i];
            j = i;
            while (j >= k && ((mode == 1 && A[j-k] > temp) || (mode == 0 && A[j-k] < temp))) {
                A[j] = A[j-k];
                j -= k;
                cmp++;
                swp++;
                shf++;
            }
            A[j] = temp;
            cmp++;
            shf++;
        }
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Waktu yang dibutuhkan: %.3f detik\n", time_taken);
}



void tampil(int A[]){
    printf("\nIsi dari array : ");
    for (int i = 0; i<jumlahData ; i++){
        printf("%d ",A[i]);
    }
}

void tukar(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void generate(int A[]){
    int i;
    srand(time(NULL));
    for (i = 0; i < jumlahData; i++){
        A[i] = rand() / 1000;
    }
}

void generate_backup(int A_backup[], int A[]) {
    int i;
    for (i = 0; i < jumlahData; i++) {
        A_backup[i] = A[i];
    }
}


void mode_urut() {
    printf("\nPengurutan yang dipilih:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan anda [1/2]: ");
    scanf("%d", &mode);
}


void allmenu(int menuSort, int jumlahData){
    int a[jumlahData],n[jumlahData];
        //int a[jumlahData] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
    if(menuSort!=3){

        srand(time(NULL));
        generate(a);
    }
    switch (menuSort) {
            case 1:
                insertionSort(a);
                puts("");
                break;
            case 2:
                selectionSort(a);
                puts("");
                break;
            case 3:
                bubbleSort(a);
                puts("");
                break;
            case 4:
                shellSort(a);
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
