#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	while(!cin.eof())
	{
		string X;
		int M, N;
		char C;
		cin >> X >> M >> N >> C;
		string integerPart, floatPart;

		//�`�������p���I�ӷ��ƩM�p�ƪ����q
		string::size_type flag = X.find(".");
		//�Y�O�S��쪺�ܡA����o
		if (flag == string::npos)
		{
			//�Y�O�ݭn���p���I�ᤣ��0�A�h�n�S�O�B�z
			if (N != 0)
			{
				cout << setw(M - X.size() - N - 1) << setfill(C) << "";
				cout << X << ".";
				cout << left << setfill('0') << setw(N) << "" << endl;
			}
			else
			{
				cout << right << setfill(C) << setw(M) << X <<endl;
			}
		}
		//���p���I�N����o
		else
		{
			//�@�Ǳ���P�_
			integerPart = X.substr(0, flag);
			if (N == 0)
			{
				cout << setw(M - integerPart.size() - N) << setfill(C) << "";
				cout << setw(M - integerPart.size() - N - 1) << setfill(C) << right << integerPart << endl;
			}
			else if (X.substr(flag + 1).size() > N)
			{
				cout << setw(M - integerPart.size() - N - 1) << setfill(C) << "";
				cout << integerPart << ".";
				floatPart = X.substr(flag + 1, flag + N - 1);
				cout << floatPart << endl;
			}
			else
			{
				cout << setw(M - integerPart.size() - N - 1) << setfill(C) << "";
				cout << integerPart << ".";
				floatPart = X.substr(flag + 1);
				cout << setfill('0') << setw(N) << left << floatPart << endl;
			}
		}
    }
}