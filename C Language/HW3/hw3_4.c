#include<stdio.h>

int main(){
	int A[1000],i,j,k,m;
	for(i=0;i<1000;i++){//initialize
		A[i]=1;
	}
	
	for(j=2;j<1000;j++){//�⤣�O��ƪ����ܦ�0 
		if(A[j]==1){
			for(k=j+1;k<1000;k++){
				if(k%j==0){
			       A[k]=0;
			    }
		    }
		}
	}
	
	for(m=2;m<1000;m++){//�L�X��1(�O��ƪ���) 
		if(A[m]==1){
			printf("%d\n",m);
		}
	}
}
