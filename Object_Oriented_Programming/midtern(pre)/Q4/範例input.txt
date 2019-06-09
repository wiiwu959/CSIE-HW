int main() {

	VecNf empty;
	float xy[] = { 3.0, 2.0 };
	float xyz[] = { 1, 2, 3 };
	float xyz2[] = { 6, 5, 4 };

	VecNf Vxy(xy, 2);
	VecNf Vxyz(xyz, 3);
	VecNf Vxyz2(xyz2, 3);

	VecNf t;
	t = Vxy;             //test operator=
	t = Vxyz;

	cout << "Vector xy " << endl;
	{for (int i = 0; i < 2; i++)
		cout << "dimension  " << i + 1 << " :  " << Vxy[i] << endl;
	}
	cout << "Vector xyz " << endl;
	{for (int i = 0; i < 3; i++)
		cout << "dimension  " << i + 1 << " :  " << Vxyz[i] << endl;
	}

	cout << "Vector add " << endl;
	VecNf add = Vxyz + Vxyz2;   //add test
	for (int i = 0; i < 3; i++)
		cout << "dimension  " << i + 1 << " :  " << add[i] << endl;

	float dot = Vxyz * Vxyz2;   //inner product test
	cout << "dot = " << dot << endl;

	float dot2 = Vxy * Vxyz;   //inner product test
	cout << "dot = " << dot2 << endl;

	system("pause");

	return 0;

}