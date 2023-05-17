#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};

void alokasi();
void akhir();
void hapus_awal();
void hapus_tertentu();
void tampil();
void bebaskan(Node *);
Node *head = NULL,*p,*tail, *hapus, *phapus;
Node *baca;
int x;


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
    puts("Setelah Hapus Bagian Tertentu");
    fflush(stdin);
    hapus_tertentu();
    tampil();
    return 0;
}

void bebaskan(Node *x){
    free(x);
    x = NULL;
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

void hapus_awal(){
    hapus = head;
    if(head->next == NULL)
        head = NULL;
    else{
        head = hapus->next;
        bebaskan(hapus);
    }
}

void hapus_tertentu(){
    printf("Data yang mau dihapus : ");
    scanf("%d",&x);

    hapus = head;
    if(hapus -> data == x){
        hapus_awal();
    } else {
        while (hapus -> data != x){
            if(hapus -> next == NULL){
                printf("%d tidak ada dalam SLL",x);
                exit(0);
            } else {
                phapus = hapus;
                hapus = hapus -> next;
                }
            }
            phapus -> next = hapus -> next;
            bebaskan(hapus);
        }
    }

void tampil(){
    baca = head;
    printf("Hasil dari SSL : \n");
    while (baca != NULL){
        printf("%d\n",baca->data);
        (baca=baca->next);
    }
    puts("");
}
