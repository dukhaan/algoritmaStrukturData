#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

void alokasi();
void akhir();
void after();
void tampil();
Node *head = NULL,*p,*tail;


int main()
{
    char jwb;

    puts("Single Linked list - Insert After");

    do
    {
        alokasi();
        printf("Lagi? [y/t]: ");
        fflush(stdin);
        scanf("%c", &jwb);
        akhir();
    } while (jwb == 'y' || jwb == 'Y');
    after();
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

void after(){
    Node *after;
    int x;
    printf("Disisipkan setelah data ke berapa : ");
    scanf("%d", &x);
    alokasi();
    after = head;
    while(after->data != x) {
        if(after->next == NULL) {
            puts("Gagal");
        }
        else {
            after = after->next;
        }
    }
    p->next = after->next;
    after->next = p;
}

void tampil(){
    Node *baca;
    baca = head;
    while (baca != NULL){
        printf("%d\n",baca->data);
        (baca=baca->next);
    }
}
