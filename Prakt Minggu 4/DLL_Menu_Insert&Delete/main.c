#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul{
    int data;
    Dnode *prev,*next;
};
Dnode *head = NULL,*p,*tail,*after,*prev,*hapus,*tail,*bef;
int x,y;

void alokasi();
void d_awal();
void d_akhir();
void d_before();
void d_after();
void d_delete_awal();
void d_delete_akhir();
void d_delete_tertentu();
void tampil();
void allmenu();
void menu_insert();
void menu_delete();
void menu_awal();
void menu_akhir();
void menu_before();
void menu_after();
void menu_delete_awal();
void menu_delete_akhir();
void menu_delete_tertentu();
void bebaskan(Dnode *);
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
        if(head == NULL){
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
    if(head == NULL){
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

void bebaskan(Dnode *x){
    free(x);
    x = NULL;
}

void d_delete_awal(){
    hapus = head;
    if(hapus->next == NULL){
        head = NULL;
    } else{
        head=hapus->next;
        hapus->next->prev=NULL;
        bebaskan(hapus);
    }
}

void d_delete_akhir(){
    hapus = head;
    if(hapus->next == NULL){
        head = NULL;
    } else{
            while(hapus->next != NULL) {
            hapus = hapus -> next;
        }
        hapus -> prev -> next = NULL;
        bebaskan(hapus);
    }
}

void d_delete_tertentu(){
    int key;
    printf("Masukkan key : ");
    scanf("%d",&key);

    hapus = head;
    if(hapus->data == key){
        d_delete_awal();
    } else{
    while(hapus->data != key){
        if (hapus -> next == NULL){
            puts("Key tidak ada dalam DLL");
            exit(0);
        }else{
            hapus = hapus -> next;
            }
        }
        hapus->prev->next=hapus->next;
    if(hapus->next != NULL)
            hapus->next->prev=hapus->prev;
    bebaskan(hapus);
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
    while(x != 3) {
        puts("Menu Utama");
        printf("1. Insert\n2. Delete\n3. Keluar\n");
        printf("Masukkan pilihan anda : ");
        scanf("%d", &x);
        fflush(stdin);
        menu_insert();
        menu_delete();
        menu_exit();
    }
}

void menu_insert(){
        if (x == 1){
           while(y != 5) {
            puts("Menu Insert");
            printf("1. Insert Awal\n2. Insert Akhir\n3. Insert After\n4. Insert Before\n");
            printf("Masukkan pilihan anda : ");
            scanf("%d", &y);
            fflush(stdin);
            menu_awal();
            menu_akhir();
            menu_before();
            menu_after();
        }
    }
}

void menu_delete(){
    if(x == 2){
        if(head == NULL){
            puts("Masukkan DLL terlebih dahulu\n");
            allmenu();
        } else {
                while(y != 4) {
                puts("Menu Delete");
                printf("1. Delete Awal\n2. Delete Akhir\n3. Delete Tertentu\n");
                printf("Masukkan pilihan anda : ");
                scanf("%d", &y);
                fflush(stdin);
                menu_delete_awal();
                menu_delete_akhir();
                menu_delete_tertentu();
            }
        }

    }
}

void menu_awal(){
    if (y == 1){
        alokasi();
        d_awal();
        system("cls");
        tampil();
        allmenu();
    }
}

void menu_akhir(){
    if (y == 2){
        alokasi();
        d_akhir();
        system("cls");
        tampil();
        allmenu();
    }
}

void menu_after(){
    if (y == 3){
        d_after();
        system("cls");
        tampil();
        allmenu();
    }
}

void menu_before(){
    if (y == 4){
        d_before();
        system("cls");
        tampil();
        allmenu();
    }
}

void menu_delete_awal(){
    if (y == 1){
        d_delete_awal();
        system("cls");
        tampil();
        allmenu();
    }
}

void menu_delete_akhir(){
    if (y == 2){
        d_delete_akhir();
        system("cls");
        tampil();
        allmenu();
    }
}

void menu_delete_tertentu(){
    if (y == 3){
        d_delete_tertentu();
        system("cls");
        tampil();
        allmenu();
    }
}

void menu_exit(){
    if (x == 3){
        exit(0);
    }
}
