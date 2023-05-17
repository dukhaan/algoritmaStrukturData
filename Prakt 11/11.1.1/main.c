#include <stdio.h>
#include <stdlib.h>B
#define MAX 10

void bubbleSort(int A[]);
void shellSort(int A[]);
void tampil(int A[]);
void tukar(int *a, int *b);

int main() {
    while (menu1 != 3){
        puts("\n\nMENU METODE SORTING");
        printf("1. Insertion Sort\n2. Selection Sort\n3. Exit");
        printf("\nPilihan anda [1/2/3] : ");
        scanf("%d",&menu1);

        if(menu1 > 2){
            exit(0);
        } else{
            puts("\nMENU METODE SORTING");
            printf("1. Ascending\n2. Descending\n");
            printf("Pilihan anda [1/2] : ");
            scanf("%d",&menu2);
            puts("");
        }
        allmenu(menu1,menu2);
    }
    return 0;
}

void bubbleSort(int A[]) {
    int i, j, temp, swp=0, cmp=0, shf=0;
    int did_swap = 1;
    int iterasi = 1;
    while (did_swap) {
        did_swap = 0;
        for (i = 0; i < MAX - 1; i++) {
            if (A[i] > A[i + 1]) {
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
    printf("\nHasil dari perbandingan : %d\n",cmp);
    printf("Hasil dari penukaran : %d\n",swp);
    printf("Hasil dari pergeseran : %d\n",shf);
}

void shellSort(int A[]) {
    int Jarak = MAX, temp, cmp=0,swp=0,shf=0;
    int did_swap;
    int iterasi = 1;
    while (Jarak > 1) {
        Jarak = Jarak / 2;
        did_swap = 1;
        while (did_swap) {
            did_swap = 0;
            for (int i = 0; i < MAX - Jarak; i++) {
                if (A[i] > A[i + Jarak]) {
                    tukar(&A[i],&A[i+Jarak]);
                    did_swap = 1;
                    swp++;
                }
                cmp++;
            }
            printf("Iterasi %d: ", iterasi++);
            tampil(A);
            printf("\n");
        }
    }
    printf("\nHasil dari perbandingan : %d\n",cmp);
    printf("Hasil dari penukaran : %d\n",swp);
    printf("Hasil dari pergeseran : %d\n",shf);
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
