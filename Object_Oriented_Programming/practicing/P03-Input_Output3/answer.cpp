#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{ 
	double X;
	int M,N;		
	char C;
	while (!cin.eof())
	{
		cin.clear(); 
		cin >> X;
		cin >> M;
		cin >> N;
		cin >> C;		
		int count = 1; //整數位數 
		double unsignX = abs(X);
		while(unsignX >= (double)pow( 10.0, count))
        	++count;
    	int count2 =  (X >= 0) ? count:(count + 1); //整數加正負號位數
    	if(N > 0){
    		int fill = M - count2 - N - 1;
    		if(fill > 0)
	    		for(int i = 0; i < fill; i++)
					cout << C;
			cout << fixed << setprecision(N) << X-0.0000000009 << endl; //-0.0000000009防止自動進位 
			cout.unsetf( ios::fixed ); //關掉fixed功能
		}else{
			//N=0，不用小數點 
			int fill = M - count2;
			if(fill > 0)
	    		for(int i = 0; i < fill; i++)
					cout << C;
			int integer = (int)(X);
			if(X >= 0)
				cout << setprecision(count2) << integer << endl;
			else
				cout << setprecision(count2 - 1) << integer << endl;
		}
	}
	return 0;
}
