#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};
Node *head = NULL,*p,*tail,*phapus,*hapus;

int nilai, menu1;

void allmenu();
void menu_1();
void menu_2();
void menu_3();
void menu_4();
void alokasi();
void hapus_awal();
void tampil();
void bebaskan(Node *);
void penambahan_urut();
void pencarian_data();
void penghapusan_data();


int main()
{
    allmenu();
}


void bebaskan(Node *x){
    free(x);
    x = NULL;
}

void alokasi(){



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
    if(head == NULL || nilai < head->data) {
        p->next = head;
        head = p;
    }
    else {
        tail = head;
        while(tail->next != NULL && tail->next->data < nilai) {
            tail = tail->next;
        }
        p->next = tail->next;
        tail->next = p;
    }
}

void pencarian_data()
{
    int data, ketemu = 0;
    Node *cari;

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

void penghapusan_data(){
    int x;
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
    Node *baca;
    baca = head;
    puts("Data yang ada dalam SSL");
    while (baca != NULL){
        printf("%d ",baca->data);
        (baca=baca->next);
    }
}

void allmenu(){

    while (menu1 != 4){
        puts("\nMENU UTAMA");
        printf("1. Penambahan secara terurut\n2. Pencarian Data\n3. Penghapusan data\n4. Exit \n");
        printf("Masukkan pilihan anda : ");
        scanf("%d",&menu1);
        fflush(stdin);
        menu_1();
        menu_2();
        menu_3();
        menu_4();
    }
}

void menu_1(){
    if(menu1 == 1){

            {
                alokasi();
                penambahan_urut();
                system("cls");
                tampil();
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
    if (menu1 == 4){
        exit(0);
    }
}


