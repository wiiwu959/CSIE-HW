#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shuffle(int deck[][13]);
void swap(int *a,int *b);
void deal(int deck[][13],char *face[],char *suit[]);

int main(){
	int deck[4][13];
	
	int i,j,k=1;//��l�� 
	for(i=0;i<4;i++){
		for(j=0;j<13;j++){
			deck[i][j]=k;
			k++;
		}
	}
	
	srand(time(NULL));//�غؤl 
	shuffle(deck);
	
	//�ŧi�P���W�� 
	char*suit[4]={"Hearts","Diamonds","Clubs","Spades"};
	char*face[13]={"Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
	
	deal(deck,face,suit);
}

void shuffle(int deck[][13]){//�~�P 
    int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<13;j++){
		int row=rand()%4;//���N��@�Ӧ�m 
		int column=rand()%13;
		swap(&deck[i][j],&deck[row][column]);//��o��Ӧ�m���P���� 
		}
    }
}

void swap(int*a,int*b){//�����P 
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void deal(int deck[][13],char *face[],char *suit[]){//�L�X�~���P�����G 
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
	
