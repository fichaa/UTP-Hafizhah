#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char data[MAX_SIZE][50];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, char item[]) {
    if (isFull(stack)) {
        printf("Stack penuh, tidak bisa menambahkan data.\n");
        return;
    }
    stack->top++;
    strcpy(stack->data[stack->top], item);
}

char* pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong, tidak bisa menghapus data.\n");
        return NULL;
    }
    char *item = stack->data[stack->top];
    stack->top--;
    return item;
}

void isiStack(struct Stack *stack, struct Stack *stack1, struct Stack *stack2, struct Stack *stack3) {
    int count = 0;
    while (!isEmpty(stack)) {
        char *item = pop(stack);
        if (count % 3 == 0) {
            push(stack1, item);
        } else if (count % 3 == 1) {
            push(stack2, item);
        } else {
            push(stack3, item);
        }
        count++;
    }
}

void tampilkanStack(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack kosong.\n");
        return;
    }
    printf("Isi stack dari top ke bottom:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%s\n", stack->data[i]);
    }
}

int main(){
    struct Stack stack, stack1, stack2, stack3;
    initStack(&stack);
    initStack(&stack1);
    initStack(&stack2);
    initStack(&stack3);   

    push(&stack, "String 1");
    push(&stack, "String 2");
    push(&stack, "String 3");
    push(&stack, "String 4");
    push(&stack, "String 5");
    push(&stack, "String 6");
    push(&stack, "String 7");
    push(&stack, "String 8");
    push(&stack, "String 9");
    push(&stack, "String 10");

    isiStack(&stack, &stack1, &stack2, &stack3);

    printf("Isi stack 1 : \n");
    tampilkanStack(&stack1);
    printf("Isi stack 2 : \n");
    tampilkanStack(&stack2);
    printf("Isi stack 3 : \n");
    tampilkanStack(&stack3);
    
    return 0;
}