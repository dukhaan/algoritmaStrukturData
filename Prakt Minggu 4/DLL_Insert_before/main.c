#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul{
    int data;
    Dnode *prev, *next;
};

Dnode *head = NULL,*p,*after, *prev, *tail, *bef, *pbef;
void alokasi();
void d_akhir();
void d_before();
void tampil();


int main()
{
    char jwb;

    puts("Double Linked list - Insert Before");

    do{
        fflush(stdin);
        alokasi();
        d_akhir();
        fflush(stdin);
        printf("Mau memasukkan data lagi (y/t) :");
        scanf("%c",&jwb);
        fflush(stdin);
    } while (jwb == 'y');
    tampil();
    puts("Insert before...");
    fflush(stdin);
    d_before();
    tampil();
    return 0;
}

void alokasi(){
    int x;
    printf("Angka yang mau diisi : ");
    scanf("%d",&x);

    p = (Dnode *) malloc (sizeof (Dnode));
    if(p==NULL){
        puts("Alokasi Gagal");
        exit(0);
    } else {
        p -> data = x;
        p -> next = NULL;
        p -> prev = NULL;
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
    alokasi();
    int key;
    printf("Masukkan key : ");
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

void tampil(){
    Dnode *baca;

    puts("Isi dari DLL");
    baca = head;
    while (baca != NULL){
        printf("%d\n",baca->data);
        baca=baca->next;
    }
}
