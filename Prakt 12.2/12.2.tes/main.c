#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 3

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
void Merge(int left, int median, int right, Siswa *siswa);
void MergeSortRekursif(int left, int right, Siswa *siswa);
int Partition(Siswa *siswa, int p, int r);
void Quicksort(Siswa *siswa, int p, int r);
void tukar(Siswa *a, Siswa *b);
void tampil(Siswa *siswa, int n);
void allmenu(Siswa *,Siswa *, int menuSort);
void generate(Siswa data[]);
void modeAscDesc();
void modeSorting();

int menuSort = 0, metodeAscDesc = 0, metodeSorting = 0;

int main()
{
    Siswa data[MAX];
    Siswa data2[MAX];
    generate(data);


        tampil(data, MAX);
    while(menuSort != 7){
        generate_backup(&data2, &data);
        puts("\nMENU METODE SORTING");
        printf("1. Insertion Sort\n2. Selection Sort\n3. Shell Sort\n4. Bubble Sort\n5. Merge Sort\n6. Quick Sort\n7. Exit");
        printf("\nPilihan anda [1/2/3/4/5/6/7] : ");
        scanf("%d", &menuSort);

        if (menuSort == 7){
            exit(0);
        }else if (menuSort < 1 || menuSort > 7){
            printf("Menu yang dimasukkan salah!\n");
        }else{
            modeSorting();
            modeAscDesc();
            if (metodeSorting < 1 || metodeSorting > 3)
                printf("Menu yang dimasukkan salah!\n");
            else
                allmenu(data,data2, menuSort);
        }
    }
    return 0;
}

void allmenu(Siswa *data,Siswa *data2, int menuSort)
{
    switch (menuSort){
    case 1:
        system("cls");
        insertionSort(data2);
        puts("Insertion Sort :\n");
        tampil(data2, MAX);
        puts("");
        break;
    case 2:
        system("cls");
        selectionSort(data2);
        puts("Selecetion Sort :\n");
        tampil(data2, MAX);
        puts("");
        break;
    case 3:
        system("cls");
        shellSort(data2);
        puts("Shell Sort :\n");
        tampil(data2, MAX);
        puts("");
        break;
    case 4:
        system("cls");
        bubbleSort(data2);
        puts("Bubble Sort :\n");
        tampil(data2, MAX);
        puts("");
        break;
    case 5:
        system("cls");
        MergeSortRekursif(0, MAX-1, data2);
        puts("Merge Sort :\n");
        tampil(data2, MAX);
        puts("");
        break;
    case 6:
        system("cls");
        Quicksort(data2,0,MAX-1);
        puts("Quick Sort :\n");
        tampil(data2, MAX);
        puts("");
        break;
    case 7:
        exit(0);
        break;
    default:
        printf("Invalid menu!\n");
        return;
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


void Merge(int left, int median, int right, Siswa *siswa) {
    int kiri1 = left;
    int kanan1 = median;
    int kiri2 = median + 1;
    int kanan2 = right;
    int i = left;
    Siswa hasil[MAX];

    while (kiri1 <= kanan1 && kiri2 <= kanan2) {
        if ((metodeSorting == 1 && metodeAscDesc == 1 && siswa[kiri1].NO <= siswa[kiri2].NO) ||
            (metodeSorting == 1 && metodeAscDesc == 2 && siswa[kiri1].NO >= siswa[kiri2].NO) ||
            (metodeSorting == 2 && metodeAscDesc == 1 && strcmp(siswa[kiri1].Nama, siswa[kiri2].Nama) < 0) ||
            (metodeSorting == 2 && metodeAscDesc == 2 && strcmp(siswa[kiri1].Nama, siswa[kiri2].Nama) > 0) ||
            (metodeSorting == 3 && metodeAscDesc == 1 && siswa[kiri1].Nilai < siswa[kiri2].Nilai) ||
            (metodeSorting == 3 && metodeAscDesc == 2 && siswa[kiri1].Nilai > siswa[kiri2].Nilai)){
            hasil[i] = siswa[kiri1];
            kiri1++;
        }
        else {
            hasil[i] = siswa[kiri2];
            kiri2++;
        }
        i++;
    }

    while (kiri1 <= kanan1) {
        hasil[i] = siswa[kiri1];
        kiri1++;
        i++;
    }

    while (kiri2 <= kanan2) {
        hasil[i] = siswa[kiri2];
        i++;
        kiri2++;
    }

    for (int j = left; j <= right; j++) {
        siswa[j] = hasil[j];
    }
}

void MergeSortRekursif(int left, int right, Siswa *siswa) {

    if (left < right) {
        int median = (left + right) / 2;
        MergeSortRekursif(left, median, siswa);
        MergeSortRekursif(median + 1, right, siswa);
        Merge(left, median, right, siswa);
    }
}

void Quicksort(Siswa *siswa, int p, int r)
{
    int q;

    if(p < r)
    {
        q = Partition(siswa, p, r);
        Quicksort(siswa, p, q);
        Quicksort(siswa, q+1, r);
    }
}

int Partition(Siswa *siswa, int p, int r)
{
    Siswa pivot = siswa[p];
    int i = p;
    int j = r;

    do {
        while ((metodeSorting == 1 && metodeAscDesc == 1 && siswa[j].NO > pivot.NO) ||
               (metodeSorting == 1 && metodeAscDesc == 2 && siswa[j].NO < pivot.NO) ||
               (metodeSorting == 2 && metodeAscDesc == 1 && strcmp(siswa[j].Nama, pivot.Nama) > 0) ||
               (metodeSorting == 2 && metodeAscDesc == 2 && strcmp(siswa[j].Nama, pivot.Nama) < 0) ||
               (metodeSorting == 3 && metodeAscDesc == 1 && siswa[j].Nilai > pivot.Nilai) ||
               (metodeSorting == 3 && metodeAscDesc == 2 && siswa[j].Nilai < pivot.Nilai)){
                   j--;
               }

        while ((metodeSorting == 1 && metodeAscDesc == 1 && siswa[i].NO < pivot.NO) ||
               (metodeSorting == 1 && metodeAscDesc == 2 && siswa[i].NO > pivot.NO) ||
               (metodeSorting == 2 && metodeAscDesc == 1 && strcmp(siswa[i].Nama, pivot.Nama) < 0) ||
               (metodeSorting == 2 && metodeAscDesc == 2 && strcmp(siswa[i].Nama, pivot.Nama) > 0) ||
               (metodeSorting == 3 && metodeAscDesc == 1 && siswa[i].Nilai < pivot.Nilai) ||
               (metodeSorting == 3 && metodeAscDesc == 2 && siswa[i].Nilai > pivot.Nilai)){
                   i++;
               }

        if(i < j){
            tukar(&siswa[i], &siswa[j]);
            j--;
            i++;
        }
        else
            return j;

    } while (i <= j);
    return j;
}

void generate(Siswa data[]){

    for (int i = 0; i < MAX; i++) {
        printf("Masukkan data siswa ke-%d\n", (i + 1));
        printf("No: ");
        scanf("%d", &data[i].NO);
        printf("Nama: ");
        scanf("%s", data[i].Nama);
        printf("Nilai: ");
        scanf("%d", &data[i].Nilai);
    }
}

void generate_backup(Siswa *b, Siswa *A) {
    for (int i = 0; i < MAX; i++) {
        b[i] = A[i];
    }
}

void tukar(Siswa *a, Siswa *b){
    Siswa temp;
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
