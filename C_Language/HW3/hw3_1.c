#include <stdio.h>

void hanoi(int n, char initial, char temporary, char to);//�ŧifunction 

int main() {
    int n;
    printf("Please enter the height of Hanoi towel:");//���o��L�ƶq 
    scanf("%d", &n);
    hanoi(n, '1', '2', '3');
} 

void hanoi(int n, char innitial, char temporary, char to) {
    if(n == 1) {
        printf("From %c to %c\n",innitial,to);//�פ���󬰥u�ѤU�@����L 
    }
    else {
        hanoi(n-1,innitial,to,temporary); 
        printf("From %c to %c\n",innitial,to);
        hanoi(n-1,temporary,innitial,to);
    }
}
