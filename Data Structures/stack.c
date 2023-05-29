#include <stdio.h>
#include <stdlib.h>
#define max 100

int top=-1;
int stack[max];

void push(int x){
    if(top==max-1) {
        printf("stack overflow\n");
        return;
    }
    top++;
    stack[top]=x;
}
int pop(){
    if(top==-1){
        printf("stack underflow\n");
        return -1;
    }
    int x=stack[top];
    top--;
    return x;
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    return 0;
}