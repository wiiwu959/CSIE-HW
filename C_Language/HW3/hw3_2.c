#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int number,guess;
    char play='y';
	while(play=='y'){//�p�G�ϥΪ̷Q�~�򪱴N�|�~����� 
        srand(time(NULL));
	    number=(rand()%1000)+1;
	  
	    printf("I have a number between 1 and 1000\n");//�L�X���D 
	    printf("Can you guess my number?\n");
  	    printf("Please type your first guess.\n");
	    scanf("%d",&guess);//Ū���ϥΪ̪��Ĥ@�Ӳq�� 
	
	    while(number!=guess){//�u�n�q���N���X���ܨ��~��U�@���q�� 
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
		    scanf(" %c",&play);//�q��ɸ߰ݨϥΪ̭n���n�~�� 
    }
}
