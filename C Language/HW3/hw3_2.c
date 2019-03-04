#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int number,guess;
    char play='y';
	while(play=='y'){//如果使用者想繼續玩就會繼續執行 
        srand(time(NULL));
	    number=(rand()%1000)+1;
	  
	    printf("I have a number between 1 and 1000\n");//印出問題 
	    printf("Can you guess my number?\n");
  	    printf("Please type your first guess.\n");
	    scanf("%d",&guess);//讀取使用者的第一個猜測 
	
	    while(number!=guess){//只要猜錯就給出提示並繼續下一次猜測 
	  	    if(number>guess){
		      printf("Too low! Try again.\n");
		      scanf("%d",&guess);
			}
		    else if(number<guess){
			  printf("Too high! Try again.\n");
		      scanf("%d",&guess);
		    }	
	    }
		    printf("Excellent! You guessed the number.\n");
		    printf("Would you like to play again (y or n)?\n");
		    scanf(" %c",&play);//猜對時詢問使用者要不要繼續玩 
    }
}
