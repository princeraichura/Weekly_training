#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* creat_node(int data){
	struct node *new=malloc(sizeof(struct node));
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	
	return new;
}

struct node* tree(struct node* root){
	int data;
	printf("enter data for node : \n");
	scanf("%d",&data);

	if(data==-1){
		return NULL;
	}
	root = creat_node(data);

	root->left = tree(root->left);
	root->right = tree(root->right);	
	return root;
}


void inorder(struct node *root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	printf("%d",root->data);
	inorder(root->right);
	
}

void preorder(struct node* root){
	if(root==NULL){
		return;
	}
	printf("%d",root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct node* root){
	if(root==NULL){
		return;
	}

	postorder(root->left);
	postorder(root->right);
	printf("%d",root->data);
}

int height(struct node* root){
	if(root==NULL){
		return 0;
	}

	int left = height(root->left);
	int right = height(root->right);

	if(left>right){
		return left = left+1;
	}
	else{
		return right = right+1;
	}
}


void height_tree(struct node* root){
	int left=height(root->left);
	int right=height(root->right);

	if(left-right>1 || left-right<-1){
		printf("\nnot Balanced.\n");
	}
	else{	
		printf("balanced.\n");
	}
}

int main(){
	struct node *root = NULL;
	
	root = tree(root);
	printf("\nInorder : ");
	inorder(root);
	printf("\npreorder : ");
	preorder(root);
	printf("\npostorder : ");
	postorder(root);
	
	height_tree(root);

	return 0;
}
