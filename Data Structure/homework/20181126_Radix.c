#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printarray(int arr[], int size){
    for (int i = 0; i < size-1; i++) {
        printf("%d ",arr[i]);
    }
    printf("%d\n",arr[size-1]);
}

int finddigit(int arr[],int size){
    int max=arr[0],digit=0;
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    while(max/10!=0||max%10!=0){
        max=max/10;
        digit++;
    }
    return digit;
}

void radixsort(int arr[],int size) {
    int nop=finddigit(arr,size),pass=0,tem;
    while(pass<nop){
        int A[100][10]={0};
        for(int i=0;i<size;i++){
            tem=(arr[i]%(int)pow(10,pass+1))/(int)pow(10,pass);
            A[i][tem]=arr[i];
        }
        int i=0;
        while(i<size){
            for(int j=0;j<10;j++){
                for(int k=0;k<size;k++){
                    if(A[k][j]!=0){
                        arr[i]=A[k][j];
                        i++;
                    }
                }
            }
        }
        printarray(arr,size);
        pass++;
    }
}

int main(void) {
    int arr[100],size;
    scanf("%d",&size);
    for(int i=0;i<size;i++){
    	scanf("%d",&arr[i]);
	}
	radixsort(arr,size);
}
