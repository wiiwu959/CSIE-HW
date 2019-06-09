#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	double value, guess, preguess, root;
	cout.setf(ios::fixed);

	while (cin >> value) {
		preguess = value;
		guess = value / 2;
		guess = (guess + value / guess) / 2;
		root = fabs(preguess - guess);

		while ( fabs(preguess - guess) >=  0.01 )
		{
			preguess = guess;
			guess = (guess + value / guess) / 2;
			root = fabs(preguess - guess);
		}

		cout << setprecision(2) << guess << endl;
	}
	return 0;
}