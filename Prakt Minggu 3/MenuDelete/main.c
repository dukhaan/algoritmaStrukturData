#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul{
    int data;
    Node *next;
};
Node *head = NULL,*p,*tail,*phapus,*hapus;

void allmenu();
void menu_insert();
void menu_delete();
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

char jwb;
int menu1,menu2,menu3;

int main()
{
    allmenu();
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
    if(bef->data == x){
        awal();
    } else {
        while(bef->data != x) {
        if(bef->next == NULL) {
            puts("gagal!");
        }
        else {
            pbef = bef;
            bef = bef->next;
        }
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
    while(after->data == x) {
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

void hapus_akhir(){
    hapus = head;
    if(hapus == NULL)
        head = NULL;
    else if(hapus->next == NULL){
        hapus_awal();
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
        printf("%d\n",baca->data);
        (baca=baca->next);
    }
}

void allmenu(){

    while (menu1 != 3){
        puts("Menu SLL");
        printf("1. Insert\n2. Delete\n3. Exit \n");
        printf("Masukkan pilihan anda : ");
        scanf("%d",&menu1);
        fflush(stdin);
        menu_insert();
        menu_delete();
        if(menu1 == 3){
            exit(0);
        }
    }
}
void menu_insert(){
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
                if(head == NULL){
                    puts("Masukkan data dahulu");
                } else{
                     after();
                     system("cls");
                     tampil();
                }

                break;
            case 4:
                if(head == NULL){
                    puts("Masukkan data dahulu");
                } else{
                    before();
                    system("cls");
                    tampil();
                }

                break;
            default:
                system("cls");
                puts("Input salah");
                break;
                }
            }
        }
}
void menu_delete(){
    if(menu1 == 2){
            if(head == NULL){
                puts("Insert Terlebih Dahulu");

            } else {
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

        }
}
