#include "syscall.h"

int arr[1000];

int
main()
{
    int i, add = 0;
    arr[0] = 1;
    for(i = 0; i < 1000; i++) {
	arr[i] = arr[0];
	//PrintInt(arr[0]);
	add += arr[i];
	//PrintInt(add);
	
    }
    //PrintInt(add);
}
