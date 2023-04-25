//
// Created by Raghul A on 25/04/23.
//
#include "stdio.h"
#define MAX 10
#include "stdlib.h"
int STACK[MAX], top = -1;
int isFull() {
    if (top == MAX-1)
        return 1;
    else
        return 0;
}
int isEmpty() {
    if (top == -1) {
        return 1;
    }
    else return 0;
}
void Push(int e) {
    if (isFull()) printf("Stack overflow \n");
    else {
        top = top +1;
        STACK[top] = e;
    }
}
void pop() {
    if (isEmpty()) printf("Stack underflow \n");
    else {
        printf("%d\n",STACK[top]);
        top = top-1;
    }
}
void Top() {
    if (isEmpty()) printf("Stack underflow");
    else {
        printf("%d\n",STACK[top]);
    }
}
void display() {
    int i;
    if (isEmpty())printf("stack underflow");
    else {
        for (i=top;i>=0;i--) {
            printf("%d",STACK[i]);
        }
    }
}
//linked list implementation of stack
struct node {
    int e;
    struct node *next;
}*List = NULL;
typedef struct node stack;
int isEmptyL() {
    if (List == NULL) return 1;
    else return 0;
}
void push1(int e) {
    stack *newNode = malloc(sizeof(stack));
    newNode->e = e;
    if (isEmpty()) newNode->next = NULL;
    else newNode->next = List;
    List = newNode;
}
void pop1() {
    if (isEmpty()) printf("stack underflow");
    else {
        stack *tempNode = malloc(sizeof(stack));
        tempNode = List;
        List = List->next;
        free(tempNode);
    }
}
void top1() {
    if (isEmpty()) printf("underflow");
    else {
        printf("%d\n",List->e);
    }
}
void display1() {
    if (isEmpty()) printf("underflow");
    else {
        stack *position;
        position = List;
        while (position!=NULL) {
            printf("%d",position->e);
            position = position->next;
        }
    }

}

//ok\