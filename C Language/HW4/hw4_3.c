#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	char tele[13];//讀入電話號碼 
	scanf("%13s",tele);
	
	printf("The area number is:");
	char*pockey=strtok(&tele[1],")");//從第一個括弧之後到第二個括弧為止是區域馬 
	char *popo;
	int d=strtod(pockey,&popo); 
	printf("%02d\n",d);
	
	printf("The phone number is:");//剩下的都是電話號碼，把-去掉後印出來 
	char*tok=strtok(&tele[4],"-");
	char*toto;
	while(tok!=NULL){
		long s=strtol(tok,&toto,10);
		printf("%ld",s);
		tok=strtok(NULL,"-");
	}
}
