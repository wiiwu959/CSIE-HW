#include<stdio.h>

int main (void){
	
	int w,h;
	float s;
	
	printf("Please enter your weight(kilogram):");
	scanf("%d",&w);  //read the weight which user entered
	
	printf("Please enter your height(centimeter):");
	scanf("%d",&h);  //read the height which user entered
	
	s=(float)w/h/h*10000;  //height in cetimeter must be transfered into meter
	printf("Your BMI(body mass index) is: %.1f\n", s);
		
	printf("BMI VALUES\n\
	Underweight: less than 18.5\n\
	Normal: between 18.5 and 24.9\n\
	Overweight: between 25 and 29.9\n\
	Obese: 30 or greater");  //print the imformation for users
	
	system("pause");
}
