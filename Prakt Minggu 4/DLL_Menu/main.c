#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul{
    int data;
    Dnode *prev,*next;
};
Dnode *head = NULL,*p,*tail,*after,*prev,*hapus,*tail,*bef;
int x;

void alokasi();
void d_awal();
void d_akhir();
void d_before();
void d_after();
void tampil();
void allmenu();
void menu_awal();
void menu_akhir();
void menu_before();
void menu_after();
void menu_exit();

int main()
{
    allmenu();
}

void alokasi(){
    int nilai;
    printf("Nilai yang akan disimpan : ");
    scanf("%d",&nilai);
    p = (Dnode *) malloc(sizeof(Dnode));
    if (p == NULL){
       puts("gagal");
       exit(0);
    } else {
        p -> data = nilai;
        p -> next = NULL;
    }
}

void d_awal(){
    if(head!=NULL){
        p -> next = head;
        head -> prev = p;
    }
    head = p;
}

void d_akhir(){
    if(head == NULL) {
        head = p;
    }
    else {
        tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        p->prev = tail;
        tail->next = p;
        tail=p;
    }
}

void d_before(){
    int key;
    if (head == NULL){
        puts("Masukkan DLL terlebih dahulu\n");
        allmenu();
    } else {
        alokasi();
        printf("Dimasukkan sebelum data ke : ");
        scanf("%d",&key);

            bef=head;
        if(bef->data == key){
            d_awal();
        } else {
        while(bef->data != key){
            if(bef->next == NULL){
                puts("Key tidak ditemukan");
                exit(0);
            } else {
                bef = bef->next;
            }
        }
        p->next = bef;
        p->prev = bef -> prev;
        bef->prev->next = p;
        bef->prev = p;
        }
    }
}

void d_after(){
    int key;
    if (head == NULL){
        puts("Masukkan DLL terlebih dahulu\n");
        allmenu();
    } else {
        alokasi();
        printf("Dimasukkan setelah data ke : ");
        scanf("%d", &key);
        after = head;
        while(after->data != key){
            if(after->next == NULL){
                printf("Key tidak ditemukan");
                exit(0);
            }
            else
                after = after->next;
        }
        if(after->next != NULL){
            p->next = after->next;
            after->next->prev = p;
        }
        p->prev = after;
        after->next = p;
    }
}

void tampil(){
    Dnode *baca;
    baca = head;
    puts("Data yang ada dalam SSL");
    while (baca != NULL){
        printf("%d\n",baca->data);
        (baca=baca->next);
    }
}

void allmenu(){
    while(x != 6) {
        puts("Menu Insert");
        printf("1. Insert Awal\n2. Insert Akhir\n3. Insert After\n4. Insert Before\n5. Keluar\n");
        printf("Masukkan pilihan anda : ");
        scanf("%d", &x);
        fflush(stdin);
        menu_awal();
        menu_akhir();
        menu_before();
        menu_after();
        menu_exit();
    }
}

void menu_awal(){
    if (x == 1){
        alokasi();
        d_awal();
        system("cls");
        tampil();
    }
}

void menu_akhir(){
    if (x == 2){
        alokasi();
        d_akhir();
        system("cls");
        tampil();
    }
}

void menu_after(){
    if (x == 3){
        d_after();
        system("cls");
        tampil();
    }
}

void menu_before(){
    if (x == 4){
        d_before();
        system("cls");
        tampil();
    }
}

void menu_exit(){
    if (x == 5){
        exit(0);
    }
}
