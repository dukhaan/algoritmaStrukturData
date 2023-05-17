#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 10

void selectionSort(int x[]);
void insertionSort(int x[]);
void bubbleSort(int A[]);
void shellSort(int A[]);
void MergeSortRekursif(int left, int right, int x[]);
void Merge(int left, int median, int right, int x[]);
void Quicksort(int A[], int p, int r);
int Partition(int A[], int p, int r);
void tampil(int A[]);
void tukar(int *a, int *b);
void mode_urut();
void allmenu(int menuSort, int a[], int b[]);
int mode;

int main() {
    int a[MAX] = {10,9,10,7,2,2,2,2,2,2};
    int b[MAX];
    for (int i = 0; i < MAX; i++) {
        b[i] = a[i];
    }
    int menuSort = 0;
    while (menuSort != 7){
        puts("\nMENU METODE SORTING");
        printf("1. Insertion Sort\n2. Selection Sort\n3. Bubble sort\n4. Shell Sort\n5. Merge Sort\n6. Quick Sort\n7. Exit\n");
        printf("Pilihan anda [1/2/3/4/5/6/7] : ");
        scanf("%d",&menuSort);

        if(menuSort > 6){
            exit(0);
        }else if(menuSort!=7){
            mode_urut();
        }
        allmenu(menuSort, a, b);
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
    for (i = 1; i < MAX ; i++){
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
        for (int k = 0; k < MAX; k++) {
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

void selectionSort(int x[]){
    int cmp = 0; //jumlah pembandingan
    int swp = 0; //jumlah penukaran
    int shf = 0; //jumlah pergeseran
    int i,j,min,temp;
    clock_t t;
    t = clock();
    puts("");
    for (i = 0; i < MAX ; i++){
        min = i;
        for (j = i+1 ; j < MAX ; j++){
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
        for (int k = 0; k < MAX; k++){
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

void bubbleSort(int A[]) {
    int i, j, temp;
    int did_swap = 1;
    int iterasi = 1;
    clock_t t;
    t = clock();
        puts("");
    while (did_swap) {
        did_swap = 0;
        for (i = 0; i < MAX - 1; i++) {
            if ((mode == 1 && A[i] > A[i + 1]) || (mode == 2 && A[i] < A[i + 1])) {
                tukar(&A[i],&A[i+1]);
                did_swap = 1;
            }
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
    int i, j, k, temp;
    int iterasi = 1;
    clock_t t;
    t = clock();
    puts("");
    for (k = MAX/2; k > 0; k = k/2) {
        for (i = k; i < MAX; i++) {
            temp = A[i];
            j = i;
            while (j >= k && ((mode == 1 && A[j-k] > temp) || (mode == 2 && A[j-k] < temp))) {
                A[j] = A[j-k];
                j -= k;
            }
            A[j] = temp;
        }
        printf("Iterasi %d: ", iterasi++);
        tampil(A);
        printf("\n");
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Waktu yang dibutuhkan: %f detik\n", time_taken);
}

void Merge(int left, int median, int right, int x[]) {
    int kiri1 = left;
    int kanan1 = median;
    int kiri2 = median + 1;
    int kanan2 = right;
    int i = left;
    int hasil[MAX];

    while (kiri1 <= kanan1 && kiri2 <= kanan2) {
        if ((mode == 1 && x[kiri1] <= x[kiri2]) || (mode == 2 && x[kiri1] >= x[kiri2])) {
            hasil[i] = x[kiri1];
            kiri1++;
        }
        else {
            hasil[i] = x[kiri2];
            kiri2++;
        }
        i++;
    }

    while (kiri1 <= kanan1) {
        hasil[i] = x[kiri1];
        kiri1++;
        i++;
    }

    while (kiri2 <= kanan2) {
        hasil[i] = x[kiri2];
        i++;
        kiri2++;
    }

    for (int j = left; j <= right; j++) {
        x[j] = hasil[j];
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

int Partition(int A[], int p, int r) {
    int x = A[p];
    int i = p;
    int j = r;
    do {
        while ((mode == 1 && A[j] > x) || (mode == 2 && A[j] < x)){
            j--;
        }
        while ((mode == 1 && A[i] < x) || (mode == 2 && A[i] > x)){
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

void tampil(int A[]){
    printf("\nIsi dari array : ");
    for (int i = 0; i<MAX ; i++){
        printf("%d ",A[i]);
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
    printf("Pilihan anda [1/2]: ");
    scanf("%d", &mode);
}

void allmenu(int menuSort, int a[], int b[]){
    system("cls");
    puts("\nQuick Sort\nSebelum Sort");
    tampil(b);
    switch (menuSort) {

            case 1:
                insertionSort(a);
                break;
            case 2:
                selectionSort(a);
                break;
            case 3:
                bubbleSort(a);
                break;
            case 4:
                shellSort(a);
                break;
            case 5:
                MergeSortRekursif(0, MAX - 1, a);
                break;
            case 6:
                Quicksort(a,0,MAX-1);
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid menu!\n");
                return 1;
    }
    puts("\nQuick Sort\n");
    printf("Sesudah Sort");
    tampil(a);
    puts("");
}
