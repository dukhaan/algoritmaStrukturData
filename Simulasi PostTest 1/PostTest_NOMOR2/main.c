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
Node *head = NULL,*p,*tail,*phapus,*hapus;

int no, menu1;
float nilai;
char nama[MAKS];

void allmenu();
void menu_1();
void menu_2();
void menu_3();
void menu_4();
void menu_5();
void alokasi();
void hapus_awal();
void tampil();
void bebaskan(Node *);
void penambahan_urut();
void pencarian_data();
void penghapusan_data();
void rerata();


int main()
{
    allmenu();
}


void bebaskan(Node *x){
    free(x);
    x = NULL;
}

void alokasi(){

    p = (Node *) malloc(sizeof(Node));

    if (p == NULL){
       puts("Alokasi Gagal");
       exit(0);
    } else {
        printf("No    : ");
        scanf("%d",&p->no);
        fflush(stdin);
        printf("Nama  : ");
        gets(p->nama);
        fflush(stdin);
        printf("Nilai : ");
        scanf("%f",&p->nilai);
    }
}


void hapus_awal(){
    hapus = head;
    if(hapus == NULL){
        puts("Masukkan SLL terlebih dahulu");
    } else {
        if(head->next == NULL)
        head = NULL;
        else{
            head = hapus->next;
            bebaskan(hapus);
        }
    }
}

void penambahan_urut(){
    if(head == NULL || p->no < head->no) {
        p->next = head;
        head = p;
    }
    else {
        tail = head;
        while(tail->next != NULL && tail->next->no < p->no) {
            tail = tail->next;
        }
        p->next = tail->next;
        tail->next = p;
    }
}

void pencarian_data()
{
    int no, ketemu = 0;
    Node *cari;

    printf("Data Yang Dicari: ");
    scanf("%d", &no);

    cari = head;
    while(cari != NULL)
    {
        if(cari->no == no)
            ketemu++;
        cari = cari->next;
    }

    if(ketemu >= 1)
        printf("Data %d ditemukan sebanyak %d Kali\n", no, ketemu);
    else
        printf("Data %d tidak ditemukan\n",no);

}

void penghapusan_data(){
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
                allmenu();
            } else {
                phapus = hapus;
                hapus = hapus -> next;
                }
            }
            phapus -> next = hapus -> next;
            bebaskan(hapus);
        }
}

void rerata(){
    int hitung=0;
    float rata=0;
    p = head;
    while (p != NULL){
        hitung++;
        rata += p->nilai;
        p = p->next;
    }
    if(hitung != 0){
        float x = rata/hitung;
        printf("Rata rata : %.2f\n",x);
        allmenu();
    } else{
        printf("Harap masukkan SLL terlebih dahulu\n");
        allmenu();
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

void allmenu(){

    while (menu1 != 5){
        puts("\nMENU UTAMA");
        printf("1. Penambahan secara terurut\n2. Pencarian Data\n3. Penghapusan data\n4. Nilai rata-rata kelas\n5. Exit \n");
        printf("Masukkan pilihan anda : ");
        scanf("%d",&menu1);
        fflush(stdin);
        menu_1();
        menu_2();
        menu_3();
        menu_4();
        menu_5();
    }
}

void menu_1(){
    if(menu1 == 1){
            {
                fflush(stdin);
                alokasi();
                fflush(stdin);
                penambahan_urut();
                system("cls");
                tampil();
                fflush(stdin);
            }
    }
}

void menu_2(){
    if(menu1 == 2){
        pencarian_data();
    }
}

void menu_3(){
    if(menu1 == 3){
        if(head == NULL){
            puts("Masukkan SLL terlebih dahulu");
        } else {
            penghapusan_data();
                system("cls");
                tampil();
        }

    }
}

void menu_4(){
    if(menu1 == 4){
        rerata();
    }
}

void menu_5(){
    if (menu1 == 5){
        exit(0);
    }
}


