#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{//�ŧi�@�Ӧ��@��char�M�@��pointer��structure 
	char data;
	struct node *nextPtr;
};

typedef struct node Node;//�w�q�L�� 
typedef Node *nodeptr;

void insert(nodeptr *sptr,char b){
	nodeptr newptr=malloc(sizeof(Node));//���ŧi�@�ӷs��pointer�M���쪺structure 
	if(newptr!=NULL){//�u�n�o�ӷs��pointer�����\�ŧi�N�|���汵�U�Ӫ��{�� 
		newptr->data=b;//����n���J��character���w��o�ӷs�ŧi���ܼƤ� 
		newptr->nextPtr=NULL;
		
		nodeptr previousptr=NULL;//�ŧi��ӧP�w��m�Ϊ�structure pointer 
		nodeptr currentptr=*sptr;//currentptr�N�O�즳structure���}�Y��m 
		
		while(currentptr!=NULL&&b>currentptr->data){// �u�ncurrentptr���O�Ū��ӥB�o�ӭn���J���r���ƧǤ�currentptr���쪺�r���ƧǤj�Apreviousptr�Mcurrentptr�N�@�_����@��structure 
			previousptr=currentptr;
			currentptr=currentptr->nextPtr;
		}
		
		if(previousptr==NULL){//�Y�O����̫�F�N��n���J���o��newptr��쪺�sstructure���b�̧��� 
			newptr->nextPtr=*sptr;
			*sptr=newptr;
		}
		else{//���M�N�b���U����m���J�s��structure 
			previousptr->nextPtr=newptr;
			newptr->nextPtr=currentptr;
		}
	}
	else{ 
		printf("%c not inserted. No memory available.",b);
	}
}


int main(){
	srand(time(NULL));//�ŧi�Ӻؤl 
	nodeptr start=NULL;
	int i=0;
	for(i=0;i<10;i++){//�ݭn�Q���H���r�� 
		int a=(rand()%26)+65;//�H���ͦ�65��90�������Ʀr (�ഫ�᪺�j�gA��Z�d��) 
		char b=a;//��o�ӼƦr�j���૬���r�A�N�|�ӵ�ASCII code�ন�۹������r 
		insert(&start,b);
	}
	
	while(start!=NULL){
		printf("%c-->",start->data);
		start=start->nextPtr;
	}
	
	printf("NULL\n");
}
