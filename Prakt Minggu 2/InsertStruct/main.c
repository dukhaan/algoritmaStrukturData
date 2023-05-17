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

Node *head = NULL,*p;
void alokasi();
void awal();
void tampil();



int main()
{
    puts("Linked list untuk aplikasi INSERT DI AWAL");
    puts("Membentuk lined list dg Insert di awal");

    char jwb;

    do{
    fflush(stdin);
    alokasi();
    awal();
    fflush(stdin);
    printf("Ada data lagi (y/t) : ");
    scanf("%c",&jwb);
    fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');
        tampil();


    return 0;
}

void inputan(){

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
        fflush(stdin);
    }
}

void awal(){

    if(head != NULL)
        p -> next = head;
    head = p;
}

void tampil(){
    Node *baca;
    baca = head;
    printf("No\t\tNama\t\tNilai\n");

    while (baca != NULL){
        printf("%d\t\t%s\t\t%g",baca->no,baca->nama,baca->nilai);
        (baca=baca->next);
    }
}

