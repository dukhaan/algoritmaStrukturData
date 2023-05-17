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
void awal();
void akhir();
void before();
void after();
void hapus_awal();
void hapus_akhir();
void hapus_tertentu();
void tampil();
void bebaskan(Node *);
void tampil_semua();

int main()
{
    tampil_semua();
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
            exit(0);
        }
        else {
            after = after->next;
        }
    }
    p->next = after->next;
    after->next = p;
}

void hapus_awal(){
    hapus = head;
    if(hapus == NULL){
        puts("Masukkan SLL Terlebih Dahulu");
    } else {
        if(head->next == NULL)
        head = NULL;
        else{
            head = hapus->next;
            bebaskan(hapus);
        }
    }

}

void hapus_akhir(){
    hapus = head;
    if(hapus == NULL){
        puts("Masukkan SLL Terlebih Dahulu");
        head = NULL;
    }
    else{
        while(hapus->next != NULL){
            phapus = hapus;
            hapus = hapus -> next;
        }
        phapus->next = NULL;
    }
    bebaskan(hapus);
}

void hapus_tertentu(){
    int x;
    printf("Data yang mau dihapus : ");
    scanf("%d",&x);

    hapus = head;
    if(hapus -> no == x){
        hapus_awal();
    } else {
        while (hapus -> no != x){
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
    Node *baca;
    baca = head;
    printf("No\t\tNama\t\tNilai\n");

    while (baca != NULL){
        printf("%d\t\t%s\t\t%g\n",baca->no,baca->nama,baca->nilai);
        (baca=baca->next);
    }
}

void tampil_semua(){
    puts("SLL MENU DELETE - data struct");
    puts("Linked list untuk aplikasi INSERT DI AKHIR");

    char jwb;
    int menu1,menu2,menu3;
    while (menu1 != 3){
        puts("Menu SLL");
        printf("1. Insert\n2. Delete\n3. Exit \n");
        printf("Masukkan pilihan anda : ");
        scanf("%d",&menu1);
        fflush(stdin);
        if(menu1 == 1){
            {
        puts("Menu Insert");
        printf("1.insert awal\n2.insert akhir\n3.insert after\n4.insert before\n");
        printf("Masukkan pilihan anda : ");
        scanf("%d", &menu2);
        fflush(stdin);
        switch(menu2){
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
        if(menu1 == 2){
            {
        puts("Menu Delete");
        printf("1.Delete awal\n2.Delete akhir\n3.Delete Tertentu\n");
        printf("Masukkan pilihan anda : ");
        scanf("%d", &menu3);
        fflush(stdin);
        switch(menu3){
            case 1:
                hapus_awal();
                system("cls");
                tampil();
                break;

            case 2:
                hapus_akhir();
                system("cls");
                tampil();
                break;
            case 3:
                hapus_tertentu();
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
        if(menu1 == 3){
            exit(0);
        }
    }
}
