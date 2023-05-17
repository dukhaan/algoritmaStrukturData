#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void insertion(int *x);
void tampil(int *x);


int main()
{
    int a[MAX] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
    puts("Data sebelum ditukar\n");
    tampil(a);
    insertion(a);
    return 0;
}

void insertion(int x[]){
    int cmp = 0; //jumlah pembandingan
    int swp = 0; //jumlah penukaran
    int shf = 0; //jumlah pergeseran
    int i,j,key;
    puts("");
    for (i = 1; i < MAX ; i++){
        key = x[i];
        j = i - 1;

        while(j >= 0 && x[j] > key){
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
    printf("\nHasil dari perbandingan : %d\n",cmp);
    printf("Hasil dari penukaran : %d\n",swp);
    printf("Hasil dari pergeseran : %d\n",shf);
}


void tampil(int *x){
    printf("Isi dari array : ");
    for (int i = 0; i<MAX ; i++){
        printf("%d ",x[i]);
    }
}
