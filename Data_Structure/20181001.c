#include <stdio.h>
#include <stdlib.h>
#define MAX 100

char st[MAX]={'\0'},temp1[MAX]={'\0'},temp2[MAX]={'\0'},temp3[MAX]={'\0'};
int top=-1;
void push(char st[],char val);
int pop(char st[]);
int peek(char st[]);
void display(char st[],int n);
void topostfix(char infix[],char postfix[]);
void toprefix(char infix[],char prefix[]);

int main(){
	char infix[MAX]={'\0'},postfix[MAX]={'\0'},prefix[MAX]={'\0'};
	printf("Infix:");
	scanf("%s",infix);
	puts("");
	topostfix(infix,postfix);
	puts("");
	toprefix(infix,prefix);
}

void push(char st[],char val){
	if(top==MAX-1){
		printf("\n STACK OVERFLOW");
	}
	else{
		top++;
		st[top]=val;
	}
}

int pop(char st[]){
	char val;
	if(top==-1){
		printf("\n STACK UNDERFLOW");
		return -1;
	}
	else{
		val=st[top];
		top--;
		return val;
	}
}

void display(char st[],int n){         //display the whole stack
	int i;
	if(n==-1){
		printf("\n STACK IS EMPTY");
	}
	else{
		for(i=0;i<n;i++){
			printf("%c",st[i]);
		}
	}
	if(n<25){
		int k=25-n,o;
		for(o=0;o<=k;o++){
			printf(" ");
		}
	}
}


void topostfix(char infix[],char postfix[]){
	push(st,'(');
	printf("From Infix to Postfix:\n");
	printf("%15s%10s%35s\n","Infix Scanned","Stack","Postfix Expression");
	int i=0,j=0;
	while(1){
		if (infix[i+1]=='\0'){
			infix[i+1]=')';
			break;
		}
		i++;	
	}
	
	for(i=0;infix[i]!='\0';i++){
		printf("%7c",infix[i]);
		switch(infix[i]){
			case '+':
			case '-':
				while(st[top]=='*'||st[top]=='/'||st[top]=='%'||st[top]=='+'||st[top]=='-'){
					postfix[j]=pop(st);
					j++;
				}
				push(st,infix[i]);
				break;
			case '*':
			case '%':
			case '/':
				while(st[top]=='*'||st[top]=='/'||st[top]=='%'){
				postfix[j]=pop(st);
				j++;	
				}
				push(st,infix[i]);
				break;
			case '(':
				push(st,infix[i]);
				break;
			case ')':
				while(st[top]!='('){
					postfix[j]=pop(st);
					j++;
				}
				pop(st);
				break;
			default:
				postfix[j]=infix[i];
				j++;
				break;
		}	
		printf("               ");
		display(st,top+1);
		display(postfix,j);
		puts("");
	}
	printf("Postfix:");
	display(postfix,j);
	puts("");
}


void toprefix(char infix[],char prefix[]){
	int i=0,t,j=0;
	printf("From Infix to Prefix:\n");
	for(i=0;infix[i]!='\0';i++){
		if(infix[i]=='('){
			infix[i]=')';
			push(temp1,infix[i]);
			continue;
		}
		else if(infix[i]==')'){
			infix[i]='(';
			push(temp1,infix[i]);
			continue;
		}
		push(temp1,infix[i]);
	}
	pop(temp1);
	t=i;
	for(i=0;i<t-1;i++){
		temp2[i]=pop(temp1);
	}
	printf("Step 1:");
	display(temp2,t);
	puts("");
	
	printf("Step 2:");
	puts("");
	topostfix(temp2,temp3);
	puts("");
	

	for(i=0,j=0;temp3[i]!='\0';i++){
		push(st,temp3[i]);
		j++;
	}
	for(i=0;i<j;i++){
		prefix[i]=pop(st);
	}
	
	printf("Prefix:");
	display(prefix,j);
}

