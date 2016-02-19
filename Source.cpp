#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>


int rows = 0;
int cols = 0;

using namespace std;

class mat{

private:


public:
	vector<vector<int>> MatrixA;
	vector<vector<int>> MatrixB;
	void print_function(vector<vector<int>>);
	vector<vector<int>> sum_function(vector<vector<int>>, vector<vector<int>>);
	vector<vector<int>> sub_function(vector<vector<int>>, vector<vector<int>>);
	vector<vector<int>> multiplication_function(vector<vector<int>>, vector<vector<int>>);
	vector<vector<int>> strassen_function(vector<vector<int>>, vector<vector<int>>);





};

void mat::print_function(vector<vector<int>> answer)
{
	int rows = answer.size();
	int cols = answer[0].size();
	cout << "\n";
	for (int i = 0; i < rows; i++) {
		cout << "";
		for (int j = 0; j < cols; j++) {
			if (j == cols - 1)
				cout << answer[i][j];
			else
				cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

vector<vector<int>> mat::sum_function(vector<vector<int>> MatrixA, vector<vector<int>> MatrixB) {

	int n = MatrixA.size();
	vector<vector<int>> result;
	result.resize(n, vector<int>(n, 0));
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			result[i][j] = MatrixA[i][j] + MatrixB[i][j];
		}
	}
	return result;
}

vector<vector<int>> mat::sub_function(vector<vector<int>> MatrixA, vector<vector<int>> MatrixB) {

	int n = MatrixA.size();
	vector<vector<int>> result;
	result.resize(n, vector<int>(n, 0));
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			result[i][j] = MatrixA[i][j] - MatrixB[i][j];
		}
	}
	return result;
}
vector<vector<int>> mat::multiplication_function(vector<vector<int>> MatrixA, vector<vector<int>> MatrixB)
{
	int rows = MatrixA.size();
	int cols = MatrixA[0].size();
	int dimension = MatrixB[0].size();

	vector<vector<int>> answer;
	answer.resize(rows, vector<int>(dimension, 0));
	for (int i = 0; i < rows; i++)
	for (int j = 0; j < dimension; j++) {
		int sum = 0;
		for (int k = 0; k < cols; k++)
			sum = sum + (MatrixA[i][k] * MatrixB[k][j]);
		answer[i][j] = sum;
	}
	return answer;
}

