#include <stdio.h>
#include <stdlib.h>
#define MAKS 20

typedef struct simpul Dnode;
struct simpul{
    int no;
    Dnode *prev,*next;
    char nama[MAKS];
    float nilai;
};
Dnode *head = NULL,*p,*tail,*after,*prev,*hapus,*tail,*bef,*phapus;

//variable global
int nilai,no, menu1;

//big boss
void allmenu();
//fungsi alokasi dan baca
void alokasi();
void hapus_awal();
void tampil();
void bebaskan(Dnode *);
//fungsi utama
void penambahan_urut();
void pencarian_data();
void penghapusan_data();
void rerata();
//fungsi menu
void menu_penambahan_urut();
void menu_pencarian_data();
void menu_penghapusan_data();
void menu_rerata();
void menu_exit();





//=======================================BIG_BOSS======================================================================

int main()
{
    allmenu();
}

//=================================ALOKASI_DAN_BACA=====================================================================


void bebaskan(Dnode *x){
    free(x);
    x = NULL;
}

void alokasi(){

    p = (Dnode *) malloc(sizeof(Dnode));

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

void tampil(){
    Dnode *baca;
    baca = head;
    printf("No\t\tNama\t\tNilai\n");

    while (baca != NULL){
        printf("%d\t\t%s\t\t%g\n",baca->no,baca->nama,baca->nilai);
        (baca=baca->next);
    }
}

//=================================F U N G S I__U T A M A=====================================================================


void hapus_awal(){
    hapus = head;
    if(hapus == NULL){
        puts("Masukkan SLL terlebih dahulu");
    } else {
           hapus = head;
            if(hapus->next == NULL){
                head = NULL;
            } else{
                head=hapus->next;
                hapus->next->prev=NULL;
                bebaskan(hapus);
        }
    }

}

void penambahan_urut(){
    if(head == NULL || p->no < head->no) {
        p->next = head;
        if(head != NULL){
            head->prev = p;
        }
        head = p;
    }
    else {
        tail = head;
        while(tail->next != NULL && tail->next->no < p->no) {
            tail = tail->next;
        }
        p->next = tail->next;
        p->prev = tail;
        if(tail->next != NULL){
            tail->next->prev = p;
        }
        tail->next = p;
    }
}

void pencarian_data()
{
    int data, ketemu = 0;
    Dnode *cari;

    printf("Data Yang Dicari: ");
    scanf("%d", &data);

    cari = head;
    while(cari != NULL)
    {
        if(cari->no == no)
            ketemu++;
        cari = cari->next;
    }

    if(ketemu >= 1)
        printf("Data %d ditemukan sebanyak %d Kali\n", data, ketemu);
    else
        printf("Data %d tidak ditemukan\n",data);
}

void penghapusan_data(){
    int x;

    if(head == NULL){
        puts("Masukkan DLL terlebih dahulu");
        allmenu();
    } else{
        printf("Data yang mau dihapus : ");
        scanf("%d",&x);

        hapus = head;
        if(hapus -> no == x){
            hapus_awal();
        } else {
            while (hapus != NULL && hapus -> no != x){
                phapus = hapus;
                hapus = hapus -> next;
            }
            if(hapus == NULL){
                printf("%d tidak ada dalam SLL",x);
                allmenu();
            } else {
                phapus -> next = hapus -> next;
                if(hapus -> next != NULL){
                    hapus->next->prev = hapus;
                }
                bebaskan(hapus);
            }
        }
    }
}


void rerata(){
        if(head == NULL){
            puts("DLL Kosong, masukkan data dahulu");
            allmenu();
            } else {
                int nilai = p->no;
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
                printf("Harap masukkan DLL terlebih dahulu\n");
                allmenu();
            }
        }


}



//=================================M E N U=====================================================================


void allmenu(){

    while (menu1 != 6){
        puts("\nMENU UTAMA - DOUBLE LINKED LIST");
        printf("1. Penambahan secara terurut\n2. Pencarian Data\n3. Penghapusan data\n4. Nilai rata-rata kelas\n5. Exit \n");
        printf("Masukkan pilihan anda : ");
        scanf("%d",&menu1);
        fflush(stdin);
        menu_penambahan_urut();
        menu_pencarian_data();
        menu_penghapusan_data();
        menu_rerata();
        menu_exit();
    }
}

void menu_penambahan_urut(){
    if(menu1 == 1){
        alokasi();
        penambahan_urut();
        system("cls");
        tampil();
    }
}

void menu_pencarian_data(){
    if(menu1 == 2){
        pencarian_data();
    }
}

void menu_penghapusan_data(){
    if(menu1 == 3){
        penghapusan_data();
        system("cls");
        tampil();
    }
}

void menu_rerata(){
    if(menu1 == 4){
        rerata();
    }
}

void menu_exit(){
    if (menu1 == 5){
        puts("Terimakasih telah menggunakan aplikasi ini");
        exit(0);
    }
}


