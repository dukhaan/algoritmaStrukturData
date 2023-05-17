#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void insertion(int x[],int submenu);
void selection(int x[],int submenu);
void tukar(int *a, int *b);
void tampil(int x[]);
void allmenu(int menu1,int menu2);
int menu1,menu2;

int main()
{
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

void insertion(int x[], int submenu){
    int cmp = 0; //jumlah pembandingan
    int swp = 0; //jumlah penukaran
    int shf = 0; //jumlah pergeseran
    int i,j,key;
    for (i = 1; i < MAX ; i++){
        key = x[i];
        j = i - 1;

        while(j >= 0 && ((submenu == 1 && x[j] > key) || (submenu == 2 && x[j] < key))){
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


void selection(int x[], int submenu){
    int cmp = 0; //jumlah pembandingan
    int swp = 0; //jumlah penukaran
    int shf = 0; //jumlah pergeseran
    int i,j,min,temp;
    for (i = 0; i < MAX ; i++){
        min = i;
        for (j = i+1 ; j < MAX ; j++){
            cmp++; // pembandingan
            if((submenu == 1 && x[j] < x[min]) || (submenu == 2 && x[j] > x[min])){
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
void tampil(int x[]){
    printf("\nIsi dari array : ");
    for (int i = 0; i<MAX ; i++){
        printf("%d ",x[i]);
    }
}

void allmenu(int menu1,int menu2){
    int a[MAX] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
    switch (menu1) {
            case 1:
                menu2;
                insertion(a,menu2);
                tampil(a);
                break;
            case 2:
                menu2;
                selection(a,menu2);
                tampil(a);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid menu!\n");
                return 1;
    }
}


