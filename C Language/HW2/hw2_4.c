#include<stdio.h>
#include<stdlib.h>

int isEven(int num);//prototype

int main(){
	
	int num;
	printf("Please enter a positive number:(enter -1 to end)");
	scanf("%d",&num);//read a number
	
	while(num!=-1){
		if(isEven(num)==1){//use the function to judge if the number is even or not
			printf("The number is even.\n");
		}
		else{
			printf("The number is not even.\n");
		}
		printf("Please enter a positive number:(enter -1 to end)");
	    scanf("%d",&num);
	}
}

int isEven(int num){//the function which return integer 1 if the number is even
	if (num%2==0){
	    return 1;
	}
	else{
		return 0;
	}
}
