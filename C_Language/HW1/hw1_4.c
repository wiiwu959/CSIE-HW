#include<stdio.h>

int main (void){
	
	int fdi,a,b,c,d,e,pld; 
	
	printf("Please enter a five-digit integer :");
	scanf("%d",&fdi);  //read the five-digits integer
	
	a=fdi/10000;  
	b=(fdi%10000)/1000;
	c=(fdi%1000)/100;
	d=(fdi%100)/10;
	e=fdi%10;  //seperate each numbers
	
	pld=e*10000+d*1000+c*100+b*10+a;  //rearrange the number entered
	
	if(fdi==pld){
		printf("This is a palindrome.");  //find out if the number user entered is palindrome
	}
	else{
		printf("This is not a palindrome.");
	}
	
	system("pause");
	
}
