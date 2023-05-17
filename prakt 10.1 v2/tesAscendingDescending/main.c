#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void insertion(int *x,int order);
void tampil(int *x);

int main()
{
    int a[MAX] = {1,3,2,4,5,7,6,8,9,10};
    int pesanan;
    printf("1. Ascending\n2. Descending\n");
    printf("pilihan anda [1/2] : ");
    scanf("%d",&pesanan);
    insertion(a,pesanan);
    tampil(a);
    return 0;
}

void insertion(int *x,int order){
    int i,j,key;
    for (i = 1; i < MAX ; i++){
        key = x[i];
        j = i - 1;

        while(j >= 0 && ((order == 1 && x[j] > key) || (order == 2 && x[j] < key))){
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = key;
    }
}

void tampil(int *x){
    printf("Isi dari array : ");
    for (int i = 0; i<MAX ; i++){
        printf("%d ",x[i]);
    }
}
