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


int kosong (Queue *q);
int penuh (Queue *q);
void inisialisasi(Queue *q);
void Enqueue(Queue *q, itemType x);
itemType Dequeue(Queue *q);
void allmenu(Queue *q);
void menu_enqueue(Queue *q, int menu1);
void menu_dequeue(Queue *q, int menu1);
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

void allmenu(Queue *q){
    Queue antrian;
    int menu1;
    while (menu1 != 4){
        puts("\nMenu Queue - ARRAY");
        printf("1. Mengisi Queue <Enqueue>\n2. Mengambil isi Queue <Dequeue>\n3. Menampilkan isi Queue -> FIFO\n4. Keluar\n");
        printf("Masukkan pilihan anda : ");
        scanf("%d",&menu1);
        fflush(stdin);
        menu_enqueue(q,menu1);
        menu_dequeue(q,menu1);
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

void menu_tampil(Queue *q, int menu1){
    if(menu1 == 3){
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
    if (menu1 == 4){
        exit(0);
    }
}

