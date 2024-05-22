#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack penuh\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = item;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

int charToInt(char c) {
    return c - '0'; 
}

int stringToInt(char *str) {
    int result = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        result = result * 10 + charToInt(str[i]); // Mengonversi setiap karakter menjadi integer
    }
    return result;
}

int main() {
    Stack stack;
    initStack(&stack);

    char input[MAX_SIZE];
    printf("Masukkan string karakter angka: ");
    scanf("%s", input);

    int len = strlen(input);
    
    for (int i = 0; i < len; i++) {
        push(&stack, input[i]);
    }

    int hasil = stringToInt(stack.items);

    printf("Hasil konversi: %d\n", hasil);

    return 0;
}
