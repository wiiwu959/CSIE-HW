#include<stdio.h>

int main (void){
	
	int h;
	float hr,s;
	
	printf("Enter # of hours worked (-1 to end) :");
	scanf("%d",&h);  //read the hours first
	
	while(h!=-1){ //judge if user entered -1
		printf("Enter hourly rate of the worker ($00.00) :");
		scanf("%f",&hr);  //read hourly rate
		
		if(h>40){  //if hours more than 40, the hours will be paid time-and-a-half
			s=(float)40*hr+(h-40)*1.5*hr;
		}
		else{
			s=(float)hr*h;
		}
		
		printf("Salary is $%.2f\n",s);
		
		printf("Enter # of hours worked (-1 to end) :");  //read the hours again
		scanf("%d",&h);
	}
	system("pause");
}
