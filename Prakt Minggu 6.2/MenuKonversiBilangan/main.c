#include <stdio.h>
#include <stdlib.h>
#define MAX 100

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

void d_to_biner(int num, stack *s);
void d_to_oktal(int num, stack *s);
void d_to_heksa(int num, stack *s);

void tampil();
void menu_biner();
void menu_oktal();
void menu_heksadesimal();
void menu_exit();

char menu1;
itemType x;
stack tumpukan;
int in1;

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
        if(!empty(&tumpukan)){
            for(i = s->count-1; i >= 0;i--){
                printf("%c",s->data[i]);
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

void d_to_biner(int num,stack *s){
    inisialisasi(s);
    int panggil = num;
    while (num > 0){
        int sisa = num % 2;
        char digit = sisa + '0';
        push(digit, s);
        num /= 2;
    }

    printf("Hasil konversi %d ke BINER = ",panggil);
    tampil(s);
}

void d_to_oktal(int num,stack *s){
    inisialisasi(s);
    int panggil = num;
    while (num > 0){
        int sisa = num % 8;
        char digit = sisa + '0';
        push(digit, s);
        num /= 8;
    }

    printf("Hasil konversi %d ke OKTAL = ",panggil);
    tampil(s);
}

void d_to_heksa(int num, stack *s){
    inisialisasi(s);
    int panggil = num;

    while (num > 0){
        int sisa = num % 16;
        char digit;
        if (sisa < 10){
            digit = sisa + '0';
        } else{
            digit = sisa - 10 + 'A';
        }
        push(digit, s);
        num /= 16;
    }

    printf("Hasil konversi %d ke HEKSADESIMAL = ",panggil);
    tampil(s);
}

void allmenu(){
        puts("\nKONVERSI BILANGAN DESIMAL");
        printf("Masukkan bil desimal yang akan dikonversi : ");
        scanf("%d",&in1);

    while (menu1 != 5){
        printf("\n\nMENU KONVERSI:\n1. BINER\n2. OKTAL\n3. HEKSADESIMAL\n4. Keluar\n");
        printf("Masukkan pilihan anda : ");
        scanf("%d",&menu1);
        fflush(stdin);
        menu_biner();
        menu_oktal();
        menu_heksadesimal();
        menu_exit();
    }
}

void menu_biner(){
    if(menu1 == 1){
        system("cls");
        d_to_biner(in1,&tumpukan);
    }
}


void menu_oktal(){
    if(menu1 == 2){
        system("cls");
        d_to_oktal(in1,&tumpukan);
    }
}

void menu_heksadesimal(){
    if(menu1 == 3){
        system("cls");
        d_to_heksa(in1,&tumpukan);
    }
}


void menu_exit(){
    if (menu1 == 4){
        puts("Terimakasih telah menggunakan aplikasi ini");
        exit(0);
    }
}
