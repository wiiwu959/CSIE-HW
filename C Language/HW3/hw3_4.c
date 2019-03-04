#include<stdio.h>

int main(){
	int A[1000],i,j,k,m;
	for(i=0;i<1000;i++){//initialize
		A[i]=1;
	}
	
	for(j=2;j<1000;j++){//把不是質數的項變成0 
		if(A[j]==1){
			for(k=j+1;k<1000;k++){
				if(k%j==0){
			       A[k]=0;
			    }
		    }
		}
	}
	
	for(m=2;m<1000;m++){//印出為1(是質數的項) 
		if(A[m]==1){
			printf("%d\n",m);
		}
	}
}
