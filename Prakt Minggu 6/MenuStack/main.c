#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef char itemType;
typedef struct {
    itemType data[MAX];
    int count;
}stack;

void allmenu();
void inisialisasi(stack *s);
int empty(stack *s);
int full(stack *s);
void push(itemType x, stack *s);
itemType pop(stack *s);
void tampil();
void menu_push();
void menu_pop();
void menu_tampil();
void menu_exit();

char menu1;
itemType x;
stack tumpukan;

int main()
{
    inisialisasi(&tumpukan);
    allmenu();

    return 0;
}

void inisialisasi(stack *s){
    s->count = 0;
}

int empty(stack *s){
    return(s->count == 0 ? 1 : 0);
}

int full(stack *s){
    return(s->count == MAX ? 1 : 0);
}

void push(itemType x, stack *s){
    if(full(s)){
        printf("Stack penuh, data tidak dapat disimpan.\n");
    } else{
        s->data[s->count] = x;
        s->count++;
    }
}

void tampil(stack *s){
    int i;
    puts("Isi dari Stack :");
        if(!empty(&tumpukan)){
            for(i = s->count-1; i >= 0;i--){
                printf("%c\n",s->data[i]);
            }
        } else {
            puts("Stack empty.");
    }
}

itemType pop(stack *s){
    itemType temp;

    if(empty(s)){
        printf("Stack Kosong, tidak dapat mengambil data\n");
        temp = "";
    } else{
        --(s->count);
        temp = s->data[s->count];
    }
    return temp;
}

void allmenu(){
    while (menu1 != 5){
        puts("\nMENU STACK - ARRAY");
        printf("1. Mengisi Stack (PUSH)\n2. Mengambil Isi Stack(POP)\n3. Menampilkan isi stack -> LIFO\n4. Keluar\n");
        printf("Masukkan pilihan anda : ");
        scanf("%d",&menu1);
        fflush(stdin);
        menu_push();
        menu_pop();
        menu_tampil();
        menu_exit();
    }
}

void menu_push(){
    if(menu1 == 1){
        printf("Masukkan elemen : ");
        x = getchar();
        push(x, &tumpukan);
        system("cls");
    }
}


void menu_pop(){
    if(menu1 == 2){
        system("cls");
        printf("Data yang di pop : %c\n",pop(&tumpukan));
    }
}

void menu_tampil(){
    if(menu1 == 3){
        system("cls");
        tampil(&tumpukan);
    }
}


void menu_exit(){
    if (menu1 == 4){
        puts("Terimakasih telah menggunakan aplikasi ini");
        exit(0);
    }
}
