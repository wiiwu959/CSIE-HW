#include "FileController.h"
int main()
{
	FileController fc;
	fc.showFolderContents(false, "data\\source");

	cout << (fc.isFileExist("data\\source\\test0.txt") ? "true" : "false") << endl;
	cout << (fc.isFileExist("data\\source\\test1.txt") ? "true" : "false") << endl;
	cout << (fc.isFileExist("data\\source\\PIC") ? "true" : "false") << endl;
	
	cout << (fc.isFolderExist("data\\source\\test0.txt") ? "true" : "false") << endl;
	cout << (fc.isFolderExist("data\\source\\test1") ? "true" : "false") << endl;
	cout << (fc.isFolderExist("data\\source\\PIC") ? "true" : "false") << endl;
	
	cout << fc.getFileSize("data\\source\\NTUST.png") << "\tbyte(s)" << endl;
	cout << fc.getFileSize("data\\source\\test1.txt") << "\tbyte(s)" << endl;

	cout << (fc.copyFile("data\\source\\PIC\\PNG\\Stanford.PNG", "data\\copy1\\STF.PNG") ? "Copy successful" : "Copy failed") << endl;
	fc.showFolderContents(true, "data\\copy1");

	cout << (fc.copyFolder("data\\source\\test", "data\\copy1") ? "Copy successful" : "Copy failed") << endl;
	cout << (fc.copyFolder("data\\source\\School", "data\\copy1") ? "Copy successful" : "Copy failed") << endl;
	fc.showFolderContents(true, "data\\copy1");
	fc.showFolderContents(true, "data\\copy1\\NTUST");

	system("pause");
	return 0;
}