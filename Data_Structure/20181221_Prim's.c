#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char node1;
	char node2;
	int weight;
    struct Node *next;
}node;

node* minnode(node* fringe){
    int min=fringe->weight;
    node* minpo=fringe;
    node* now=fringe;
    while(now!=NULL){
        if(now->weight<min){
            min=now->weight;
            minpo=now;
        }
        now=now->next;
    }
    return minpo;
}

int lookfor(char arr[],char a,int num){
    for(int i=0;i<=num;i++){
        if(arr[i]==a){
            return 1;
        }
    }
    return 0;
}

int numofnode(node* firstptr,int edgenum){
    node* now=firstptr;
    char check;
    char arr[10000]={'/0'};
    int pos=-1;
    for(int i=0;i<edgenum;i++){
        check=now->node1;
        if(lookfor(arr,check,pos)==0){
            pos++;
            arr[pos]=check;
        }
        check=now->node2;
        if(lookfor(arr,check,pos)==0){
            pos++;
            arr[pos]=check;
        }
        now=now->next;
    }
    return (pos+1);
}





int main(){
    int edgenum;
    char connect;
    node* nowptr;                               //nowptr指向現在所在位置
    node* newptr;
    scanf("%d",&edgenum);                      //edgenum是edge的數量

    node *firstptr=malloc(sizeof(node));       //先讀進第一個node(因為第一個是存firstnode)
    scanf("%c",&(firstptr->node1));
    scanf("%c",&(firstptr->node2));
    scanf("%d",&(firstptr->weight));
    firstptr->next=NULL;
    nowptr=firstptr;

    for(int i=0;i<edgenum-1;i++){             //讀進其他的node
        newptr=malloc(sizeof(node));
        nowptr->next=newptr;
        nowptr=newptr;
        scanf("%c",&(nowptr->node1));
        scanf("%c",&(nowptr->node2));
        scanf("%d",&(nowptr->weight));
        nowptr->next=NULL;
    }
    scanf("%c",&connect);
    printf("%d",numofnode(firstptr,edgenum));






/*
    node* fringe;
    node* nowfringe;
    nowptr=firstptr;            //從第一個node開始掃描
    node* tree;
    node* treehead;
    int haha=0;

    while(nowptr!=NULL){        //找到第一個fringe
        if(nowptr->node1==connect||nowptr->node2==connect){
            newptr=malloc(sizeof(node));
            newptr->node1=nowptr->node1;
            newptr->node2=nowptr->node2;
            newptr->weight=nowptr->weight;
            newptr->next=NULL;
            fringe=newptr;
            nowfringe=newptr;
            nowptr=nowptr->next;
            break;
        }
        nowptr=nowptr->next;
    }

    while(nowptr!=NULL){        //找到其他fringe,加到陣列裡
        if(nowptr->node1==connect||nowptr->node2==connect){
            newptr=malloc(sizeof(node));
            newptr->node1=nowptr->node1;
            newptr->node2=nowptr->node2;
            newptr->weight=nowptr->weight;
            newptr->next=NULL;
            nowfringe->next=newptr;
            nowfringe=newptr;
        }
        nowptr=nowptr->next;
    }

    if(haha=0){
        treehead=minnode(fringe);
        tree=minnode(fringe);
        haha=1;
    }

    */



    system("pause");
    return 0;

}
