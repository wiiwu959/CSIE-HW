#include <iostream>
#include "Point.h"

using namespace std;

int main(void) {
	Point A, B, C;

	A.Set(5, -20);
	cout << A.RetrieveHorizontal() << " " << A.RetrieveVertical() << endl;

	B.Set(3, -2);
	cout << B.RetrieveHorizontal() << " " << B.RetrieveVertical() << endl;

	B.Move(1, 2);
	cout << B.RetrieveHorizontal() << " " << B.RetrieveVertical() << endl;

	C = B;
	cout << "Copy point:" << endl;
	cout << C.RetrieveHorizontal() << " " << C.RetrieveVertical() << endl;
	C.Move(-4, 0);
	cout << C.RetrieveHorizontal() << " " << C.RetrieveVertical() << endl;
	C.Reflect();
	cout << C.RetrieveHorizontal() << " " << C.RetrieveVertical() << endl;

	for (int i = 0; i < 4; i++) {
		C.Rotate();
		cout << C.RetrieveHorizontal() << " " << C.RetrieveVertical() << endl;
	}
	system("pause");
	return 0;
}