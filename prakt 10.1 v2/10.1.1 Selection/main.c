#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void selection(int *x);
void tukar(int *a, int *b);
void tampil(int *x);


int main()
{
    int a[MAX] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
    puts("Data sebelum ditukar ");
    tampil(a);
    selection(a);

    return 0;
}

void selection(int x[]){
    int cmp = 0; //jumlah pembandingan
    int swp = 0; //jumlah penukaran
    int shf = 0; //jumlah pergeseran
    int i,j,min,temp;
    for (i = 0; i < MAX ; i++){
        min = i;
        for (j = i+1 ; j < MAX ; j++){
            cmp++; // pembandingan
            if(x[j] < x[min]){
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
    printf("\nHasil dari perbandingan : %d\n",cmp);
    printf("Hasil dari penukaran : %d\n",swp);
    printf("Hasil dari pergeseran : %d\n",shf);
}

void tukar(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(int *x){
    printf("Isi dari array : ");
    for (int i = 0; i<MAX ; i++){
        printf("%d ",x[i]);
    }
        puts(" ");
}
