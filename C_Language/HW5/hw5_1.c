#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int reverseBits(unsigned int a){//�b�o��function����C��bit�˹L�� 
	int i=0;
	while((a/(unsigned int)pow(10,i))!=0){//�q�̤p��ƶ}�l�L�A�L���N���e�@��A����e���S���Ʀr���� 
		int b=((a%(int)pow(10,i+1))/(int)pow(10,i));
		printf("%d",b);
		i++;
	}
}

int main(){
	unsigned int a;
	printf("Please enter the value:");
	scanf("%u",&a);//Ū�i�nreverse���Ʀr 
	
	printf("The value before reverse is: %u",a);//��reverse�e�Mreverse�᪺��̳��L�X�ӥH�K��� 
	printf("\nThe value after reverse is: ");
	reverseBits(a);
} 
