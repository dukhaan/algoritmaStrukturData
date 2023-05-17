#include <stdio.h>
#include <stdlib.h>
#define MAKS 5

typedef char itemType;
typedef struct {
    itemType data[MAKS];
    int count;
}stack;

void inisialisasi(stack *s);
int kosong(stack *s);
int penuh(stack *s);
void push(itemType x, stack *s);
itemType pop(stack *s);

int main()
{
    stack tumpukan;
    char jwb;
    itemType x;

    puts("Implementasi STACK menggunakan ARRAY");
    inisialisasi(&tumpukan);
    printf("Mengisi stack \n");
    do{
        fflush(stdin);
        printf("Masukkan elemen : ");
        x = getchar();
        push(x, &tumpukan);
        fflush(stdin);
        printf("Ada data lagi (y/t) : ");
        jwb = getchar();
        puts(" ");
    } while ((jwb =='y') || (jwb == 'Y'));
    puts("Isi dari Stack :");
    while(!kosong(&tumpukan)){
        printf("%c\n",pop(&tumpukan));
    }
    return 0;
}

void inisialisasi(stack *s){
    s->count = 0;
}

int kosong(stack *s){
    if(s->count == 0)
        return (1);
    else
        return (0);
}

int penuh(stack *s){
    if (s->count == MAKS){
        return (1);
    } else
        return (0);
}

void push(itemType x, stack *s){
    if(penuh(s)){
        printf("Stack penuh, data tidak dapat disimpan.\n");
    } else{
        s->data[s->count] = x;
        s->count++;
    }
}

itemType pop(stack *s){
    itemType temp;

    if(kosong(s)){
        printf("Stack Kosong, tidak dapat mengambil data\n");
        return "";
    } else{
        --s->count;
        temp = s->data[s->count];
        return(temp);
    }
}
