#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void selectionSort(int x[], int jumlahData);
void insertionSort(int x[], int jumlahData);
void bubbleSort(int A[], int jumlahData);
void shellSort(int A[], int jumlahData);
void tampil(int A[], int jumlahData);
void tukar(int *a, int *b);
void mode_urut();
void generate(int A[], int jumlahData);
void generate_backup(int b[], int A[], int jumlahData);
void allmenu(int menuSort, int jumlahData, int a[], int b[]);
int mode;

int main() {
    int jumlahData;
    printf("Input Jumlah Data : ");
    scanf("%d", &jumlahData);

    int a[jumlahData];
    int b[jumlahData];

    generate(a, jumlahData);

    int menuSort = 0;
    while (menuSort != 5){
        generate_backup(b, a, jumlahData);
        puts("\nMENU METODE SORTING");
        printf("1. Insertion Sort\n2. Selection Sort\n3. Bubble sort\n4. Shell Sort\n5. Exit\n");
        printf("Pilihan anda [1/2/3/4/5] : ");
        scanf("%d",&menuSort);

        if(menuSort > 4){
            exit(0);
        }else if(menuSort!=5){
            mode_urut();
        }
        allmenu(menuSort, jumlahData, a, b);
    }
    return 0;
}

void insertionSort(int x[], int jumlahData){
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
        printf("Iterasi ke-%d: ", i);
        for (int k = 0; k < jumlahData; k++) {
            printf("%d ", x[k]);
        }
        printf("\n");
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Waktu yang dibutuhkan: %f detik\n", time_taken);

    //printf("\nHasil dari perbandingan : %d\n",cmp);
    //printf("Hasil dari penukaran : %d\n",swp);
    //printf("Hasil dari pergeseran : %d\n",shf);
}

void selectionSort(int x[], int jumlahData){
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
        printf("Iterasi ke-%d: ", i+1);
        for (int k = 0; k < jumlahData; k++){
            printf("%d ", x[k]);
        }
        printf("\n");
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Waktu yang dibutuhkan: %f detik\n", time_taken);

    //printf("\nHasil dari perbandingan : %d\n",cmp);
    //printf("Hasil dari penukaran : %d\n",swp);
    //printf("Hasil dari pergeseran : %d\n",shf);
}

void bubbleSort(int A[], int jumlahData) {
    int i, j, temp;
    int did_swap = 1;
    int iterasi = 1;
    clock_t t;
    t = clock();
        puts("");
    while (did_swap) {
        did_swap = 0;
        for (i = 0; i < jumlahData - 1; i++) {
            if ((mode == 1 && A[i] > A[i + 1]) || (mode == 2 && A[i] < A[i + 1])) {
                tukar(&A[i],&A[i+1]);
                did_swap = 1;
            }
        }
        printf("Iterasi %d: ", iterasi++);
        tampil(A,jumlahData);
        printf("\n");
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Waktu yang dibutuhkan: %f detik\n", time_taken);
}

void shellSort(int A[], int jumlahData) {
    int i, j, k, temp;
    int iterasi = 1;
    clock_t t;
    t = clock();
    puts("");
    for (k = jumlahData/2; k > 0; k = k/2) {
        for (i = k; i < jumlahData; i++) {
            temp = A[i];
            j = i;
            while (j >= k && ((mode == 1 && A[j-k] > temp) || (mode == 2 && A[j-k] < temp))) {
                A[j] = A[j-k];
                j -= k;
            }
            A[j] = temp;
        }
        printf("Iterasi %d: ", iterasi++);
        tampil(A,jumlahData);
        printf("\n");
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Waktu yang dibutuhkan: %f detik\n", time_taken);
}


void tampil(int A[], int jumlahData){
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

void generate(int A[], int jumlahData){
    int i;
    printf("\n");
    for (i = 0 ; i < jumlahData ; i++){
        A[i] = rand()%100+1;
        printf("%d ",A[i]);
    }
    printf("\n");
}

void generate_backup(int b[], int A[], int jumlahData) {
    for (int i = 0; i < jumlahData; i++) {
        b[i] = A[i];
    }
}


void mode_urut() {
    printf("\nPengurutan yang dipilih:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan anda [1/2]: ");
    scanf("%d", &mode);
}


void allmenu(int menuSort, int jumlahData, int a[],int b[]){



    switch (menuSort) {
            case 1:
                system("cls");
                puts("\nInsertion Sort\nSebelum Sort");
                tampil(a,jumlahData);
                insertionSort(b,jumlahData);
                puts("\nShell Sort\n");
                printf("Sesudah Sort");
                tampil(b,jumlahData);
                puts("");
                break;
            case 2:
                system("cls");
                puts("\nSelection Sort\nSebelum Sort");
                tampil(a,jumlahData);
                selectionSort(b,jumlahData);
                puts("\nShell Sort\n");
                printf("Sesudah Sort");
                tampil(b,jumlahData);
                puts("");
                break;
            case 3:
                system("cls");
                puts("\nBubble Sort\nSebelum Sort");
                tampil(a,jumlahData);
                bubbleSort(b,jumlahData);
                puts("\nBubble Sort\nSesudah Sort");
                tampil(b,jumlahData);
                puts("");
                break;
            case 4:
                system("cls");
                puts("\nShell Sort\nSebelum Sort");
                tampil(a,jumlahData);
                shellSort(b,jumlahData);
                puts("\nShell Sort\n");
                printf("Sesudah Sort");
                tampil(b,jumlahData);
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
