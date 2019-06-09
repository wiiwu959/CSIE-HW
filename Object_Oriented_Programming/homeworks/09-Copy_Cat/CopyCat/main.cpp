#include <iostream> 
#include <fstream>

using namespace std;

// �Ѧ�http://www2.lssh.tp.edu.tw/~hlf/class-1/lang-c/c++file.htm

int main(int argc, char* argv[])
{
	// �Y�O��J�֩�Φh��T�ӰѼơA�h�^�ǿ��~�T���õ���
	if (argc != 3)
	{
		cout << "Wrong input!" << endl;
		return -1;
	}

	// �}���ɮסA�ɮצW�٬O��J���ĤG�ӰѼơA��binary���覡�}��
	ifstream  src(argv[1], ios::binary);
	// �Y�s�b�N�}�ҡA���s�b�N�s�W�@��
	ofstream  dst(argv[2], ios::binary);

	// �Y�O�n�Q�ƻs���ɮצ����~�A�N�^�ǿ��~�T���õ���
	if (src.fail())
	{
		cout << "Source file failed." << endl;
		src.close();
		dst.close();
		remove(argv[2]);
		return -1;
	}

	// Ū�i�ӦA�ǥX�h
	char input;
	src.get(input);
	while (!src.eof())
	{
		dst << input;
		src.get(input);
	}

	// flush�������ɮ�
	dst.flush();
	src.close();
	dst.close();
	cout << "Finish" << endl;
	
	return 0;
}