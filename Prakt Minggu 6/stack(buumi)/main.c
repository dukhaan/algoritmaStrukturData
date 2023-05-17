#include <stdio.h>
#include <stdlib.h>
#define MAKS 5

typedef char itemType;
typedef struct {
    itemType data[MAKS];
    int count;
}stack;

void inisialisasi(stack *s);
int empty(stack *s);
int full(stack *s);
void push(itemType x, stack *s);
itemType pop(stack *s);
void tampil(stack *s);

itemType x;
stack tumpukan;

int main()
{

    stack tumpukan;
    itemType x;
    char jwb;
    inisialisasi(&tumpukan);
    puts("Stacking data");
    do{
        fflush(stdin);
        printf("Masukkan elemen : ");
        x = getchar();
        push(x, &tumpukan);
        fflush(stdin);
        printf("Ingin memasukkan kembali (y/t) : ");
        jwb = getchar();
    }
    while(jwb == 'y' || jwb == 'Y');
    tampil(&tumpukan);
    /*
    if(!empty(&tumpukan)){
        for(itemType i = tumpukan->count-1; i>=0;i--){
            printf("%c\n",tumpukan->data[i]);
        }
    else
        printf("Data sudah kosong\n");
    }
    */
    return 0;
}


void inisialisasi(stack *s){
    s->count = 0;
}

int empty(stack *s){
    return(s->count == 0 ? 1 : 0);
}

int full(stack *s){
    return(s->count == MAKS ? 1 : 0);
}

void push(itemType x, stack *s){
    if(full(s)){
        printf("Stack penuh, data tidak dapat disimpan.\n");
    } else{
        s->data[s->count] = x;
        s->count++;
    }
}

itemType pop(stack *s){
    itemType temp;

    if(empty(s)){
        printf("Stack kosong, push data terlebih dahulu\n");
    } else{
        --(s->count);
        temp = s->data[s->count];
        return temp;
    }
}

void tampil(stack *s){
    printf("Isi dari stack : \n");

    while(!empty(s)){
        printf("%c\n",pop(s));
    }
}
