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

Node *head = NULL,*p,*tail;
void alokasi();
void akhir();
void before();
void tampil();



int main()
{
    puts("Linked list untuk aplikasi INSERT BEFORE");
    puts("Membentuk linked list dg Insert di Akhir");

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
        before();
        tampil();
    return 0;
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

void before(){
    Node *bef;
    Node *pbef;
    int x;
    printf("Disisipkan sebelum data berapa : ");
    scanf("%d", &x);
    alokasi();
    bef = head;
    while(bef->no != x) {
        if(bef->next == NULL) {
            puts("gagal!");
        }
        else {
            pbef = bef;
            bef = bef->next;
        }
    }
    p->next = bef;
    pbef->next = p;
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

