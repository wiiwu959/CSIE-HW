#include<stdio.h>
#include<stdlib.h>

void reverse(int *A,int size){
	int i=0,j=size-1,k;
	while(i<j){
		k=A[i];
		A[i]=A[j];
		A[j]=k;
		i++;
		j--;
	}
}

int decode(int*data,int size,int num){
	int i,j=0,k=0;
	if(size%6!=5||size<24){
		printf("Case %d:bad code\n",num);
		return 0;
	}
    
	int max=data[0],min=data[0];
	for(i=0;i<size;i++){
	    if(data[i]>max){
	    	max=data[i];
		}
		if(data[i]<min){
			min=data[i];
		}	
	}
	
	int t=(min+max)/2.0;
	int small[256],most[256]={0};
	j=0;k=0;
	
	for(i=0;i<size;i++){
	    if(data[i]<t){
	    	small[j]=data[i];
	    	j++;
		}
	}
	
	for(i=0;i<=j;i++){
		most[small[i]]++;
	}
	
	
	int mostnum=0;
	for(i=0;i<=200;i++){
		if(most[i]>=mostnum){
			mostnum=small[i];
		}
	}
	

	for(i=0;i<size;i++){
	    if(data[i]<t){
	    	if(data[i]>=(mostnum*0.95)&&data[i]<=(mostnum*1.05)){
	    		data[i]=0;
			}
			else{
				printf("Case %d:bad code\n",num);
				return 0;
			}
		}
		else if(data[i]>t){
			if(data[i]>=(mostnum*2*0.95)&&data[i]<=(mostnum*2*1.05)){
	    		data[i]=1;
			}
			else{
				printf("Case %d:bad code\n",num);
				return 0;
			}			
		}
		else{
			printf("Case %d:bad code\n",num);
			return 0;
		}
	}
	
	if((data[0]+data[1]+data[2]+data[3]+data[4])!=2){
		printf("Case %d:bad code\n",num);
		return 0;
	}
	else if((data[0]+data[1]+data[2]+data[3]+data[4])==2){
		if(data[2]!=1||data[3]!=1){
			if((data[size-1]+data[size-2]+data[size-3]+data[size-4]+data[size-5])!=2){
				printf("Case %d:bad code\n",num);
		        return 0;
			}
			else if((data[size-1]+data[size-2]+data[size-3]+data[size-4]+data[size-5])==2){
				if(data[size-3]!=1||data[size-4]!=1){
				    printf("Case %d:bad code\n",num);
				    return 0;
			    }
			    else if(data[size-3]==1&&data[size-4]==1){
			    	if(data[1]!=1||data[2]!=1){
			    		printf("Case %d:bad code\n",num);
				        return 0;
					}
					else if(data[1]==1&&data[2]==1){
					    reverse(data,size);
					}
			    }
			}
		}
	}
	
	int n=1,m=((size+1)/6);
	char A[200];
	i=0;
	while(n<m-1){
		if(data[n*6+5]!=0){
			printf("Case %d:bad code\n",num);
			return 0;
		}
	    if(data[6*n]==1){
			if((data[6*n]+data[6*n+1]+data[6*n+2]+data[6*n+3]+data[6*n+4])==1){
				A[i]='0';
				i++;
				n++;
				continue;
			}
			else if((data[6*n]+data[6*n+1]+data[6*n+2]+data[6*n+3]+data[6*n+4])==2){
				if(data[6*n+1]==1){
			        A[i]='5';
			        i++;
					n++;
			        continue;
		        }
			    else if(data[6*n+2]==1){
				    A[i]='3';
				    i++;
					n++;
				    continue;
			    }
			    else if(data[6*n+3]==1){
			        A[i]='1';
			        i++;
			        n++;
			        continue;
				}
				else if(data[6*n+4]==1){
			        A[i]='8';
			        i++;
			        n++;
			        continue;
				}
				else{
				    printf("Case %d:bad code\n",num);
				    return 0;
				}
			}
			else{
				printf("Case %d:bad code\n",num);
			    return 0;
			}
		}
		else if(data[6*n+1]==1){
		    if((data[6*n]+data[6*n+1]+data[6*n+2]+data[6*n+3]+data[6*n+4])==2){
				if(data[6*n+2]==1){
			        A[i]='4';
			        i++;
			        n++;
			        continue;
		        }
			    else if(data[6*n+4]==1){
			        A[i]='7';
			        i++;
					n++;
			        continue;
			    }
			    else{
				    printf("Case %d:bad code\n",num);
				    return 0;
				}
			}
			else{
				printf("Case %d:bad code\n",num);
			    return 0;
			}		
		}
		else if(data[6*n+2]==1){
		    if((data[6*n]+data[6*n+1]+data[6*n+2]+data[6*n+3]+data[6*n+4])==2){
		    	if(data[6*n+4]==1){
		    		A[i]='6';
		    		i++;
					n++;
		    		continue;
				}
				else{
					printf("Case %d:bad code\n",num);
			        return 0;
				}
			}
			else if((data[6*n]+data[6*n+1]+data[6*n+2]+data[6*n+3]+data[6*n+4])==1){
				if(data[6*n+2]==1){
					A[i]='-';
					i++;
					n++;
					continue;
				}
				else{
					printf("Case %d:bad code\n",num);
			        return 0;
				}
			}
			else{
				printf("Case %d:bad code\n",num);
			    return 0;
			}
	    }
		else if(data[6*n+3]==1){
		 	if((data[6*n]+data[6*n+1]+data[6*n+2]+data[6*n+3]+data[6*n+4])==2){
		    	if(data[6*n+4]==1){
		    		A[i]='2';
		    		i++;
					n++;
		    		continue;
				}
				else{
				    printf("Case %d:bad code\n",num);
			        return 0;
			    }
			}
			else{
				printf("Case %d:bad code\n",num);
			    return 0;
			}
		}
		else if(data[6*n+4]==1){
			if((data[6*n]+data[6*n+1]+data[6*n+2]+data[6*n+3]+data[6*n+4])==1){
		    	if(data[6*n+4]==1){
		    		A[i]='9';
		    		i++;
					n++;
		    		continue;
				}
				else{
	    		    printf("Case %d:bad code\n",num);
			        return 0;
			    }
			}
			else{
				printf("Case %d:bad code\n",num);
			    return 0;
			}
		}
		else{
			printf("Case %d:bad code\n",num);
			return 0;
		}
	}
			
	
	int B[200]={0};
    for(i=0;i<(m-2);i++){
	    switch(A[i]){
	    	case'0':
	    		B[i]=0;
	    		break;
		    case'1':
			    B[i]=1;
			    break;
			case'2':
				B[i]=2;
				break;
			case'3':
				B[i]=3;
				break;
			case'4':
				B[i]=4;
				break;
			case'5':
				B[i]=5;
				break;
			case'6':
				B[i]=6;
				break;
			case'7':
				B[i]=7;
				break;
			case'8':
				B[i]=8;
				break;
			case'9':
				B[i]=9;
				break;
			case'-':
				B[i]=10;
				break;
			default:
				printf("Case %d:bad code\n",num);
				return 0;
		}	
	}
	
    int C=0,K=0;
    for(i=1;i<m-3;i++){
        C=(C+((m-4-i)%10+1)*B[i-1]);
    }
    if(B[m-4]!=(C%11)){
     	printf("Case %d:bad C\n",num);
		return 0;
	}

	for(i=1;i<m-2;i++){
        K=(K+((m-3-i)%9+1)*B[i-1]);
    }
    if(B[m-3]!=(K%11)){
     	printf("Case %d:bad K\n",num);
		return 0;
	}
	printf("Case %d:",num);
	for(i=0;i<(m-4);i++){
		printf("%c",A[i]);
	}
	printf("\n");
	
    return 0;
}

int main(){
	FILE *cfPtr;
	int k=1,size;
	char X[256];
	printf("Please enter file name:\n");
	gets(X);
	cfPtr=fopen(X,"r");
	if(cfPtr==NULL){
		printf("File could not be opened.");
	}
	else{		
	    fscanf(cfPtr,"%d",&size);
		while(size!=0){
			int *data=malloc(size*sizeof(int));
			
			int i;
			for(i=0;i<size;i++){
	    		fscanf(cfPtr,"%d",&data[i]);
			}
			decode(data,size,k);
			free(data);
			k++;
			fscanf(cfPtr,"%d",&size);
    	}
	}
	fclose(cfPtr);
}
