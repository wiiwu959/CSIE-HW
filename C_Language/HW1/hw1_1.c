#include<stdio.h>

int main (void)
{ int integer1,integer2,integer3; //number to be entered
  int sum,average,product;
  int largest,smallest;

  printf("Enter three different integers:");
  scanf("%d %d %d",&integer1,&integer2,&integer3);  //read three integers
  
  if(integer1==integer2||integer2==integer3||integer1==integer3){ //make sure that user entered three different numbers
  	printf("Three integers must be different");
  	return(0);
  }
  
  
  sum=integer1+integer2+integer3; //assigned total to sum
  printf("Sum is %d\n",sum);
  
  average=sum/3;  //assigned average to sum
  printf("Average is %d\n",average);
  
  product=integer1*integer2*integer3;  //assigned product to sum
  printf("Product is %d\n",product);
  

  largest=integer1;  //find out the largest number
  if(integer2>largest){
  	largest=integer2;
  }
  if(integer3>largest){
  	largest=integer3;
  }
  
  smallest=integer1;  //find out the smallest number
  if(integer2<smallest){
  	largest=integer2;
  }
  if(integer3<smallest){
  	largest=integer3;
  }

  printf("Smallest is %d\n",smallest);  
  printf("Largest is %d\n",largest);
  
  system("pause");
}

