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
	printf("Enter Number of Nodes: \n");
	scanf("%d",&n);

	struct node *p;
	printf("Enter data for node 1 : \n");
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	scanf("%d",&newnode->data);
	
	newnode->link=NULL;
	start=newnode;
	lastnode=newnode;

	int i;
	for(i=2;i<=n;i++)
	{
		printf("Enter data for node %d : \n",i);
		newnode = (struct node *)malloc(sizeof(struct node));			
		scanf("%d",&newnode->data);
	
		newnode->link = NULL;
		lastnode->link = newnode;
		lastnode = newnode;
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
		printf("Node = %d, Data = %d \n",i+1,p->data);
		i++;
		p=p->link;
	}	
}

void delete_front(){
	struct node* temp;
	
	//if link list is empty
	if(start==NULL){
		printf("Link List is Empty\n");
	}
	//if single node is present in link list 
	else if(start->link==NULL){
		temp=start;
		start=NULL;
		free(temp);
	}
	//if more than 1 nodes in link list
	else{
		temp=start;
		start=start->link;
		free(temp);
	}

}

void delete_end()
{
	struct node* temp;	
	struct node* prev;
	if(start==NULL){
		printf("linked List is Empty\n");
	}
	else if(start->link == NULL)
	{
		temp = start;
		start = NULL;
		free(temp);
	}
	else{
		temp = start;
		while(temp->link!=NULL){
			prev = temp;
			temp = temp->link;
		}
			prev->link = NULL;
			free(temp);
	}
}
int main(){
	struct node *p;
	p=start;

	creat_list();
	display();
	delete_front();
	printf("\nafter deleting first node :\n");
	display();
	delete_end();
	printf("\nafter deleting last Node :\n");
	display();
	return 0;
}
