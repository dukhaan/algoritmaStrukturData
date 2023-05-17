#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void Quicksort(int A[], int p, int r);
int Partition(int A[], int p, int r);
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
    while (menuSort != 7){
        generate_backup(b, a, jumlahData);
        puts("\nMENU METODE SORTING");
        printf("1. Insertion Sort\n2. Selection Sort\n3. Bubble sort\n4. Shell Sort\n5. Merge Sort\n6. Quick Sort\n7. Exit\n");
        printf("Pilihan anda [1/2/3/4/5/6/7] : ");
        scanf("%d",&menuSort);

        if(menuSort > 6){
            exit(0);
        }else if(menuSort!=7){
            mode_urut();
        }
        allmenu(menuSort, jumlahData, a, b);
    }
    return 0;
}

int Partition(int A[], int p, int r) {
    int x = A[p]; //pivot=elemen posisi pertama
    int i = p;
    int j = r;
    do {
        while (A[j] > x) {
            j--;
        }
        while (A[i] < x) {
            i++;
        }
        if (i < j) {
            tukar(&A[i],&A[j]);
            j--;
            i++;
        } else {
            return j;
        }
    } while (i <= j);
    return j;
}


void Quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        Quicksort(A, p, q);
        Quicksort(A, q+1, r);
    }
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
int left, right;


    switch (menuSort) {
            /*
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
                system("cls");
                puts("\nQuick Sort\nSebelum Sort");
                tampil(a,jumlahData);
                MergeSortRekursif(0, jumlahData - 1, b);
                puts("\nMerge Sort\n");
                printf("Sesudah Sort");
                tampil(b,jumlahData);
                puts("");
                break;
            */
            case 6:
                system("cls");
                puts("\nQuick Sort\nSebelum Sort");
                tampil(a,jumlahData);
                Quicksort(b,0,jumlahData-1);
                puts("\nQuick Sort\n");
                printf("Sesudah Sort");
                tampil(b,jumlahData);
                puts("");
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid menu!\n");
                return 1;
    }
}
