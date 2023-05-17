#include <stdio.h>
#include <stdlib.h>

typedef char itemType;

typedef struct node {
    itemType data;
    struct node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void inisialisasi(Stack *s);
int empty(Stack *s);
void push(itemType x, Stack *s);
itemType pop(Stack *s);

void tampil(Stack *s);

void allmenu();
void menu_push(Stack *s);
void menu_pop(Stack *s);
void menu_tampil(Stack *s);
void menu_exit();

char menu1;
itemType x;
Stack tumpukan;

int main(){
    inisialisasi(&tumpukan);
    allmenu();
    return 0;
}

void inisialisasi(Stack *s){
    s->top = NULL;
}

int empty(Stack *s){
    return (s->top == NULL);
}

void push(itemType x, Stack *s){
    Node *p = malloc(sizeof(Node));
    if (p == NULL) {
        printf("Alokasi memori gagals.\n");
        return;
    }
    p->data = x;
    p->next = s->top;
    s->top = p;
}

itemType pop(Stack *s){
    if (empty(s)) {
        printf("Stack Kosong, tidak dapat mengambil data\n");
        return '\0';
    } else{
        Node *temp = s->top;
        s->top = s->top->next;
        itemType result = temp->data;
        free(temp);
        printf("Data yang di pop : %c\n", result);
    }
}

void tampil(Stack *s){
    Node *baca = s->top;
    if(empty(s)){
        puts("Stack kosong, Masukkan data terlebih dahulu");
        allmenu();
    } else{
        puts("Isi dari Stack :");
        while (baca != NULL) {
            printf("%c\n", baca->data);
            baca = baca->next;
        }
    }
}

void allmenu(){
    while (menu1 != 4) {
        puts("\nMENU STACK - LINKED LIST");
        printf("1. Mengisi Stack (PUSH)\n2. Mengambil Isi Stack(POP)\n3. Menampilkan isi stack -> LIFO\n4. Keluar\n");
        printf("Masukkan pilihan anda : ");
        scanf("%d", &menu1);
        fflush(stdin);
        menu_push(&tumpukan);
        menu_pop(&tumpukan);
        menu_tampil(&tumpukan);
        menu_exit();
    }
}

void menu_push(Stack *s){
    if (menu1 == 1) {
        printf("Masukkan elemen : ");
        x = getchar();
        push(x, s);
    }
}

void menu_pop(Stack *s){
    if (menu1 == 2) {
        system("cls");
        pop(s);
    }
}

void menu_tampil(Stack *s){
    if (menu1 == 3) {
        system("cls");
        tampil(s);
    }
}

void menu_exit(){
    if (menu1 == 4) {
        puts("Terimakasih telah menggunakan aplikasi ini");
        exit(0);
    }
}
