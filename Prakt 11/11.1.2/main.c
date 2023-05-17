#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void bubbleSort(int A[]);
void shellSort(int A[]);
void tampil(int A[]);
void tukar(int *a, int *b);
void mode_urut();
void generate(int A[]);
void allmenu(int menuSort, int jumlahData);
int menuSort,mode,jumlahData;

int main() {
    while (menuSort != 3){
        puts("\n\nMENU METODE SORTING");
        printf("1. Bubble sort\n2. Shell Sort\n3. Exit\n");
        printf("Pilihan anda [1/2/3] : ");
        scanf("%d",&menuSort);

        if(menuSort > 2){
            exit(0);
        }else if(menuSort!=3){
            mode_urut();
            printf("Input Jumlah Data : ");
            scanf("%d", &jumlahData);
        }
        allmenu(menuSort, jumlahData);
    }
    return 0;
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
        printf("Iterasi %d: ", iterasi++);
        tampil(A);
        printf("\n");
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Waktu yang dibutuhkan: %f detik\n", time_taken);
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
        printf("Iterasi %d: ", iterasi++);
        tampil(A);
        printf("\n");
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Waktu yang dibutuhkan: %f detik\n", time_taken);

    //printf("\nHasil dari perbandingan : %d\n",cmp);
    //printf("Hasil dari penukaran : %d\n",swp);
    //printf("Hasil dari pergeseran : %d\n",shf);
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
                system("cls");
                puts("\nBubble Sort\nSebelum Sort");
                tampil(a);
                bubbleSort(a);
                puts("\nBubble Sort\nSesudah Sort");
                tampil(a);
                puts("");
                break;
            case 2:
                system("cls");
                puts("\nShell Sort\nSebelum Sort");
                tampil(a);
                shellSort(a);
                puts("\nShell Sort\n");
                printf("Sesudah Sort");
                tampil(a);
                puts("");
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid menu!\n");
                return 1;
    }
}
