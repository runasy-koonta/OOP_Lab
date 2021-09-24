#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
using Matrix = vector<vector<int>>;

void init_matrix(Matrix& mat, int row, int col) {
	if (row <= 0 || col <= 0) {
		cout << "행렬을 생성할 수 없습니다.";
		exit(0);
	}
	for (int i = 0; i < row; i++) {
		vector<int> m;
		for (int j = 0; j < col; j++) {
			m.push_back((rand() % 19) - 9);
		}
		mat.push_back(m);
	}
}
void print_matrix(const Matrix& mat) {
	for (vector<int> col: mat) {
		for (int item: col) {
			cout << setw(4) << item;
		}
		cout << endl;
	}
}

Matrix multiply_matrix(const Matrix& A, const Matrix& B) {
	Matrix ret;
	
	if (A.at(0).size() != B.size()) {
		cout << "두 행렬을 곱할 수 없습니다.";
		exit(0);
	}
	for (int i = 0; i < A.size(); i++) {
		vector<int> p;
		for (int j = 0; j < B.at(0).size(); j++) {
			int q = 0;
			for (int k = 0; k < A.at(i).size(); k++) {
				q += A.at(i).at(k) * B.at(k).at(j);
			}
			p.push_back(q);
		}
		ret.push_back(p);
	}
	return ret;
}

int main() {
	Matrix A, B;
	
	int col_a, col_b, row_a, row_b;
	
	cout << "A의 행, 열의 크기를 입력해주세요 : ";
	cin >> row_a >> col_a;
	cout << "B의 행, 열의 크기를 입력해주세요 : ";
	cin >> row_b >> col_b;
	
	init_matrix(A, row_a, col_a);
	init_matrix(B, row_b, col_b);
	
	cout << "A 행렬 :" << endl;
	print_matrix(A);
	cout << "B 행렬 :" << endl;
	print_matrix(B);
	
	Matrix ret = multiply_matrix(A, B);
	cout << "AB 곱행렬 :" << endl;
	print_matrix(ret);

	return 0;
}
