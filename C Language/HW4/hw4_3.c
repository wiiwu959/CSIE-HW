#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	char tele[13];//Ū�J�q�ܸ��X 
	scanf("%13s",tele);
	
	printf("The area number is:");
	char*pockey=strtok(&tele[1],")");//�q�Ĥ@�ӬA�������ĤG�ӬA������O�ϰ차 
	char *popo;
	int d=strtod(pockey,&popo); 
	printf("%02d\n",d);
	
	printf("The phone number is:");//�ѤU�����O�q�ܸ��X�A��-�h����L�X�� 
	char*tok=strtok(&tele[4],"-");
	char*toto;
	while(tok!=NULL){
		long s=strtol(tok,&toto,10);
		printf("%ld",s);
		tok=strtok(NULL,"-");
	}
}