vector<vector<int>> mat::strassen_function(vector<vector<int>> MatrixA, vector<vector<int>> MatrixB) {

	int n = MatrixA.size();

	vector<vector<int>> answer;
	answer.resize(n, vector<int>(n, 0));

	if (n == 1) {
		answer[0][0] = MatrixA[0][0] * MatrixB[0][0];
		return answer;
	}
	else {
		vector<vector<int>> a11, a12, a21, a22;
		vector<vector<int>> b11, b12, b21, b22;
		vector<vector<int>> c11, c12, c21, c22;
		vector<vector<int>> p1, p2, p3, p4, p5, p6, p7;

		a11.resize(n / 2, vector<int>(n / 2, 0));
		a12.resize(n / 2, vector<int>(n / 2, 0));
		a21.resize(n / 2, vector<int>(n / 2, 0));
		a22.resize(n / 2, vector<int>(n / 2, 0));

		b11.resize(n / 2, vector<int>(n / 2, 0));
		b12.resize(n / 2, vector<int>(n / 2, 0));
		b21.resize(n / 2, vector<int>(n / 2, 0));
		b22.resize(n / 2, vector<int>(n / 2, 0));

		c11.resize(n / 2, vector<int>(n / 2, 0));
		c12.resize(n / 2, vector<int>(n / 2, 0));
		c21.resize(n / 2, vector<int>(n / 2, 0));
		c22.resize(n / 2, vector<int>(n / 2, 0));

		p1.resize(n / 2, vector<int>(n / 2, 0));
		p2.resize(n / 2, vector<int>(n / 2, 0));
		p3.resize(n / 2, vector<int>(n / 2, 0));
		p4.resize(n / 2, vector<int>(n / 2, 0));
		p5.resize(n / 2, vector<int>(n / 2, 0));
		p6.resize(n / 2, vector<int>(n / 2, 0));
		p7.resize(n / 2, vector<int>(n / 2, 0));

		vector<vector<int>> aResult;
		vector<vector<int>> bResult;
		aResult.resize(n / 2, vector<int>(n / 2, 0));
		bResult.resize(n / 2, vector<int>(n / 2, 0));


		int i, j;

	
		for (i = 0; i < n / 2; i++) {
			for (j = 0; j < n / 2; j++) {
				a11[i][j] = MatrixA[i][j];
				a12[i][j] = MatrixA[i][j + n / 2];
				a21[i][j] = MatrixA[i + n / 2][j];
				a22[i][j] = MatrixA[i + n / 2][j + n / 2];

				b11[i][j] = MatrixB[i][j];
				b12[i][j] = MatrixB[i][j + n / 2];
				b21[i][j] = MatrixB[i + n / 2][j];
				b22[i][j] = MatrixB[i + n / 2][j + n / 2];
			}
		}

		aResult = sum_function(a11, a22); 
		bResult = sum_function(b11, b22); 
		p1 = strassen_function(aResult, bResult);

		aResult = sum_function(a21, a22); 
		p2 = strassen_function(aResult, b11); 

		bResult = sub_function(b12, b22); 
		p3 = strassen_function(a11, bResult); 

		bResult = sub_function(b21, b11); 
		p4 = strassen_function(a22, bResult);

		aResult = sum_function(a11, a12); 
		p5 = strassen_function(aResult, b22);

		aResult = sub_function(a21, a11); 
		bResult = sum_function(b11, b12); 
		p6 = strassen_function(aResult, bResult); 

		aResult = sub_function(a12, a22); 
		bResult = sum_function(b21, b22); 
		p7 = strassen_function(aResult, bResult); 


		c12 = sum_function(p3, p5); 
		c21 = sum_function(p2, p4);

		aResult = sum_function(p1, p4);
		bResult = sum_function(aResult, p7); 
		c11 = sub_function(bResult, p5); 

		aResult = sum_function(p1, p3);
		bResult = sum_function(aResult, p6); 
		c22 = sub_function(bResult, p2); 

		for (i = 0; i < n / 2; i++) {
			for (j = 0; j < n / 2; j++) {
				answer[i][j] = c11[i][j];
				answer[i][j + n / 2] = c12[i][j];
				answer[i + n / 2][j] = c21[i][j];
				answer[i + n / 2][j + n / 2] = c22[i][j];
			}
		}
	}
	return answer;
}

int main()
{
	mat m1;
	
	cout << "please do write the rows and cols in multiple of 2\n";
	cout << "Enter the number of rows:";
	cin >> rows;
	cout << "Enter the number of cols:";
	cin >> cols;
	m1.MatrixA.resize(rows, vector<int>(cols, 0));
	m1.MatrixB.resize(rows, vector<int>(cols, 0));

	int a;
	
	cout << "Please Enter the Matrix MatrixA:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << " MatrixA["<< i<<"]["<<j<<"]:";
			cin >> a;
			
			m1.MatrixA[i][j] = a;
		}
		cout << "\n";
	}
	int b;
	cout << "Please Enter the Matrix B:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << " MatrixB[" << i << "][" << j << "]:";
			cin >> b;
			
			m1.MatrixB[i][j] = b;
		}
		cout << "\n";
	}
	cout << "By multiplication method:\n";
	m1.print_function(m1.multiplication_function(m1.MatrixA, m1.MatrixB));
	cout << "By strassen method:\n";
	m1.print_function(m1.strassen_function(m1.MatrixA, m1.MatrixB));
	fflush(stdin);
	getchar();
}