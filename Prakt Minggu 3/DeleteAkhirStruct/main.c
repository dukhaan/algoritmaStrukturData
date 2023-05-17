#include <stdio.h>
#include <stdlib.h>
#define MAKS 20

typedef struct siswa Node;
struct siswa{
    int no;
    char nama[MAKS];
    float nilai;
    Node *next;
};

Node *head = NULL,*p,*tail,*hapus,*phapus;
void alokasi();
void akhir();
void hapus_awal();
void hapus_akhir();
void after();
void bebaskan(Node *);
void tampil();



int main()
{
    puts("SLL DELETE AKHIR - data struct");
    puts("Linked list untuk aplikasi INSERT DI AKHIR");

    char jwb;

    do{
    fflush(stdin);
    alokasi();
    akhir();
    fflush(stdin);
    printf("Ada data lagi (y/t) : ");
    scanf("%c",&jwb);
    fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');
        hapus_akhir();
        tampil();
    return 0;
}

void bebaskan(Node *x){
    free(x);
    x = NULL;
}

void alokasi(){

    p = (Node *) malloc(sizeof(Node));

    if (p == NULL){
       puts("gagal");
       exit(0);
    } else {
        printf("No    : ");
        scanf("%d",&p -> no);
        fflush(stdin);
        printf("Nama  : ");
        gets(p->nama);
        fflush(stdin);
        printf("Nilai : ");
        scanf("%f",&p -> nilai);
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

void hapus_akhir(){
    hapus = head;
    if(hapus == NULL)
        head = NULL;
    else{
        while(hapus->next != NULL){
            phapus = hapus;
            hapus = hapus -> next;
        }
        phapus->next = NULL;
    }
    bebaskan(hapus);
}

void tampil(){
    Node *baca;
    baca = head;
    printf("No\t\tNama\t\tNilai\n");

    while (baca != NULL){
        printf("%d\t\t%s\t\t%g\n",baca->no,baca->nama,baca->nilai);
        (baca=baca->next);
    }
}

