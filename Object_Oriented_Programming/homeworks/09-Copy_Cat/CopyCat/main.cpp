#include <iostream> 
#include <fstream>

using namespace std;

// 參考http://www2.lssh.tp.edu.tw/~hlf/class-1/lang-c/c++file.htm

int main(int argc, char* argv[])
{
	// 若是輸入少於或多於三個參數，則回傳錯誤訊息並結束
	if (argc != 3)
	{
		cout << "Wrong input!" << endl;
		return -1;
	}

	// 開啟檔案，檔案名稱是輸入的第二個參數，用binary的方式開啟
	ifstream  src(argv[1], ios::binary);
	// 若存在就開啟，不存在就新增一個
	ofstream  dst(argv[2], ios::binary);

	// 若是要被複製的檔案有錯誤，就回傳錯誤訊息並結束
	if (src.fail())
	{
		cout << "Source file failed." << endl;
		src.close();
		dst.close();
		remove(argv[2]);
		return -1;
	}

	// 讀進來再傳出去
	char input;
	src.get(input);
	while (!src.eof())
	{
		dst << input;
		src.get(input);
	}

	// flush完關閉檔案
	dst.flush();
	src.close();
	dst.close();
	cout << "Finish" << endl;
	
	return 0;
}