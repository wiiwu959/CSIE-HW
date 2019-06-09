#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	while (!cin.eof()) 
	{
		int Y, N = 0;
		cin >> Y;

		if (Y > 2200 || Y < 1900)
		{
			cout << "Not in the range" << endl;
		}
		
		//��X��1900�t�X�ӤQ�~�٦��X����
		double tem = (Y - 1900) / 10.0;
		double bits = 4 * pow(2, tem);
		double total = 0;

		//�Q�Ϋ�����קK�����p��|�z��
		while (total < bits)
		{
			N++;
			total += log(N) / log(2);
		}
		cout << N - 1 << endl;
	}
	
}