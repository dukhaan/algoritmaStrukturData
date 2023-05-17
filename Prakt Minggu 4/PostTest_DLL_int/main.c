#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul{
    int data;
    Dnode *prev,*next;
};
Dnode *head = NULL,*p,*tail,*after,*prev,*hapus,*tail,*bef,*phapus;

//variable global
int nilai, menu1;

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
//funngsi menu
void menu_penambahan_urut();
void menu_pencarian_data();
void menu_penghapusan_data();
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
    printf("Nilai yang akan disimpan : ");
    scanf("%d",&nilai);
    p = (Dnode *) malloc(sizeof(Dnode));
    if (p == NULL){
       puts("Alokasi gagal");
       exit(0);
    } else {
        p -> data = nilai;
        p -> next = NULL;
    }
}

void tampil(){
    Dnode *baca;
    baca = head;
    puts("Data yang ada dalam SSL");
    while (baca != NULL){
        printf("%d ",baca->data);
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
    if(head == NULL || nilai < head->data) {
        p->next = head;
        if(head != NULL){
            head->prev = p;
        }
        head = p;
    }
    else {
        tail = head;
        while(tail->next != NULL && tail->next->data < nilai) {
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
    if(head==NULL){
        puts("DLL KOSONG masukkan data");
        allmenu();
        } else {
            int data, ketemu = 0;
        Dnode *cari;

        printf("Data Yang Dicari: ");
        scanf("%d", &data);

        cari = head;
        while(cari != NULL)
        {
            if(cari->data == data)
                ketemu++;
            cari = cari->next;
        }

        if(ketemu >= 1)
            printf("Data %d ditemukan sebanyak %d Kali\n", data, ketemu);
        else
            printf("Data %d tidak ditemukan\n",data);
    }

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
        if(hapus -> data == x){
            hapus_awal();
        } else {
            while (hapus != NULL && hapus -> data != x){
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


//=================================M E N U=====================================================================


void allmenu(){

    while (menu1 != 5){
        puts("\nMENU UTAMA - DOUBLE LINKED LIST");
        printf("1. Penambahan secara terurut\n2. Pencarian Data\n3. Penghapusan data\n4. Exit \n");
        printf("Masukkan pilihan anda : ");
        scanf("%d",&menu1);
        fflush(stdin);
        menu_penambahan_urut();
        menu_pencarian_data();
        menu_penghapusan_data();
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

void menu_exit(){
    if (menu1 == 4){
        puts("Terimakasih telah menggunakan aplikasi ini");
        exit(0);
    }
}


