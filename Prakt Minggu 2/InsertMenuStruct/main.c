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
void awal();
void akhir();
void before();
void after();
void tampil();



int main()
{
    puts("Linked list untuk aplikasi INSERT AFTER");
    puts("Membentuk linked list dg Insert di Akhir");

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
                do{
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
                do{
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

void after(){
    Node *after;
    int x;
    printf("Disisipkan setelah data ke berapa : ");
    scanf("%d", &x);
    alokasi();
    after = head;
    while(after->no != x) {
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
            exit(0);
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

