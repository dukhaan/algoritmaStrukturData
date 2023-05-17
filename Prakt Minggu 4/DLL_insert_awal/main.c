#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul{
    int data;
    Dnode *prev, *next;
};

Dnode *head = NULL,*p;
void alokasi();
void d_awal();
void tampil();


int main()
{
    char jwb;

    puts("Double Linked list - Insert awal");

    do{
        fflush(stdin);
        alokasi();
        d_awal();
        fflush(stdin);
        printf("Mau memasukkan data lagi (y/t) :");
        scanf("%c",&jwb);
        fflush(stdin);
    } while (jwb == 'y');
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

void d_awal(){

    if(head!=NULL){
        p -> next = head;
        head -> prev = p;
    }
    head = p;
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
