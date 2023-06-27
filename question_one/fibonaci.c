#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV,
} TypeTag;

typedef struct Node {
    TypeTag type;
    int value;
} Node;

Node* makeFunc(TypeTag tag) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = tag;
    return node;
}

Node* fibonacci(int n) {
    Node* fib = makeFunc(ADD);

    if (n == 0) {
        fib->value = 0;
    } else if (n == 1 || n == 2) {
        fib->value = 1;
    } else {
        Node* fib1 = fibonacci(n - 3);
        Node* fib2 = fibonacci(n - 2);

        Node* add = makeFunc(ADD);
        add->value = fib1->value + fib2->value;

        Node* sub = makeFunc(SUB);
        sub->value = fib1->value - fib2->value;

        Node* mul = makeFunc(MUL);
        mul->value = fib1->value * fib2->value;

        Node* div = makeFunc(DIV);
        if (fib2->value != 0) {
            div->value = fib1->value / fib2->value;
        } else {
            div->value = 0; // Handle division by zero
        }

        fib->value = add->value + sub->value - mul->value + div->value;

        free(fib1);
        free(fib2);
        free(add);
        free(sub);
        free(mul);
        free(div);
    }

    return fib;
}

void calc(Node* node) {
    switch (node->type) {
        case ADD:
            printf("add : %d\n", node->value);
            break;
        case SUB:
            printf("sub : %d\n", node->value);
            break;
        case MUL:
            printf("mul : %d\n", node->value);
            break;
        case DIV:
            printf("div : %d\n", node->value);
            break;
        default:
            break;
    }
}

int main() {
    Node* add = makeFunc(ADD);
    add->value = 10 + 6;
    Node* mul = makeFunc(MUL);
    mul->value = 5 * 4;
    Node* sub = makeFunc(SUB);
    sub->value = mul->value - add->value;
    Node* fibo = fibonacci(sub->value);

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}
