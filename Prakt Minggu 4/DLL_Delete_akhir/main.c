#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul{
    int data;
    Dnode *prev, *next;
};
Dnode *head = NULL,*p,*after, *prev, *hapus, *tail;

void alokasi();
void d_awal();
void d_akhir();
void d_after();
void tampil();
void d_delete_akhir();
void bebaskan(Dnode *);


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
    puts("Menghapus Node terakhir...");
    d_delete_akhir();
    tampil();
    return 0;
}

void bebaskan(Dnode *x){
    free(x);
    x = NULL;
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

void d_after(){
    int key, stop=0;
    printf("Dimasukkan setelah data ke : ");
    scanf("%d",&key);

    after = head;
    while (after->data != key){
        if(after->next == NULL){
            puts("Key tidak ditemukan");
            stop = 1;
        }else{
        after=after->next;
        }
    }
    if(!stop){
        p->next = after->next;
        p->prev = after;
        if(after->next != NULL)
            after -> next -> prev = p;
        after -> next = p;
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

void tampil(){
    Dnode *baca;

    puts("Isi dari DLL");
    baca = head;
    while (baca != NULL){
        printf("%d\n",baca->data);
        baca=baca->next;
    }
}
