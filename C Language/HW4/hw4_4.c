#include<stdio.h>
#include<string.h>
int word(char A[]);
int main(){
	int a=0;//讀近四行句子 
	char first[100],second[100],third[100],forth[100];
	gets(first);
	gets(second);
	gets(third);
	gets(forth);
	
	a=a+word(first);//把每個句子的字數加在一起 
	a=a+word(second);
	a=a+word(third);
	a=a+word(forth);
	
	printf("%d",a);
}
int word(char A[]){//遇到空白就算一個字，算出一個句子有幾個字 
	char *tok=strtok(A," ");
	int count=0;
	while(tok!=NULL){
		count++;
		tok=strtok(NULL," ");
	}
	return count;
}

