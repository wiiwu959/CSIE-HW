#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shuffle(int deck[][13]);
void swap(int *a,int *b);
void deal(int deck[][13],char *face[],char *suit[]);

int main(){
	int deck[4][13];
	
	int i,j,k=1;//初始化 
	for(i=0;i<4;i++){
		for(j=0;j<13;j++){
			deck[i][j]=k;
			k++;
		}
	}
	
	srand(time(NULL));//種種子 
	shuffle(deck);
	
	//宣告牌的名稱 
	char*suit[4]={"Hearts","Diamonds","Clubs","Spades"};
	char*face[13]={"Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
	
	deal(deck,face,suit);
}

void shuffle(int deck[][13]){//洗牌 
    int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<13;j++){
		int row=rand()%4;//任意抽一個位置 
		int column=rand()%13;
		swap(&deck[i][j],&deck[row][column]);//把這兩個位置的牌互換 
		}
    }
}

void swap(int*a,int*b){//互換牌 
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void deal(int deck[][13],char *face[],char *suit[]){//印出洗完牌的結果 
	int card,row,column;
	for(card=0;card<53;card++){
		for(row=0;row<4;row++){
			for(column=0;column<13;column++){
				if(deck[row][column]==card){
					printf("%5s of %-8s%c",face[column],suit[row],card%2==0?'\n':'\t');
					break;
				}
			} 
		}
	}
}
	
