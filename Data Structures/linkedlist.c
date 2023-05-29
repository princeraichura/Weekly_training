#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node* createNode(int data){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertbegin(Node **head,int data){
    Node *newNode=createNode(data);
    newNode->next=*head;
    *head=newNode;
}

void insertend(Node **head,int data){
    Node *newNode=createNode(data);
    if (*head==NULL) {
        *head=newNode;
        return;
    }
    Node *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
}

void deletebegin(Node **head){
    if(*head==NULL){
        printf("list is empty\n");
        return;
    }
    Node *temp=*head;
    *head=(*head)->next;
    free(temp);
}

void deleteend(Node **head){
    if(*head==NULL){
        printf("list is empty\n");
        return;
    }
    if ((*head)->next==NULL) {
        free(*head);
        *head=NULL;
        return;
    }
    Node *temp=*head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void display(Node *head){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    Node *head=NULL;
    insertbegin(&head,1);
    insertbegin(&head,2);
    insertend(&head,3);
    insertend(&head,4);
    display(head);
    deletebegin(&head);
    deleteend(&head);
    display(head);
    return 0;
}