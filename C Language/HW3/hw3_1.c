#include <stdio.h>

void hanoi(int n, char initial, char temporary, char to);//宣告function 

int main() {
    int n;
    printf("Please enter the height of Hanoi towel:");//取得圓盤數量 
    scanf("%d", &n);
    hanoi(n, '1', '2', '3');
} 

void hanoi(int n, char innitial, char temporary, char to) {
    if(n == 1) {
        printf("From %c to %c\n",innitial,to);//終止條件為只剩下一片圓盤 
    }
    else {
        hanoi(n-1,innitial,to,temporary); 
        printf("From %c to %c\n",innitial,to);
        hanoi(n-1,temporary,innitial,to);
    }
}
