#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *file; 
	if((file=fopen("values.dat","w"))==NULL){//打開檔案，如果不成功就印出這一列 
		printf("File could not be opened.");
	}
	else{//如果檔案成功打開就執行接下來的動作 
		printf("If you want to print ASCII code in uppercase please enter 1\n");
		printf("If you want to print ASCII code in lowercase please enter 2\n");
   		char a;
		int i;
   		printf("Please enter your option:");
		a=getchar();
		getchar();
		if(a=='1'){
			fprintf(file,"%-9s%21s\n","Character","ASCII value");//先印出表格的標題 
			for(i=65;i<=90;i++){
				fprintf(file,"%-1c",i); 
				fprintf(file,"%25d\n",i);//把char強制轉型成int就會印出character的ASCII code
			}
		}
		else if(a=='2'){
			fprintf(file,"%-9s%21s\n","Character","ASCII value");
			for(i=97;i<=122;i++){
				fprintf(file,"%-1c",i); 
				fprintf(file,"%25d\n",i);
			}
		}
		else{
			printf("The option entered wrong.");
		}
	}  
	fclose(file);//要記得關檔案 
}

