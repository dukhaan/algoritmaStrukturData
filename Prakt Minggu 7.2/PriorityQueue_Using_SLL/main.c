#include <stdio.h>
#include <stdlib.h>

typedef char itemType;

typedef struct node {
    itemType data;
    int priority;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int count;
} Queue;

int kosong(Queue* q);
void inisialisasi(Queue* q);
void enqueue(Queue* q, itemType x,int priority);
itemType dequeue(Queue* q);
void tampil(Queue* q);
void allmenu(Queue *q);
void menu_enqueue(Queue *q, int menu1);
void menu_dequeue(Queue *q, int menu1);
void menu_tampil(Queue *q, int menu1);
void menu_exit(int menu1);

int main() {
    Queue antrian;
    inisialisasi(&antrian);
    allmenu(&antrian);
    return 0;
}

void inisialisasi(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

int kosong(Queue* q) {
    return (q->count == 0 ? 1 : 0);
}

void enqueue(Queue *q, itemType x, int priority){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->priority = priority;
    p->next = NULL;

    if(q->rear == NULL){
        q->front = p;
        q->rear = p;
    }else{
        if(priority < q->front->priority){
            p->next = q->front;
            q->front = p;
        }
        else if(priority >= q->rear->priority){
            q->rear->next = p;
            q->rear = p;
        }
        else{
            Node *temp = q->front;
            while(temp->next != NULL && temp->next->priority <= priority){
                temp = temp->next;
            }
            p->next = temp->next;
            temp->next = p;
        }
        q->count++;
    }
    printf("Data '%c' dengan priority %d berhasil ditambahkan ke dalam queue.\n\n", x, priority);
}

itemType dequeue(Queue* q) {
    Node* temp = q->front;
    itemType data = temp->data;
    q->front = q->front->next;
    q->count--;
    free(temp);
    return data;
}

void tampil(Queue* q) {
    printf("Data \t: Prioritas :\n");
    Node* baca = q->front;
    while(baca != NULL) {
        printf("\n%c \t %d ", baca->data, baca->priority);
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
        int priority;
        itemType x;
        printf("Masukkan data : ");
        x = getchar();
        printf("Priority Antrian (1-10) : ");
        scanf("%d",&priority);
        fflush(stdin);
        system("cls");
        enqueue(q, x, priority);
    }
}
void menu_dequeue(Queue *q, int menu1){
    if(menu1 == 2){
        system("cls");
        if(!kosong(q)){
            printf("Item yang diambil adalah : %c\n",dequeue(q));
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
