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

		//總之先找到小數點來當整數和小數的分段
		string::size_type flag = X.find(".");
		//若是沒找到的話，執行這
		if (flag == string::npos)
		{
			//若是需要的小數點後不為0，則要特別處理
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
		//有小數點就執行這
		else
		{
			//一些條件判斷
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