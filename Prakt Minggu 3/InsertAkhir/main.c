#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

void alokasi();
void akhir();
void tampil();
Node *head = NULL,*p,*tail;


int main()
{
    char jwb;

    puts("Single Linked list - Insert akhir");

    do{
        fflush(stdin);
        alokasi();
        akhir();
        fflush(stdin);
        printf("Lagi? [y/t]: ");
        scanf("%c",&jwb);
        fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');
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

void akhir(){
    if(head == NULL) {
        head = p;
    }
    else {
        tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = p;
    }
}

void tampil(){
    Node *baca;
    baca = head;
    while (baca != NULL){
        printf("%d\n",baca->data);
        (baca=baca->next);
    }
}
