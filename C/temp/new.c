#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 20
char stck[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

char peek() {
    return stck[top];
}

void push(char val) {
    if (isFull()) {
        printf("Stack overflow\n");
    } else {
        ++top;
        stck[top] = val;
    }
}

char pop() {
    int temp;
    if (isEmpty()) {
        printf("Stack is empty\n");
        temp = -1;
    } else {
        temp = stck[top];
        top--;
    }
    return temp;
}

int operandCheck(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char c) {
    if (c == '-' || c == '+') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    } else {
        return -1;
    }
}

int highprecedence(char a, char b) {
    return precedence(a) > precedence(b);
}

void convrtinf(char ex[]) {
    char res[MAX];
    int j = 0;
    int i = 0;
    while (strcmp(ex + i, "NULL") != 0) {
        if (operandCheck(ex[i])) {
            res[j] = ex[i];
            j++;
            i++;
        } else if (!operandCheck(ex[i])) {
            while (!isEmpty() && highprecedence(peek(), ex[i])) {
                res[j] = pop();
                j++;
            }
            push(ex[i]);
            i++;
        }
    }
    while (!isEmpty()) {
        res[j] = pop();
        j++;
    }
    res[j] = '\0';
    printf("%s\n", res);
}

int main() {
    char d[MAX];
    printf("Enter the expression: ");
    scanf("%19s", d);
    convrtinf(d);
    return 0;
}
