//
// Created by Raghul A on 25/04/23.
//
#include "stdio.h"
#include "string.h"
#define MAX 20
int Stack[MAX], top = -1;
char exp1[MAX], post[MAX];
void Push(char sym);
char pop();
char topA();
int priority(char sym);
int main() {
    int i;
    printf("Enter the expression: ");
    scanf("%s",exp1);
    for (i = 0; i< strlen(exp1 ); i++) {
        if (exp1[i]>='a' && exp1[i]<='z')
            printf("%c",exp1[i]);
        else if (exp1[i] == ')')
        {
            while (topA() != '(')
                printf("%c",pop());
            pop();
        }
        else {
            while (priority(exp1[i])<= priority(topA()) && top!=-1)
                printf("%c",pop());
            Push(exp1[i]);
        }
        for (i = top; i>=0 ;i++) {
            printf("%c",pop());
            return 0;
        }
    }
}
void Push(char sym) {
    top = top +1;
    Stack[top] = sym;
}
char pop() {
    char e;
    e = Stack[top];
    top = top-1;
    return e;
}
char topA() {
    return Stack[top];
}
int priority(char sym) {
    int p=0;
    switch (sym) {
        case '(':
            p = 0;
            break;
        case '+':
        case '-':
            p = 1;
            break;
        case '*':
        case '/':
        case '%':
            p = 2;
            break;
        case '^':
            p = 3;
            break;
    }
    return p;
}
