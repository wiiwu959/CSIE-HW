#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int i,a;
	printf("%8s%11s%7s%13s\n","Decimal","Binary","Octal","Hexadecimal");//print the title and keep the space between each title
	
	for(i=1;i<=256;i++){//print the number from 1 to 256
		int s=1,bin=0;
		for(a=i;a>0;a/=2,s*=10){//convert decimal number to binary number
			bin=bin+(a%2)*s;
		}
		printf("%8d%11d%7o%13X\n",i,bin,i,i);
	}
	system("pause");
}
