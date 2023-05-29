#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *start;
void display(){
	struct node *p;
	int i=0;
	p=start;
	if(start==NULL)
	{
		printf("Empty\n");
	}
	
	while(p!=NULL)
	{
		printf("Node = %d, Data = %d \n",i+1,p->data);
		i++;
		p=p->link;
	}	
}

int main(){
	struct node *p;
	struct node *n1=(struct node*)malloc(sizeof(struct node));
	struct node *n2=(struct node*)malloc(sizeof(struct node));	
	struct node *n3=(struct node*)malloc(sizeof(struct node));
	
	n1->data=10;
	n1->link=n2;

	n2->data=20;
	n2->link=n3;

	n3->data=30;
	n3->link=NULL;
	
	start=n1;
	p=start;
	display();
	return 0;
}
