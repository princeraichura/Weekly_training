#include<stdio.h>
#include<stdlib.h>

int n;
struct node
{
	int data;
	struct node *link;
};

struct node *start;
struct node *lastnode;

void creat_list(){
	printf("enter Number of Nodes: \n");
	scanf("%d",&n);
	struct node *p;
	printf("enter data for node 1 : \n");
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&newnode->data);
	
	newnode->link=NULL;
	start=newnode;
	lastnode=newnode;

	//rest nodes
	int i;
	for(i=2;i<=n;i++)
	{
		printf("Enter data for node %d : \n",i);
		newnode=(struct node*)malloc(sizeof(struct node));			
		scanf("%d",&newnode->data);
	
		newnode->link=NULL;
		lastnode->link=newnode;
		lastnode=newnode;
	}
}
	
//display function
void display(){
	struct node *p;
	int i=0;
	p=start;
	if(start==NULL){
		printf("Empty\n");
	}
	
	while(p!=NULL){
		printf("node = %d, data = %d \n",i+1,p->data);
		i++;
		p=p->link;
	}	

}

void insert_front(){
	struct node *new=(struct node*)malloc(sizeof(struct node));
	printf("enter data for node at front : \n");
	scanf("%d",&new->data);
	if(start == NULL){
		start=new;//if list is empty
		lastnode = new;
	}
	new->link=start;
	start=new;
}

void insert_end(){
	struct node *new=(struct node*)malloc(sizeof(struct node));
	printf("enter data for node at end: \n");
	scanf("%d",&new->data);
	new->link=NULL;

	if(start==NULL){
		start=new;
		lastnode=new;
	}
	lastnode->link=new;
	lastnode=new;
}

//insert at perticular position
void after_node()
{
	int x,i=0;
	printf("enter the value of data = \n");
	scanf("%d",&x);
	
	struct node *new=(struct node*)malloc(sizeof(struct node));
	printf("Enter data for new Node : \n");
	scanf("%d",&new->data);
	new->link=NULL;

	struct node *p;
	p=start;
	
	while(p->data!=x){
		p = p->link;
		i++;
		if(i>n){
			printf("data Not Found \n");
			printf("new data is inserted at the End\n");
			break;
		}
	}
	new->link=p->link;
	p->link=new;
}

int main(){
	struct node *p;
	p=start;

	creat_list();
	display();
	insert_front();
	display();
	insert_end();
	display();
	after_node();
	display();
	return 0;
}