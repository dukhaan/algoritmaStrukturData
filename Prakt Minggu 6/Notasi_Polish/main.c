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
int operator_deklarasi(char c);
int prioritas(char op1, char op2);
void infixToPostfix(char *infix, char *postfix, stack *s);


int main() {
    char jwb;
    puts("MENGUBAH NOTASI INFIX MENJADI POSTFIX\nDENGAN MEMANFAATKAN STRUKTUR STACK\n");
    stack tumpukan;
    char infix[MAKS], postfix[MAKS];

    do{
        fflush(stdin);
        printf("Masukkan eskpresi dalam notasi infix : ");
        fgets(infix, MAKS, stdin);
        infixToPostfix(infix, postfix,&tumpukan);
        printf("Ungkapan postfixnya = %s\n", postfix);
        fflush(stdin);
        printf("\nMau mencoba lagi (y/t) : ");
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

int operator_deklarasi(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int prioritas(char op1, char op2) {
    if (op1 == '+' || op1 == '-') {
        return op2 == '+' || op2 == '-' ? 1 : 0;
    } else if (op1 == '*' || op1 == '/') {
        return op2 == '+' || op2 == '-' ? 1 : (op2 == '*' || op2 == '/' ? 1 : 0);
    } else if (op1 == '^') {
        return op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/' ? 1 : 0;
    }
    return 0;
}

void infixToPostfix(char *infix, char *postfix, stack *s) {
    int i, j;
    inisialisasi(s);
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (infix[i] == ' ' || infix[i] == '\t' || infix[i] == '\n') {
            continue;
        }
        if (infix[i] >= '0' && infix[i] <= '9') {
            postfix[j++] = infix[i];
            while ((infix[i + 1] >= '0' && infix[i + 1] <= '9') || (infix[i + 1] >= 'A' && infix[i + 1] <= 'Z')) {
                i++;
                postfix[j++] = infix[i];
            }
            postfix[j++] = ' ';
        } else if (infix[i] >= 'A' && infix[i] <= 'Z'){
            postfix[j++] = infix[i];
            while (infix[i + 1] >= 'A' && infix[i + 1] <= 'Z') {
                i++;
                postfix[j++] = infix[i];
            }
            postfix[j++] = ' ';
        }else if (operator_deklarasi(infix[i])) {
            while (!empty(s) && top(s) != '(' && prioritas(top(s), infix[i])) {
                postfix[j++] = pop(s);
                postfix[j++] = ' ';
            }
            push(infix[i], s);
        } else if (infix[i] == '(') {
            push(infix[i], s);

        } else if (infix[i] == ')') {
            while (!empty(s) && top(s) != '(') {
                postfix[j++] = pop(s);
                postfix[j++] = ' ';
            }
            if (!empty(s) && top(s) == '(') {
                pop(s);
            } else {
                printf("Kurung tidak seimbang\n");
                return;
            }
        } else {
            printf("Input tidak valid\n");
            return;
        }
    }

    while (!empty(s)) {
        if (top(s) == '(') {
            printf("Kurung tidak seimbang\n");
            return;
        }
        postfix[j++] = pop(s);
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
}

