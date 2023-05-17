#include <stdio.h>
#include <stdlib.h>

typedef char itemType;

typedef struct node {
    itemType data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int count;
} Queue;

int kosong(Queue* q);
void inisialisasi(Queue* q);
void Enqueue(Queue* q, itemType x);
itemType Dequeue(Queue* q);
void allmenu(Queue* q);
void menu_enqueue(Queue* q, int menu1);
void menu_dequeue(Queue* q, int menu1);
void menu_tampil(Queue* q, int menu1);
void menu_exit(int menu1);

int main() {
    Queue antrian;
    inisialisasi(&antrian);
    allmenu(&antrian);
    return 0;
}

void inisialisasi(Queue* q) {
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

int kosong(Queue* q) {
    return (q->count == 0 ? 1 : 0);
}

void Enqueue(Queue* q, itemType x) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    if (q->rear == NULL) {
        q->front = p;
        q->rear = p;
    }
    else {
        q->rear->next = p;
        q->rear = p;
    }
    q->count++;
}

itemType Dequeue(Queue* q) {
    itemType p;
    if (kosong(q)) {
        printf("Queue Kosong, tidak dapat mengambil data\n");
        return ' ';
    }
    else {
        Node* temp = q->front;
        p = temp->data;
        q->front = temp->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
        q->count--;
        return(p);
    }
}

void tampil(Queue* q) {
    printf("Data :");
    Node* baca = q->front;
    while(baca != NULL) {
        printf("\n%c ", baca->data);
        baca = baca->next;
    }
    printf("\n");
}

void allmenu(Queue *q){
    Queue antrian;
    int menu1;
    while (menu1 != 4){
        puts("\nMenu Priority Queue - SINGLE LINKED LIST");
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
        fflush(stdin);
        system("cls");
        Enqueue(q, x);
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
            tampil(q);
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
