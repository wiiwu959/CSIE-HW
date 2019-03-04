#include<stdio.h>

int lcm(int a,int b);//宣告function 

int main(){
	int a,b;
	printf("Please enter two number:\n");//讀取使用者給的兩個數字 
	scanf("%d%d",&a,&b);
	printf("%d",lcm(a,b));
}

int lcm(int a,int b){//找出最小公倍數 
	int i;
	if(b>a)
	    i=b;
	else if(a>b)
		i=a;
	while(i%a!=0||i%b!=0){
		i++;
	}
	return i;
}
