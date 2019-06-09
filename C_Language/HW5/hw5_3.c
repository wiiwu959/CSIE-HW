#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{//宣告一個有一個char和一個pointer的structure 
	char data;
	struct node *nextPtr;
};

typedef struct node Node;//定義他們 
typedef Node *nodeptr;

void insert(nodeptr *sptr,char b){
	nodeptr newptr=malloc(sizeof(Node));//先宣告一個新的pointer和指到的structure 
	if(newptr!=NULL){//只要這個新的pointer有成功宣告就會執行接下來的程式 
		newptr->data=b;//先把要插入的character指定到這個新宣告的變數中 
		newptr->nextPtr=NULL;
		
		nodeptr previousptr=NULL;//宣告兩個判定位置用的structure pointer 
		nodeptr currentptr=*sptr;//currentptr就是原有structure的開頭位置 
		
		while(currentptr!=NULL&&b>currentptr->data){// 只要currentptr不是空的而且這個要插入的字母排序比currentptr指到的字母排序大，previousptr和currentptr就一起往後一個structure 
			previousptr=currentptr;
			currentptr=currentptr->nextPtr;
		}
		
		if(previousptr==NULL){//若是移到最後了就把要插入的這個newptr找到的新structure插在最尾端 
			newptr->nextPtr=*sptr;
			*sptr=newptr;
		}
		else{//不然就在停下的位置插入新的structure 
			previousptr->nextPtr=newptr;
			newptr->nextPtr=currentptr;
		}
	}
	else{ 
		printf("%c not inserted. No memory available.",b);
	}
}


int main(){
	srand(time(NULL));//宣告個種子 
	nodeptr start=NULL;
	int i=0;
	for(i=0;i<10;i++){//需要十個隨機字母 
		int a=(rand()%26)+65;//隨機生成65到90之間的數字 (轉換後的大寫A到Z範圍) 
		char b=a;//把這個數字強制轉型成字，就會照著ASCII code轉成相對應的字 
		insert(&start,b);
	}
	
	while(start!=NULL){
		printf("%c-->",start->data);
		start=start->nextPtr;
	}
	
	printf("NULL\n");
}
