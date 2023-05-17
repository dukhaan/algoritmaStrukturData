#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};
Node *head = NULL,*p,*tail;
Node *baca;
void alokasi();
void tampil();
void awal();

int main()
{
    char jwb;

    puts ("SLL LInked list - insert awal");

    do{
        fflush(stdin);
        alokasi();
        awal();
        fflush(stdin);
        printf("Mau memasukkan data lagi [y/t] : ");
        jwb = getchar();
        fflush(stdin);
    } while (jwb == 'y');
    tampil();

    return 0;
}

void alokasi(){
    int nilai;

    printf("Masukkan nilai : ");
    scanf("%d",&nilai);
    p = (Node *) malloc (sizeof(Node));
    if(p == NULL){
        puts("Alokasi Gagal");
        exit(0);
    } else {
        p->data = nilai;
        p->next = NULL;
    }
}

void awal(){
    if (head != NULL){
        p->next=head;
    }
        head=p;
}

void tampil(){
    baca=head;
    while (baca!=NULL){
        printf("%d\n",baca->data);
        baca=baca->next;
    }
}
