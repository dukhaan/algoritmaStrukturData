#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

void alokasi();
void awal();
void akhir();
void before();
void tampil();
Node *head = NULL,*p,*tail;
int x;


int main()
{
    char jwb;

    puts("Single Linked list - Insert Before");

    do
    {
        alokasi();
        printf("Lagi? [y/t]: ");
        fflush(stdin);
        scanf("%c", &jwb);
        akhir();
    } while (jwb == 'y' || jwb == 'Y');
    before();
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

void before(){
    Node *bef;
    Node *pbef;
    int x;
    printf("Disisipkan sebelum data berapa : ");
    scanf("%d", &x);
    alokasi();
    bef = head;
    if(bef->data == x){
        awal();
    } else {
        while(bef->data != x) {
        if(bef->next == NULL) {
            puts("gagal!");
        }
        else {
            pbef = bef;
            bef = bef->next;
        }
    }
    }
    p->next = bef;
    pbef->next = p;
}

void tampil(){
    Node *baca;
    baca = head;
    puts("Data yang ada dalam SSL");
    while (baca != NULL){
        printf("%d\n",baca->data);
        (baca=baca->next);
    }
}
