#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

Node *head = NULL,*p;
Node *baca;
void alokasi();
void awal();
void tampil();

int main()
{
    char jwb;

    puts("Single Linked list - Insert awal");

    do{
        fflush(stdin);
        alokasi();
        awal();
        fflush(stdin);
        printf("Mau memasukkan data lagi (y/t) :");
        scanf("%c",&jwb);
        fflush(stdin);
    } while (jwb == 'y');
    tampil();
    return 0;
}

void alokasi(){
    int nilai;


    printf("Nilai yang akan disimpan : ");
    scanf("%d",&nilai);
    p = (Node *) malloc(sizeof(Node));
    if (p == NULL){
       puts("gagal");
       exit(0);
    } else {
        p -> data = nilai;
        p -> next = NULL;
    }
}

void awal(){
    if(head != NULL)
        p -> next = head;
    head = p;
}

void tampil(){
    baca = head;
    while (baca != NULL){
        printf("%d\n",baca->data);
        (baca=baca->next);
    }
}
