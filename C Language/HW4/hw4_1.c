#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	double a[20]={0},b[20]={0};//����]�t�Ů檺�r��L�X�� 
	char c[100]={0},d[100]={0};
	printf("First array:");
	gets(c);
	printf("Second array:");
	gets(d);
	
	int i=0;//��Ĥ@�Ӧr����Φn�B�নdouble�ä@�Ӥ@�ө�iarray�� 
	char *atok=strtok(c," ");
	char *aend;
	double atd;
	while(atok!=NULL){
		atd=strtod(atok,&aend);
		a[i]=atd;
		atok=strtok(NULL," ");
		i++;
	}
	
	int j=0;//�B�z�ĤG�Ӧr�� 
	char *btok=strtok(d," ");
	char *bend;
	double btd;
	while(btok!=NULL){
		btd=strtod(btok,&bend);
		b[j]=btd;
		btok=strtok(NULL," ");
		j++;
	}
	
	int m=0,k=0,n=0;//�ŧi�@�ǥΨӭp�⪺�ܼ� 
	double ans[40]={0};//�ŧi�̫�ƦC����H���i��array 
	
	while(m<i&&n<j){//�b���䤤�@�Ӱ}�C�񧹫e��Ө�Ӥ�� 
		if(a[m]<b[n]){//����p���N��ians�̡A�M�Ჾ��U�@�� 
			ans[k]=a[m];
			m++;
			k++;
		}
		else if(a[m]>b[n]){
			ans[k]=b[n];
			n++;
			k++;
		}
		else{
			ans[k]=a[m];//��Ӭ۵����ɭԡA����N�@�ө�ians���A�M���Ӥ@�_�e�i��U�@�� 
			m++;
			n++;
			k++;
		}
    }
	
	if(m>=i){//��䤤�@�Ӥ񧹫��t�@�C�ѤU���Ӽ˷h�ians�� 
		while(n<j){
			ans[k]=b[n];
			n++;
			k++;
		}
    }
    
    if(n>=j){
    	while(m<i){
    		ans[k]=a[m];
    		m++;
    		k++;
		}
    }
    
    int count;//�̫�L�Xans���ȡA�C���Ӵ��@��A�V�k��� 
    for(count=0;count<k;count++){
    	printf("%12lf ",ans[count]);
    	if((count+1)%5==0){
    		printf("\n");
		}
	}
    
}

