#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

void pop() {
    top--;
}

int main() {
    char exp[100];
    printf("Enter expression: ");
    scanf("%s", exp);

    for(int i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')') {
            if(top == -1) {
                printf("Not Balanced");
                return 0;
            }
            pop();
        }
    }

    if(top == -1)
        printf("Balanced Expression");
    else
        printf("Not Balanced");

    return 0;
}