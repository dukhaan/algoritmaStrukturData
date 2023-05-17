#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul{
    int data;
    Dnode *prev, *next;
};

Dnode *head = NULL,*p,*after, *prev, *tail;
void alokasi();
void d_akhir();
void d_after();
void tampil();


int main()
{
    char jwb;

    puts("Double Linked list - Insert after");

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
    puts("Insert after...");
    fflush(stdin);
    alokasi();
    fflush(stdin);
    d_after();
    tampil();
    return 0;
}

void alokasi(){
    int x;
    printf("Data yang mau diisi : ");
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

void d_after(){
    int key;
    alokasi();
    printf("Disisipkan AFTER Node Berapa? : ");
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

void tampil(){
    Dnode *baca;

    puts("Isi dari DLL");
    baca = head;
    while (baca != NULL){
        printf("%d\n",baca->data);
        baca=baca->next;
    }
}
