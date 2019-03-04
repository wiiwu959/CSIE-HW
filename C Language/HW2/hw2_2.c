#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int i,j,a[5];
	printf("Please enter five numbers between 1 and 30:\n");
	
	for(i=1;i<=5;i++)//把五個數字存到array a裡 
	    scanf("%d",&a[i]);
	
	for(i=1;i<=5;i++){//print * according to the number in the array
		for(j=0;j<a[i];j++){
		printf("*");
	    }
	printf("\n");//new line after every line of *
	}
	system("pause");
}
