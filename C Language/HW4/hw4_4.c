#include<stdio.h>
#include<string.h>
int word(char A[]);
int main(){
	int a=0;//Ū��|��y�l 
	char first[100],second[100],third[100],forth[100];
	gets(first);
	gets(second);
	gets(third);
	gets(forth);
	
	a=a+word(first);//��C�ӥy�l���r�ƥ[�b�@�_ 
	a=a+word(second);
	a=a+word(third);
	a=a+word(forth);
	
	printf("%d",a);
}
int word(char A[]){//�J��ťմN��@�Ӧr�A��X�@�ӥy�l���X�Ӧr 
	char *tok=strtok(A," ");
	int count=0;
	while(tok!=NULL){
		count++;
		tok=strtok(NULL," ");
	}
	return count;
}

