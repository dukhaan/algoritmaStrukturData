#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};
Node *head = NULL, *p, *tail;
Node *baca;

void alokasi();
void tampil();
void akhir();

int main()
{
    char jwb;

    do{
        fflush(stdin);
        alokasi();
        akhir();
        fflush(stdin);
        printf("Ingin memasukkan data lagi [y/t] : ");
        jwb=getchar();
        fflush(stdin);
    }while(jwb == 'y');
    tampil();
    return 0;
}

void alokasi(){
    int nilai;
    printf("Masukkan nilai : ");
    scanf("%d",&nilai);

    p=(Node *) malloc (sizeof(Node));
    if (p == NULL){
        puts("Alokasi p gagal");
        exit(0);
    } else{
        p->data = nilai;
        p->next = NULL;
    }
}

void akhir(){
    if (head == NULL){
        head = p;
    } else {
        tail=head;
        while (tail->next != NULL){
            tail=tail->next;
        }
            tail->next=p;
    }
}

void tampil(){
    baca=head;
    while(baca!=NULL){
        printf("%d\n",baca->data);
        baca=baca->next;
    }
}
