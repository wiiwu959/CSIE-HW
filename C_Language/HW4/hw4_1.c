#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	double a[20]={0},b[20]={0};//把兩串包含空格的字串印出來 
	char c[100]={0},d[100]={0};
	printf("First array:");
	gets(c);
	printf("Second array:");
	gets(d);
	
	int i=0;//把第一個字串切割好、轉成double並一個一個放進array中 
	char *atok=strtok(c," ");
	char *aend;
	double atd;
	while(atok!=NULL){
		atd=strtod(atok,&aend);
		a[i]=atd;
		atok=strtok(NULL," ");
		i++;
	}
	
	int j=0;//處理第二個字串 
	char *btok=strtok(d," ");
	char *bend;
	double btd;
	while(btok!=NULL){
		btd=strtod(btok,&bend);
		b[j]=btd;
		btok=strtok(NULL," ");
		j++;
	}
	
	int m=0,k=0,n=0;//宣告一些用來計算的變數 
	double ans[40]={0};//宣告最後排列整齊以後放進的array 
	
	while(m<i&&n<j){//在比到其中一個陣列比完前兩個兩個比較 
		if(a[m]<b[n]){//比較小的就放進ans裡，然後移到下一格 
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
			ans[k]=a[m];//兩個相等的時候，把任意一個放進ans哩，然後兩個一起前進到下一格 
			m++;
			n++;
			k++;
		}
    }
	
	if(m>=i){//當其中一個比完後把另一列剩下的照樣搬進ans裡 
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
    
    int count;//最後印出ans的值，每五個換一行，向右對齊 
    for(count=0;count<k;count++){
    	printf("%12lf ",ans[count]);
    	if((count+1)%5==0){
    		printf("\n");
		}
	}
    
}

