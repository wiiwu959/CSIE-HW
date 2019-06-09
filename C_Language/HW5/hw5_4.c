#include<stdio.h>

struct battery{//�ŧi����q�M��S���q�����c 
	int energy;
	int voltage;
};
typedef struct battery battery_t;

int power_device(int amps,int sec,battery_t *x){//�]���ݭn���ܳo�ӹq�����ȡA�ҥHcall by reference 
	if((x->energy/(x->voltage))>=(amps*sec)){//�p�G�q�q���������o��device�n�D���R�q����N�~�򩹤U���� 
		x->energy=x->energy-((x->voltage)*amps*sec);//�M���q��������q���令���ӫ᪺���A 
		return 1;
	}
	else{
		return 0;
	}
}

int max_time(battery_t x,int amps){//��X�o�ӹq���b��e���A���i�H�R�@�ӫ��w�w����device�h�[ 
	int t=x.energy/(amps*x.voltage);
	return t;
}

void recharge(int a,int b,battery_t* x){//��q������q�M��S����_�쥼���Ӫ����A 
	x->energy=a;
	x->voltage=b;
}

int main(){
	
	battery_t bat={(5*1000000),12};//�ŧi�o�ӹq�������A 
	power_device(4,15*60,&bat);//��X�b4A��device�U�R15�����᪺���A 
	int howlong=max_time(bat,8);//��X�R��4Adevice�᪺���A�U��R�@��8A��device�h�[ 
	printf("The battery's remaining energy could power an 8A device for %d minutes %d seconds\n",howlong/60,howlong%60);
	recharge(5*1000000,12,&bat);//�⪬�A��_��S���Ӫ��ˤl 
	howlong=max_time(bat,8);//�p��b�S�����ӤU�o�ӹq���i�H�R8A��device�h�[ 
	printf("After charged, it could power an 8A device for %d minutes %d seconds",howlong/60,howlong%60);

}
