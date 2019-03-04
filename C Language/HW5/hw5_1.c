#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int reverseBits(unsigned int a){//硂functionいр–bit筁ㄓ 
	int i=0;
	while((a/(unsigned int)pow(10,i))!=0){//眖程计秨﹍Ч碞┕玡玡⊿Τ计ゎ 
		int b=((a%(int)pow(10,i+1))/(int)pow(10,i));
		printf("%d",b);
		i++;
	}
}

int main(){
	unsigned int a;
	printf("Please enter the value:");
	scanf("%u",&a);//弄秈璶reverse计 
	
	printf("The value before reverse is: %u",a);//рreverse玡㎝reverseㄢ常ㄓ獽ゑ癸 
	printf("\nThe value after reverse is: ");
	reverseBits(a);
} 
