#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void MergeSortRekursif(int left, int right, int x[]);
void Merge(int left, int median, int right, int x[]);
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
    while (menuSort != 6){
        generate_backup(b, a, jumlahData);
        puts("\nMENU METODE SORTING");
        printf("1. Insertion Sort\n2. Selection Sort\n3. Bubble sort\n4. Shell Sort\n5. Merge Sort\n6. Exit\n");
        printf("Pilihan anda [1/2/3/4/5/6] : ");
        scanf("%d",&menuSort);

        if(menuSort > 5){
            exit(0);
        }else if(menuSort!=6){
            mode_urut();
        }
        allmenu(menuSort, jumlahData, a, b);
    }
    return 0;
}

void Merge(int left, int median, int right, int x[]) {
    int n1 = median - left + 1;
    int n2 = right - median;
    int Left[n1], Right[n2];

    //bagian 1
    for (int i = 0; i < n1; i++) {
        Left[i] = x[left + i];
    }
    for (int j = 0; j < n2; j++) {
        Right[j] = x[median + 1 + j];
    }
    //bagian 2
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if ((mode == 1 && Left[i] <= Right[j]) || (mode == 2 && Left[i] >= Right[j])) {
            x[k] = Left[i];
            i++;
        }
        else {
            x[k] = Right[j];
            j++;
        }
        k++;
    }
    //bagian 3
    while (i < n1) {
        x[k] = Left[i];
        i++;
        k++;
    }
    //bagian 4
    while (j < n2) {
        x[k] = Right[j];
        j++;
        k++;
    }

}

void MergeSortRekursif(int left, int right, int x[]) {

    if (left < right) {
        int median = (left + right) / 2;
        MergeSortRekursif(left, median, x);
        MergeSortRekursif(median + 1, right, x);
        Merge(left, median, right, x);
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
clock_t t;
t = clock();
system("cls");
puts("\nShell Sort\nSebelum Sort");
tampil(a,jumlahData);
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
            */
            case 5:
                MergeSortRekursif(0, jumlahData - 1, b);

                break;

            case 6:
                exit(0);
                break;
            default:
                printf("Invalid menu!\n");
                return 1;
    }
    puts("\nShell Sort\n");
    printf("Sesudah Sort");
    tampil(b,jumlahData);
    puts("");
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Waktu yang dibutuhkan: %f detik\n", time_taken);
}
