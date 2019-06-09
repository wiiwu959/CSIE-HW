#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

typedef struct Node{
		struct Node *left;
  		int data;
		struct Node *right;
	}node;
typedef node *nodeptr;
int ok,oko,j=0;
int array[MAX]={NULL};

void insert(nodeptr (*tree) , int val){
	if((*tree)== NULL){
		(*tree)=malloc(sizeof(node));
		(*tree)->data=val;
		(*tree)->left=NULL;
		(*tree)->right=NULL;
	}
	else{
		if(val<(*tree)->data){
			insert(&((*tree)->left),val);
		}
		else if(val>(*tree)->data){
			insert(&((*tree)->right),val);
		}
	}
}

void postorder(nodeptr tree){
	if(tree!=NULL){
		postorder(tree->left);
		postorder(tree->right);
		array[j]=tree->data;
		j++ ;
	}
	return;
}



void printarray(int array[]){
	int i=0;
	while(array[i+1]!=NULL){
		printf("%d ",array[i]);
		array[i]=NULL;
		i++;
	}
	printf("%d",array[i]);
	array[i]=NULL;
}

void mirror(nodeptr tree){
	if(tree!=NULL){
		mirror(tree->left);
		mirror(tree->right);
		nodeptr temp=tree->left;
		tree->left=tree->right;
		tree->right=temp;
	}
}

void preorder(nodeptr tree){
	if(tree!=NULL){
		array[j]=tree->data;
		j++;
		preorder(tree->left);
		preorder(tree->right);
	}
}

int height(nodeptr tree){
	if(tree==NULL){
		return 0;
	}
	else{
		int leftheight=height(tree->left);
		int rightheight=height(tree->right);
		if (leftheight>rightheight){
			return leftheight+1;
		}
		else{
			return rightheight+1;
		}
	}
}

int total(nodeptr tree){
	if(tree==NULL){
		return 0;
	}
	else{
		return total(tree->left)+total(tree->right)+1;
	}
}

int external(nodeptr tree){
	if(tree==NULL){
		return 0;
	}
	else if(tree->left==NULL&&tree->right==NULL){
		return 1;
	}
	else{
		return external(tree->left)+external(tree->right);
	}
}

nodeptr max(nodeptr tree){
	if(tree==NULL){
		return 0;
	}
	else if(tree->right!=NULL){
		return max(tree->right);
	}
	else{
		return tree;
	}
}

nodeptr min(nodeptr tree){
	if(tree==NULL){
		return 0;
	}
	else if(tree->left!=NULL){
		return min(tree->left);
	}
	else{
		return tree;
	}
}

nodeptr deletelarge(nodeptr tree,int val){
	if(tree==NULL){
		printf("VAL not found in the tree");
		ok=1;
		return 0;
	}
	else if(val<tree->data){
		tree->left=deletelarge(tree->left,val);
		return tree;
	}
	else if(val>tree->data){
		tree->right=deletelarge(tree->right,val);
		return tree;
	}
	else{
		nodeptr temp=tree;
		if(tree->left!=NULL&&tree->right!=NULL){
			temp=max(tree->left);
			tree->data=temp->data;
			tree->left=deletelarge(tree->left,temp->data);
			return tree;
		}
		else if(tree->left==NULL&&tree->right==NULL){
			tree=NULL;
			return tree;
		}
		else if(tree->left!=NULL){
			tree=tree->left;
			return tree;
		}
		else{
			tree=tree->right;
			return tree;
		}
		free(temp);
	}
}


nodeptr get(int val){
  nodeptr newptr = (nodeptr)malloc(sizeof(node));
  newptr->data = val;
  newptr->left = NULL;
  newptr->right = NULL;
  return newptr;
}

nodeptr copy(nodeptr tree){
    if(tree==NULL){
    	return NULL;
	}
	else{
		nodeptr newptr = get(tree->data);
    	newptr->left=copy(tree->left);
   		newptr->right=copy(tree->right);
    	return newptr;
	} 
}

nodeptr deletesmall(nodeptr tree,int val){
	if(tree==NULL){
		printf("VAL not found in the tree");
		oko=1;
		return 0;
	}
	else if(val<tree->data){
		tree->left=deletesmall(tree->left,val);
		return tree;
	}
	else if(val>tree->data){
		tree->right=deletesmall(tree->right,val);
		return tree;
	}
	else{
		nodeptr temp=tree;
		if(tree->left!=NULL&&tree->right!=NULL){
			temp=min(tree->right);
			tree->data=temp->data;
			tree->right=deletesmall(tree->right,temp->data);
			return tree;
		}
		else if(tree->left==NULL&&tree->right==NULL){
			tree=NULL;
			return tree;
		}
		else if(tree->left!=NULL){
			tree=tree->left;
			return tree;
		}
		else{
			tree=tree->right;
			return tree;
		}
		free(temp);
	}
}


int main(void) {
	nodeptr rootptr=NULL;
	nodeptr newptr=NULL;
	 
	int num,i,x,y,tem;
    scanf("%d",&num);
    
    for(i=0;i<num;i++){
    	scanf("%d",&tem);
    	insert(&rootptr,tem);
	}
	
	scanf("%d",&x);
	scanf("%d",&y);

	postorder(rootptr);
	printarray(array);
	printf("\n");
	j=0;
	mirror(rootptr);
	postorder(rootptr);
	printarray(array);
	printf("\n");
	j=0;
	mirror(rootptr);
	insert(&rootptr,x);
	preorder(rootptr);
	printarray(array);
	printf("\n");
	j=0;
	printf("%d\n",height(rootptr));
	printf("%d\n",total(rootptr));
	printf("%d\n",total(rootptr)-external(rootptr));
	printf("%d\n",max(rootptr)->data);
	printf("%d\n",min(rootptr)->data);
	newptr=copy(rootptr);
	deletelarge(rootptr,y);
	if (ok!=1){
		preorder(rootptr);
		printarray(array);
	}
	printf("\n");
	j=0;
	deletesmall(newptr,y);
	if (oko!=1){
		preorder(newptr);
		printarray(array);
	}
}

