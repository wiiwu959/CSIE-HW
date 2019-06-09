#include<stdio.h>

struct battery{//宣告有能量和伏特的電池結構 
	int energy;
	int voltage;
};
typedef struct battery battery_t;

int power_device(int amps,int sec,battery_t *x){//因為需要改變這個電池的值，所以call by reference 
	if((x->energy/(x->voltage))>=(amps*sec)){//如果電量足夠滿足這個device要求的充電條件就繼續往下執行 
		x->energy=x->energy-((x->voltage)*amps*sec);//然後把電池中的能量欄位改成消耗後的狀態 
		return 1;
	}
	else{
		return 0;
	}
}

int max_time(battery_t x,int amps){//算出這個電池在當前狀態中可以充一個指定安培的device多久 
	int t=x.energy/(amps*x.voltage);
	return t;
}

void recharge(int a,int b,battery_t* x){//把電池的能量和伏特都恢復到未消耗的狀態 
	x->energy=a;
	x->voltage=b;
}

int main(){
	
	battery_t bat={(5*1000000),12};//宣告這個電池的狀態 
	power_device(4,15*60,&bat);//算出在4A的device下充15分鐘後的狀態 
	int howlong=max_time(bat,8);//算出充完4Adevice後的狀態下能充一個8A的device多久 
	printf("The battery's remaining energy could power an 8A device for %d minutes %d seconds\n",howlong/60,howlong%60);
	recharge(5*1000000,12,&bat);//把狀態恢復到沒消耗的樣子 
	howlong=max_time(bat,8);//計算在沒有消耗下這個電池可以充8A的device多久 
	printf("After charged, it could power an 8A device for %d minutes %d seconds",howlong/60,howlong%60);

}
