#include <iostream>
#include <vector>

using namespace std;

int** inputMatrix(int row, int col)
{
	// 先把row*col的二維陣列做出來
	int** matrix = new int*[row];
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> matrix[i][j];
		}
	}
	return matrix;
}

void outputMatrix(int ** A, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

int** multiplyMatrix(int ** A, int ** B, int row, int col, int limit)
{
	// 先做出二維陣列
	int** matrix = new int*[row];
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}

	// 初始化，矩陣中每個值歸零
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < limit; k++)
			{
				matrix[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return matrix;
}


int main()
{
	int rowA, colA, rowB, colB;
	cin >> rowA >> colA >> rowB >> colB;
	if ( rowB != colA)
	{
		cout << "Matrix multiplication failed." << endl;
		return 0;

	}
	
	int** matrixA = inputMatrix(rowA, colA);
	int** matrixB = inputMatrix(rowB, colB);
	int **ans = multiplyMatrix(matrixA, matrixB, rowA, colB, rowB);
	outputMatrix(ans, rowA, colB);
	delete[] matrixA, matrixB, ans;
	return 0;

}
