#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *file; 
	if((file=fopen("values.dat","w"))==NULL){//���}�ɮסA�p�G�����\�N�L�X�o�@�C 
		printf("File could not be opened.");
	}
	else{//�p�G�ɮצ��\���}�N���汵�U�Ӫ��ʧ@ 
		printf("If you want to print ASCII code in uppercase please enter 1\n");
		printf("If you want to print ASCII code in lowercase please enter 2\n");
   		char a;
		int i;
   		printf("Please enter your option:");
		a=getchar();
		getchar();
		if(a=='1'){
			fprintf(file,"%-9s%21s\n","Character","ASCII value");//���L�X��檺���D 
			for(i=65;i<=90;i++){
				fprintf(file,"%-1c",i); 
				fprintf(file,"%25d\n",i);//��char�j���૬��int�N�|�L�Xcharacter��ASCII code
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
	fclose(file);//�n�O�o���ɮ� 
}

