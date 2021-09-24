#include<iostream>
using namespace std;

int** buildTable(int n) {
	int** ret = new int*[n];
	for (int i = 0; i < n; i++) {
		ret[i] = new int[n];
		for (int j = 0; j < n; j++) {
			ret[i][j] = 0;
		}
	}
	return ret;
}
void make_identity_matrix(int** table, int n) {
	for (int i = 0; i < n; i++) {
		table[i][i] = 1;
	}
}
void printTable(int** table, int n) {
	cout << "Output:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << table[i][j] << '\t';
		}
		cout << endl;
	}
}

int main() {
	int n = 0;
	cout << "N을 입력하시오: ";
	cin >> n;
	if (n < 1) {
		cout << "\n행렬을 생성할 수 없습니다.\n" << endl;
		exit(EXIT_FAILURE);
	}

	int** table = buildTable(n);
	make_identity_matrix(table, n);
	printTable(table, n);

	for (int i = 0; i < n; i++)
		delete[] table[i];
	delete[] table;

	return 0;
}
