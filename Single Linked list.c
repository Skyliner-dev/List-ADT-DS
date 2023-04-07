//
// Created by Raghul A on 06/04/23.
//
//
// Created by Raghul A on 06/04/23.
//
#include "stdio.h"
#include "stdlib.h"
struct Node {
    int data;
    struct Node *next;
};
typedef struct Node node;
int isEmpty(node *list) {
    if (list->next==NULL) return 1;
    else return 0;
}
int isLast(node *pos) {
    if (pos->next == NULL) return 1;
    else return 0;
}
node *find(node *list,int x) {
    node *pos;
    pos = list->next;
    while (pos->next!=NULL && pos->data!=x) {
        pos = pos->next;
    }
    return pos;
}
node *findPrev(node *list,int x) {
    node *pos;
    pos = list;
    while (pos!=NULL && pos->next->data!=x) {
        pos = pos->next;
    }
    return pos;
}
node *findNext(node *list,int x) {
    node *pos;
    pos = find(list,x);
    return pos->next;
}
void insertBeg(node *list,int e) {
    node *newNode = malloc(sizeof(node));
    newNode->data = e;
    if (isEmpty(list)) {
        newNode->next = NULL;
    }
    else {
        newNode->next = list->next;
        list->next = newNode;
    }
    free(newNode);
}
void insertLast(node *list,int e) {
    node *newNode = malloc(sizeof(node));
    newNode->data = e;
    node *pos;
    pos = list->next;
    while (pos->next!=NULL) {
        pos = pos->next;
    }
    pos->next = newNode;
    newNode->next = NULL;
    free(newNode);
}
void insertMid(node *list,int e,int p) {
    node *newNode = malloc(sizeof(node));
    newNode->data = e;
    node *pos;
    pos = find(list,p);
    newNode->next = pos->next;
    pos->next = newNode;
}
void *deleteBeg(node *list) {
    if (!isEmpty(list)) {
        node *tempNode;
        tempNode = list->next;
        list->next = tempNode->next;
        free(tempNode);
    }
    else {
        printf("the list is empty");
    }
}
void *deleteMid(node *list,int p) {
    node *pos;
    pos = find(list,p);
    if (!isEmpty(list) ) {
        node *tempNode;
        tempNode = pos->next;
        pos->next = tempNode->next;
        printf("the deleted element is %d",tempNode->data);
        free(tempNode);
    }
    else {
        printf("cant delete lmao");
    }
}
void *traverse(node *list) {
    if (isEmpty(list)) {
        node *pos;
        pos = list;
        while(pos->next!=NULL) {
            pos = pos->next;
            printf("%d\t",pos->data);
        }
    }
    else {
        printf("empty");
    }
}
int main() {
    node *list = malloc(sizeof(node));
    list->next = NULL;
    node *pos;
    int n,p,e;
    printf("1.Insert Beg \n 2.Insert Middle \n3.Insert End");
    printf("\n4.Delete Beg \n5.Delete Middle \n6.Delete End");
    printf("\n7.Find \nTraverse \n9.Exit\n");
    printf("What u wan do my g? ");
    scanf("%d",&n);
    switch (n) {
        case 1:
            printf("Enter the element: ");
            scanf("%d",&e);
            insertBeg(list,e);
            break;
        case 2:
            printf("Enter the position ");
            scanf("%d",&p);
            printf("enter the element");
            scanf("%d",&e);
            insertMid(list,e,p);
            break;
        case 3:
            printf("Enter the element ");
            scanf("%d",&e);
            insertLast(list,e);
            break;
        case 4:
            deleteBeg(list);
            break;
        case 5:
            printf("Enter the position ");
            scanf("%d",&p);
            deleteMid(list,p);
            break;
        case 6:
            traverse(list);
            break;
    }


}

