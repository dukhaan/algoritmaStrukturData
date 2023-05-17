#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAKS 100

typedef char itemType;
typedef struct {
    itemType data[MAKS];
    int count;
} stack;

void inisialisasi(stack *s);
int empty(stack *s);
int full(stack *s);
void push(itemType x, stack *s);
itemType pop(stack *s);
itemType top(stack *s);
int cekpalindrome(char *kata, stack *s);

int main() {
    puts("MENGECEK PALINDROME");
    char jwb;
    stack tumpukan;
    char kata[MAKS];

    do{
        fflush(stdin);
        printf("Masukkan kata yang di cek : ");
        fgets(kata, MAKS, stdin);


        if (cekpalindrome(kata, &tumpukan)) {
            kata[strcspn(kata, "\n")] = '\0';
            printf("%s adalah PALINDROME.\n\n", kata);
        } else {
            kata[strcspn(kata, "\n")] = '\0';
            printf("%s adalah BUKAN PALINDROME.\n\n", kata);
        }

        fflush(stdin);
        printf("Mau coba lagi (y/t) : ");
        jwb = getchar();
    } while (jwb == 'y' || jwb == 'Y');



    return 0;
}

void inisialisasi(stack *s) {
    s->count = 0;
}

int empty(stack *s) {
    return s->count == 0 ? 1 : 0;
}

int full(stack *s) {
    return s->count == MAKS ? 1 : 0;
}

void push(itemType x, stack *s) {
    if (full(s)) {
        printf("Stack penuh, data tidak dapat disimpan.\n");
    } else {
        s->data[s->count] = x;
        s->count++;
    }
}

itemType pop(stack *s) {
    itemType temp;

    if (empty(s)) {
        printf("Stack kosong, push data terlebih dahulu\n");
    } else {
        --(s->count);
        temp = s->data[s->count];
        return temp;
    }
}

itemType top(stack *s) {
    return s->data[s->count - 1];
}

int cekpalindrome(char *kata, stack *s) {
    int i, len;
    len = strlen(kata) - 1; // Mengecualikan enter
    inisialisasi(s);

    // Push tiap karakter di kata ke dalam stack
    for (i = 0; i < len; i++) {
        push(kata[i], s);
    }

    // pop setiap karakter dari stack dan bandingkan dengan yang sesusai character di dalam kata
    for (i = 0; i < len; i++) {
        if (pop(s) != kata[i]) {
            return 0; // bukan palindrome
        }
    }

    return 1; // palindrome
}
