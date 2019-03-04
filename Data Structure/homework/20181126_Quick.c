#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y){
	int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int arr[],int beg,int end) {
    int left=beg;
	int right=end;
	int loc=beg;
	int flag=0;
	while(flag==0){
		while(arr[loc]<=arr[right]&&loc!=right){
			right--;
		}
		if(loc==right){
			flag=1;
		}
		else if(arr[loc]>arr[right]){
			swap(&arr[loc],&arr[right]);
			loc=right;
		}
		if(flag==0){
			while(arr[loc]>=arr[left]&&loc!=left){
				left++;
			}
			if(loc==left){
			flag=1;
			}
			else if(arr[loc]<arr[left]){
				swap(&arr[loc],&arr[left]);
				loc=left;
			}
		}
	}
	return loc;
}

void printarray(int arr[], int size){
    for (int i = 0; i < size-1; i++) {
        printf("%d ",arr[i]);
    }
    printf("%d",arr[size-1]);
}

void quicksort(int arr[],int beg,int end,int size){
	if(beg<end){
		int loc=partition(arr,beg,end);
		printarray(arr, size);
		printf("\n");
		quicksort(arr,beg,loc-1,size);
		quicksort(arr,loc+1,end,size);
	}
}

int main() {
	int size;
    scanf("%d",&size);
    int arr[1000];
    for(int i=0;i<size;i++){
    	scanf("%d",&arr[i]);
	}
    quicksort(arr, 0, size-1,size);
}
