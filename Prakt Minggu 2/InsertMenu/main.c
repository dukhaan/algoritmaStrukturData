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
void after();
void tampil();
Node *head = NULL,*p,*tail;


int main()
{
    char jwb;
    int x;
    while(x != 5) {
        puts("Menu Insert");
        printf("1.insert awal\n2.insert akhir\n3.insert after\n4.insert before\n5.keluar\n");
        printf("Masukkan pilihan anda : ");
        scanf("%d", &x);
        fflush(stdin);
        switch(x){
            case 1:
                do
                {
                    alokasi();
                    printf("Tambah Data [y/n] ? :");
                    scanf("%c", &jwb);
                    fflush(stdin);
                    awal();
                } while (jwb == 'y');
                system("cls");
                tampil();
                break;

            case 2:
                do
                {
                    alokasi();
                    printf("Tambah Data ? [y/n] :");
                    scanf("%c", &jwb);
                    fflush(stdin);
                    akhir();
                } while (jwb == 'y');
                system("cls");
                tampil();
                break;
            case 3:
                after();
                system("cls");
                tampil();
                break;
            case 4:
                before();
                system("cls");
                tampil();
                break;
            default:
                system("cls");
                puts("Input salah");
                break;
        }
    }
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
    puts("Data yang ada dalam SSL");
    while (baca != NULL){
        printf("%d\n",baca->data);
        (baca=baca->next);
    }
}
