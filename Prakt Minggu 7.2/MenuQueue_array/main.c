#include <stdio.h>
#include <stdlib.h>
#define MAKS 7

typedef char itemType;
typedef struct{
    itemType item[MAKS];
    int count;
    int front;
    int rear;
} Queue;

int x;

int kosong (Queue *q);
int penuh (Queue *q);
void inisialisasi(Queue *q);
void Enqueue(Queue *q, itemType x);
itemType Dequeue(Queue *q);
void minmax(Queue *q, itemType x);
void caridata(Queue *q, itemType x);
void allmenu(Queue *q);
void menu_enqueue(Queue *q, int menu1);
void menu_dequeue(Queue *q, int menu1);
void menu_minmax(Queue *q,int menu1);
void menu_caridata(Queue *q,int menu1);
void menu_tampil(Queue *q, int menu1);
void menu_exit(int menu1);


int main()
{
    Queue antrian;
    inisialisasi(&antrian);
    allmenu(&antrian);
    return 0;
}

void inisialisasi(Queue *q){
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

int kosong(Queue *q){
    return (q->count == 0 ? 1:0);
}

int penuh(Queue *q){
    return (q->count == MAKS ? 1 : 0);
}

void Enqueue(Queue *q, itemType x){
    if(penuh(q))
        printf("Queue penuh, data tidak dapat disimpan");
    else {
        q->item[q->rear] = x;
        q->rear = (q->rear + 1) % MAKS;
        q->count++;
    }
}

itemType Dequeue (Queue *q){
    itemType temp;
    if(kosong(q)){
        printf("Queue Kosong, tidak dapat mengambil data\n");
        return ' ';
    } else {
        temp = q->item[q->front];
        q->front = (q->front+1) % MAKS;
        q->count--;
        return(temp);
    }
}

void minmax(Queue *q, itemType x){
    itemType min = q->item[q->front];
    itemType max = q->item[q->front];

    for(int i=0; i<q->count; i++){
        if(q->item[(q->front+i)%MAKS] < min){
            min = q->item[(q->front+i)%MAKS];
        }
        if(q->item[(q->front+i)%MAKS] > max){
            max = q->item[(q->front+i)%MAKS];
        }
    }
    printf("Nilai minimum dalam Queue adalah : %c\n", min);
    printf("Nilai maksimum dalam Queue adalah : %c\n", max);
}

void caridata(Queue *q, itemType x){
    itemType key;
    int count = 0;
    printf("Masukkan data yang ingin dicari : ");
    key = getchar();

    for(int i=0; i<q->count; i++){
        if(q->item[(q->front+i)%MAKS] == key){
            count++;
        }
    }

    if(count == 0){
        printf("Data %c tidak ditemukan dalam Queue\n", key);
    } else {
        printf("Data %c ditemukan %d kali dalam Queue\n", key, count);
    }
}

void allmenu(Queue *q){
    Queue antrian;
    int menu1;
    while (menu1 != 6){
        puts("\nMenu Queue - ARRAY");
        printf("1. Tambah data\n2. Hapus data\n3. Tampilkan data min & max\n4. Cari data \n5. Cetak isi Queue\n6. Keluar\n");
        printf("Masukkan pilihan anda : ");
        scanf("%d",&menu1);
        fflush(stdin);
        menu_enqueue(q,menu1);
        menu_dequeue(q,menu1);
        menu_minmax(q,menu1);
        menu_caridata(q,menu1);
        menu_tampil(q,menu1);
        menu_exit(&menu1);
    }
}
void menu_enqueue(Queue *q, int menu1){
    if(menu1 == 1){
        itemType x;
        printf("Masukkan data : ");
        x = getchar();
        Enqueue(q, x);
        system("cls");
    }
}
void menu_dequeue(Queue *q, int menu1){
    if(menu1 == 2){
        system("cls");
        if(!kosong(q)){
            printf("Item yang diambil adalah : %c\n",Dequeue(q));
        } else{
            printf("Queue Kosong, Masukkan data terlebih dahulu\n");
        }
    }
}

void menu_minmax(Queue *q, int menu1){
    if(menu1 == 3){
        system("cls");
        if(!kosong(q)){
            minmax(q,x);
        } else{
            printf("Queue Kosong, Masukkan data terlebih dahulu\n");
        }
    }
}

void menu_caridata(Queue *q, int menu1){
    if(menu1 == 4){
        system("cls");
        if(!kosong(q)){
            caridata(q,x);
        } else{
            printf("Queue Kosong, Masukkan data terlebih dahulu\n");
        }
    }
}

void menu_tampil(Queue *q, int menu1){
    if(menu1 == 5){
        system("cls");
        if(!kosong(q)){
            printf("Isi Queue saat ini adalah : ");
            for(int i=0; i<q->count; i++){
                printf("\n%c", q->item[(q->front+i)%MAKS]);
            }
            printf("\n");
        }
        else{
            printf("Queue kosong, Masukkan data terlebih dahulu\n");
        }
    }
}

void menu_exit(int menu1){
    if (menu1 == 6){
        exit(0);
    }
}

