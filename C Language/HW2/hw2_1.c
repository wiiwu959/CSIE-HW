#include<stdio.h>
#include<stdlib.h> 

int main(){
	
	int num,lar,tem,i;
	
	printf("How many number are you going to type?\n");
	scanf("%d",&num);//to know now many numbers are going to be read
	
	if(num>0){//make sure there is number to be read
		printf("Please enter the number:\n"); 
	    scanf("%d",&tem);
	    lar=tem;//initiallize the varieble tem
	
	    for(i=1;i<num;i++){//read the numbers and compare them
		    printf("Please enter the number:\n");
		    scanf("%d",&tem);
		
		    if(tem>lar)
		    lar=tem;
	    }
    }
	else{//make sure there is number to be read
		printf("You need to enter a number larger than 0.");
		system("pause");
		return 0;
	}
	
	printf("The largest number is %d.",lar);//print the result
	system("pause");
}
	
