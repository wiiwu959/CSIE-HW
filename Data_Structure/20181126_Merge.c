#include <stdio.h>
#include <stdlib.h>

void printarray(int arr[], int size){
    for (int i = 0; i < size-1; i++) {
        printf("%d ",arr[i]);
    }
    printf("%d\n",arr[size-1]);
}

void merge(int arr[],int beg,int mid,int end){
    int i =beg,j=mid+1,index=0;
    int temp[1000]={0};
    while(i<=mid&&j<=end){
        if(arr[i]<arr[j]){
            temp[index]=arr[i];
            i++;
        }

        else{
            temp[index]=arr[j];
            j++;
        }
        index++;
    }
    while(i<=mid){
        temp[index]=arr[i];
        i++;
        index++;
    }
    while(j<=end){
        temp[index]=arr[j];
        j++;
        index++;
    }
    printarray(temp,index);
    for(i=0;i<index;i++){
        arr[beg+i]=temp[i];
    }
}

void mergesort(int arr[],int beg, int end){
    if(beg<end){
        int mid=(beg+end-1)/2;
        mergesort(arr,beg,mid);
        mergesort(arr,mid+1,end);
        if(beg==mid){
            printf("%d\n%d\n",arr[beg],arr[beg+1]);
        }
        merge(arr,beg,mid,end);
    }
}

int main(){
    int arr[1000],size;
    scanf("%d",&size);
    for(int i=0;i<size;i++){
    	scanf("%d",&arr[i]);
	}
	mergesort(arr,0,size-1);
}

