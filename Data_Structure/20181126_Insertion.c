#include <stdio.h>
#include <stdlib.h>

void printarray(int arr[], int size){
    for (int i = 0; i < size-1; i++) {
        printf("%d ",arr[i]);
    }
    printf("%d\n",arr[size-1]);
}

void insertionsort(int arr[],int size) {
    for(int i=1;i<size;i++){
        int temp=arr[i];
        int j=i-1;
        while(temp<=arr[j]&&j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        printarray(arr,size);
    }
}

int main(void) {
    int arr[100],size;
    scanf("%d",&size);
    for(int i=0;i<size;i++){
    	scanf("%d",&arr[i]);
	}
	insertionsort(arr,size);
}
