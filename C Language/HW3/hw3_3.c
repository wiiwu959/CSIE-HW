#include<stdio.h>

int lcm(int a,int b);//�ŧifunction 

int main(){
	int a,b;
	printf("Please enter two number:\n");//Ū���ϥΪ̵�����ӼƦr 
	scanf("%d%d",&a,&b);
	printf("%d",lcm(a,b));
}

int lcm(int a,int b){//��X�̤p������ 
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
