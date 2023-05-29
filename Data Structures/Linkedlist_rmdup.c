#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node* crtnode(int data){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insertbegin(Node **head, int data){
    Node *newNode=crtnode(data);
    newNode->next=*head;
    *head=newNode;
}

void rmvnode(Node **head,int data){
    if (*head==NULL){
        printf("List is empty\n");
        return;
    }
    if ((*head)->data==data){
        Node *temp=*head;
        *head=(*head)->next;
        free(temp);
        return;
    }
    Node *temp=*head;
    while (temp->next!=NULL && temp->next->data!=data) {
        temp=temp->next;
    }
    if (temp->next==NULL){
        printf("node not found\n");
        return;
    }
    Node *nextNode=temp->next->next;
    free(temp->next);
    temp->next=nextNode;
}

void display(Node *head){
    if (head==NULL){
        printf("list is empty\n");
        return;
    }
    Node *temp=head;
    while (temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    Node *head=NULL;
    int n,data;
    printf("enter no. of elements in list: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        printf("enter element %d: ",i+1);
        scanf("%d",&data);
        insertbegin(&head,data);
    }
    printf("original list: ");
    display(head);
    printf("list after removing duplicates: ");
    Node *temp=head;
    while (temp!=NULL) {
        rmvnode(&head,temp->data);
        temp=temp->next;
    }
    display(head);
    return 0;
}